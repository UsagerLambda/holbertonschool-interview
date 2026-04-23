#!/usr/bin/python3
"""Module pour générer le triangle de Pascal."""


def pascal_triangle(n):
    """Retourne une liste de listes représentant le triangle de Pascal."""
    if n <= 0:
        return []
    matrix = [[1]]  # Le haut du triangle est toujours 1

    for i in range(1, n):
        temp = [1]  # Chaque ligne commence et finit toujours par 1

        # On itère sur les éléments intérieurs de la ligne précédente
        # (on s'arrête avant le dernier pour éviter un dépassement d'index)
        for j in range(len(matrix[i - 1]) - 1):
            # Chaque valeur intérieure est la somme des deux valeurs
            # adjacentes de la ligne précédente
            temp.append(matrix[i - 1][j] + matrix[i - 1][j + 1])

        temp.append(1)  # Toujours terminer la ligne par 1
        matrix.append(temp)
    return matrix
