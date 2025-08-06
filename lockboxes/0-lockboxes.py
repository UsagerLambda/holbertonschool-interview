#!/usr/bin/python3
"""
Function that determine if all boxes can be opened from box 0
"""


def canUnlockAll(boxes):
    """
    Determines if all boxes can be opened starting from box 0.

    Args:
        boxes (list of lists): Each index represents a box,
        and each sublist contains keys (integers) to other boxes.

    Returns:
        bool: True if all boxes can be opened, False otherwise.
    """
    visited = set()  # Créer un set qui stockera les index visité
    recursion_magic(boxes, visited, index=0)
    # Si la taille de visited est égal à celle de boxes,
    # alors toutes les boxe ont été visité donc la condition est vrai
    # donc true est renvoyé, sinon False
    return len(visited) == len(boxes)


def recursion_magic(boxes, visited, index):
    """recursion_magic

    Args:
        boxes (list of lists): liste des boîtes avec leurs clés.
        visited (set): ensemble des boîtes déjà ouvertes.
        index (int): index de la boîte actuelle à explorer.
    """
    # Si l'index a déjà été visité
    if index in visited:
        return

    # Ajoute l'index actuel au set
    visited.add(index)
    for key in boxes[index]:
        if 0 <= key < len(boxes):
            recursion_magic(boxes, visited, key)
