#!/usr/bin/python3

"""Prime Game."""


def isWinner(x, nums):
    """Détermine le gagnant global après x parties."""

    def is_prime(n):
        """Vérifie si n est un nombre premier."""
        if n < 2:
            return False
        for i in range(2, int(n ** 0.5) + 1):
            if n % i == 0:
                return False
        return True

    def play(n):
        """
        Simulate une partie sur l'ensemble {1, ..., n} et retourne le gagnant.

        À chaque tour, le joueur courant choisit le plus petit nombre premier
        disponible et supprime tous ses multiples. Le joueur qui ne trouve
        plus de premier perd.
        """
        numbers = list(range(1, n + 1))  # ensemble de nombres disponibles
        turn = 0  # compteur de tours joués

        while True:
            # Cherche le premier nombre premier encore disponible
            prime = next((p for p in numbers if is_prime(p)), None)
            if prime is None:
                # Plus aucun premier disponible : le joueur courant perd
                break
            # Supprime le premier choisi et tous ses multiples
            numbers = [x for x in numbers if x % prime != 0]
            turn += 1

        # Maria joue les tours impairs (1, 3, 5...), Ben les pairs
        return "Maria" if turn % 2 == 1 else "Ben"

    maria, ben = 0, 0  # compteurs de victoires

    for n in nums[:x]:  # on ne joue que les x premières valeurs
        winner = play(n)
        if winner == "Maria":
            maria += 1
        else:
            ben += 1

    # Retourne le joueur avec le plus de victoires, ou None si égalité
    if maria > ben:
        return "Maria"
    if ben > maria:
        return "Ben"
    return None
