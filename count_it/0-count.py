#!/usr/bin/python3
"""Compte récursivement des mots-clés."""
import requests


def count_words(subreddit, word_list, after=None, count=None):
    """Compte récursivement des mots-clés."""
    if count is None:
        count = {word.lower(): 0 for word in word_list}
    url = f"https://www.reddit.com/r/{subreddit}/hot.json"
    response = requests.get(
        url,
        allow_redirects=False,
        headers={"User-Agent": "python:test:v1.0"},
        params={"after": after} if after else {},
    )
    if response.status_code != 200:
        return
    data = response.json()

    for post in data["data"]["children"]:
        title_words = post["data"]["title"].lower().split()
        for word in word_list:
            word_lower = word.lower()
            for title_word in title_words:
                if title_word == word_lower:
                    count[word_lower] += 1

    if data["data"]["after"] is None:
        sorted_counts = sorted(count.items(), key=lambda x: (-x[1], x[0]))
        for word, value in sorted_counts:
            if value > 0:
                print(f"{word}: {value}")
        return
    else:
        count_words(subreddit, word_list, data["data"]["after"], count)
