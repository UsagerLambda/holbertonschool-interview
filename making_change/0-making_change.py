#!/usr/bin/python3
"""Trouve le nombre minimal de pièces nécessaire pour total."""


def makeChange(coins, total):
    """
    Trouve le nombre minimal de pièces nécessaire pour total.

    Args:
        coins (list): Liste de pièces de certaine valeur
        total (int): Nombre à atteindre

    Returns:
        int: nombre de pièces minimal
    """
    if total <= 0:
        return 0

    target = total
    count = 0

    while target != 0:
        candidates = [v for v in coins if v < target]
        value = max(candidates) if candidates else None
        if value is not None:
            target -= value
            count += 1
        else:
            break

    if target != 1:
        return -1

    return count
