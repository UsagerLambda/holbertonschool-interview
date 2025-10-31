#!/usr/bin/python3

import sys

args = sys.argv

args = ["o", "4"]

# Validation des arguments -------------------------------------------------- #
if len(args) != 2:
    print("Usage: nqueens N")
    exit(1)

try:
    N = int(args[1])
except ValueError:
    print("N must be a number")
    exit(1)

if N < 4:
    print("N must be at least 4")
    exit(1)

# Vérif position ------------------------------------------------------------ #

def is_safe(board, row, col):
    """Vérifie si on peut placer une reine à board[row][col]"""
    # Vérifie si il y a une reine sur la même colonne
    for i in range(row):
        if board[i] == col:
            return False

    # Vérifie si il y a une reine sur la même diagonale
    for i in range(row):
        if board[i] == col - (row - i):
            return False

    # Vérifie si il y a une reine sur la diagonale droite supérieure
    for i in range(row):
        if board[i] == col + (row - i):
            return False

    return True

# main function ------------------------------------------------------------- #

def solve(board, row):
    """Résout le problème N reines avec backtracking"""
    if row == N:  # Si row == N ça veux dire que l'on à placé toutes les reines
        # Créer une liste qui stocke la ligne et la colonne pour la position
        # de chaque reines
        solution = [[i, board[i]] for i in range(N)]
        # print la liste
        print(solution)
        return

    for col in range(N):  # Pour chaque colonnes de l'échiquier
        if is_safe(board, row, col):  # Retourne True ou False
            board[row] = col  # Si vrai pose la reine
            solve(board, row + 1)  # appel recursif de la fonction en avancant
            # dans les lignes
            board[row] = -1


# Initialiser le plateau (board[i] = colonne de la reine à la ligne i)
board = [-1] * N

# Appel de la fonction avec le tableau 1D (car une reine par ligne) et l'index
# de la ligne de début
solve(board, 0)
