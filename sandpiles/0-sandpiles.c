#include <stdlib.h>
#include <stdio.h>

#include "sandpiles.h"

/**
 * print_grid - Affiche une grille 3x3
 * @grid: grille à afficher
 */
static void print_grid(int grid[3][3])
{
	int i, j;

	printf("=\n");
	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			if (j)
				printf(" ");
			printf("%d", grid[i][j]);
		}
		printf("\n");
	}
}

/**
 * is_unstable - Vérifie si une grille est instable
 * @grid: grille à vérifier
 * Return: 1 si instable, 0 sinon
 */
static int is_unstable(int grid[3][3])
{
	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++)
			if (grid[i][j] > 3)
				return (1);
	return (0);
}

/**
 * sandpiles_sum - Additionne et stabilise deux grilles 3x3
 * @grid1: première grille (résultat)
 * @grid2: seconde grille (tampon)
 */
void sandpiles_sum(int grid1[3][3], int grid2[3][3])
{
	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++)
			grid1[i][j] += grid2[i][j];

	while (is_unstable(grid1))
	{
		print_grid(grid1);

		for (int x = 0; x < 3; x++) /* Reset grid 2 */
		{
			for (int y = 0; y < 3; y++)
				grid2[x][y] = 0;
		}

		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				if (grid1[i][j] > 3)
				{
					grid1[i][j] -= 4;

					if (j + 1 < 3)  /* colonne à droite de l'index */
						grid2[i][j + 1] += 1;

					if (j - 1 >= 0)  /* colonne à gauche de l'index */
						grid2[i][j - 1] += 1;

					if (i + 1 < 3)  /* colonne en dessous de l'index */
						grid2[i + 1][j] += 1;

					if (i - 1 >= 0)  /* colonne au dessus de l'index */
						grid2[i - 1][j] += 1;
				}
			}
		}
		for (int o = 0; o < 3; o++)
			for (int k = 0; k < 3; k++)
				grid1[o][k] += grid2[o][k];
	}
}


