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

    # Créer un tableau d'infini positif de taille total
    dp = [float("inf")] * (total + 1)
    dp[0] = 0

    # Pour chaque montant de 1 à total
    for amount in range(1, total + 1):
        # Pour chaque pièces dans la liste de pièces
        for coin in coins:
            # Combien de pièces pour chaque valeur jusqu'à amount[total]
            # coin <= amount la pièce ne dépasse pas le montant
            # dp[amount - coin] != float('inf') on sait résoudre
            # les amount précédents
            if coin <= amount and dp[amount - coin] != float("inf"):
                # Prend le nombre minimal de pièces nécessaires pour combler
                # amount - coin
                # (+ 1 pour la pièce rajoutée à l'itération actuelle)
                dp[amount] = min(dp[amount], dp[amount - coin] + 1)

    return dp[total] if dp[total] != float("inf") else -1
