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
    # Je crée une liste `checker` contenant autant de listes vides
    # qu'il y a d'éléments dans la liste `boxes`.
    # Chaque sous-liste sera remplie par `True` lorsqu'elle sera ouverte,
    # sauf pour l'index 0 qui est considéré comme ouvert par défaut.
    checker = []
    for i in range(len(boxes)):
        if i != 0:
            checker.append(False)
        else:
            checker.append(True)

    checker = recursion_magic(checker, boxes)

    # Vérifie si chaque item de la liste est égal à True Sinon renvoie False
    for bool in checker:
        if bool is not True:
            return False
    return True


def recursion_magic(checker, boxes, index=0):
    """recursion_magic

    Args:
        checker (list): a list whose first item is True,
            followed by False values — one for each remaining sublist in boxes
        boxes (list of lists): each index represents a box,
            and each sublist contains keys to other boxes.
        index (int, optional): Current index from which to explore.
            Defaults to 0.

    Returns:
        list: The modified list "checker" filled with the lists checked
    """
    for key in boxes[index]:  # Pour chaque clé dans la boîte à l'index actuel
        if checker[key] is not True:  # Si la boîte n’a pas encore été ouverte
            checker[key] = True  # Marque la boîte comme ouverte
            # Récursion à partir de la liste à l'index key
            recursion_magic(checker, boxes, index=key)

    return checker
