#!/usr/bin/env python3
"""Rotate a 2D matrix in-place."""


def rotate_2d_matrix(matrix):
    """Rotate a 2D matrix in-place."""
    n = len(matrix)
    for i in range(n):
        for j in range(i + 1, n):
            matrix[i][j], matrix[j][i] = matrix[j][i], matrix[i][j]
    for row in matrix:
        row.reverse()
