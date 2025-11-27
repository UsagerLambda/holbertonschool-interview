#!/usr/bin/python3
"""Rain."""


def recursive(walls, left, right):
    """
    Calculate récursivement l'eau piégée entre les murs.

    Args:
        walls: liste des hauteurs de murs
        left: index du mur actuel (point de départ)
        right: index de fin de la liste

    Returns:
        Quantité totale d'eau piégée
    """
    if left >= right - 1:
        return 0

    # Décalle next_wall vers la droite sur la liste
    next_wall = left + 1
    for i in range(left + 1, right + 1):
        # Si le mur i est plus haut que next_wall, on le prend
        if i < len(walls) and walls[i] >= walls[next_wall]:
            next_wall = i
            # Vérifie que le prochain n'est pas plus grand
            # Ou plutôt on confirme que c'est le cas
            if walls[i] >= walls[left]:
                break

    water = 0
    # La hauteur de l'eau est basé sur le plus petit mur
    height = min(walls[left], walls[next_wall])
    # Pour chaque position entre les deux murs
    for i in range(left + 1, next_wall):
        # Eau = hauteur du niveau d'eau - hauteur du mur à cette position
        water += max(0, height - walls[i])

    # Continuer la recursion: on traite le reste avec next_wall
    # comme nouveau point de départ
    water += recursive(walls, next_wall, right)

    return water


def rain(walls):
    """
    Calculate la quantité totale d'eau de pluie retenue entre les murs.

    Args:
        walls: liste d'entiers positifs représentant les hauteurs des murs

    Returns:
        Entier représentant la quantité totale d'eau retenue
    """
    if not walls or len(walls) < 3:
        return 0

    water = recursive(walls, 0, len(walls) - 1)

    return water
