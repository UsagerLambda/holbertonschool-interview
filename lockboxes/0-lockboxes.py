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
    visited = []
    for _ in range(len(boxes)):
        visited.append([])
    visited[0] = True
    view = {0}  # Set pour éviter les doublons

    while view:  # Tant qu'il y a des éléments à traiter dans view
        current = view.pop()  # Prend le dernier élément de la liste
        for key in boxes[current]:  # For each key dans la boxe d'index current
            # Si key n'est pas inférieur à 0 et supérieur à la taille de boxes
            # et qui n'est pas déjà marqué comme True
            if 0 <= key < len(boxes) and not visited[key]:
                # Marque la boxe comme visité
                visited[key] = True
                # Ajoute le nouvel index dans la liste view
                view.add(key)

    # Return True si tout les éléments de la liste sont identique, sinon False
    return all(visited)
