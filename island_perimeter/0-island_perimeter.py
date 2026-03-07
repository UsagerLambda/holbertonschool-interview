#!/usr/bin/python3
"""Calcule le périmètre d'une île dans une grille binaire."""


def island_perimeter(grid):
    """Calculate le périmètre d'une île dans une grille binaire.

    Chaque cellule terre (1) commence avec 4 côtés exposés.
    Quand deux cellules terre sont adjacentes, leur collage
    supprime 2 côtés (1 par cellule). On ne vérifie que bas
    et droite car haut et gauche sont déjà traités par les
    itérations précédentes.
    """
    rows, cols = len(grid), len(grid[0])
    perimeter = 0

    for i in range(rows):
        for j in range(cols):
            if grid[i][j] == 1:
                perimeter += 4

                # Voisin du bas : 2 côtés disparaissent au collage
                if i + 1 < rows and grid[i + 1][j] == 1:
                    perimeter -= 2

                # Voisin de droite : même logique
                if j + 1 < cols and grid[i][j + 1] == 1:
                    perimeter -= 2

    return perimeter
