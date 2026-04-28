#!/usr/bin/python3

"""Prime Game."""


def isWinner(x, nums):
    """Détermine le gagnant global après x parties.

    Observation : dans une partie sur {1..n}, chaque premier <= n est choisi
    exactement une fois (dans l'ordre croissant). Le nombre de coups est donc
    égal au nombre de premiers <= n. Si ce nombre est impair, Maria gagne
    (elle joue en premier) ; sinon Ben gagne.

    On précalcule le nombre de premiers jusqu'à max(nums) avec un crible
    d'Ératosthène, puis chaque partie se résout en O(1).
    """
    if not nums or x == 0:
        return None

    max_n = max(nums)

    # is_prime[i] = True si i est premier
    is_prime = [False, False] + [True] * (max_n - 1)
    for i in range(2, int(max_n ** 0.5) + 1):
        if is_prime[i]:
            # Supprime tous les multiples de i à partir de i²
            for multiple in range(i * i, max_n + 1, i):
                is_prime[multiple] = False

    # prime_count[i] = nombre de premiers <= i (somme cumulative)
    prime_count = [0] * (max_n + 1)
    for i in range(1, max_n + 1):
        prime_count[i] = prime_count[i - 1] + (1 if is_prime[i] else 0)

    # --- Comptage des victoires ---
    maria, ben = 0, 0

    for n in nums[:x]:
        # Nombre de coups dans cette partie = nombre de premiers <= n
        moves = prime_count[n]
        if moves % 2 == 1:  # impair → Maria gagne
            maria += 1
        else:               # pair → Ben gagne
            ben += 1

    if maria > ben:
        return "Maria"
    if ben > maria:
        return "Ben"
    return None
