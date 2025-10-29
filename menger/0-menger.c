#include <stdio.h>
#include <stdbool.h>
#include <math.h>

/**
 * is_filled - Vérifie si une case du tapis de Menger doit être remplie
 * @x: Coordonnée x
 * @y: Coordonnée y
 *
 * Return: true si la case est remplie, false sinon
 */
bool is_filled(int x, int y)
{
	while (x > 0 || y > 0)
	{
		/* Si on est dans la case centrale d'un 3x3 */
		if (x % 3 == 1 && y % 3 == 1)
			return (false);

		/* Zoom arrière : passer au niveau supérieur */
		x /= 3;
		y /= 3;
	}
	return (true);
}

/**
 * menger - Affiche un tapis de Menger d’un certain niveau
 * @level: Niveau du tapis
 *
 * Return: Rien
 */
void menger(int level)
{
	int size, i, y;

	if (level < 0)
		return;

	size = pow(3, level);

	for (i = 0; i < size; i++)
	{
		for (y = 0; y < size; y++)
		{
			if (is_filled(y, i))
				printf("#");
			else
				printf(" ");
		}
		printf("\n");
	}
}
