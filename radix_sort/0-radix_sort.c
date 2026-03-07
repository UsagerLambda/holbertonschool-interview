#include "sort.h"

/**
 * max_digit - Trouve le nombre de chiffres max dans la liste d'entiers
 *
 * @array: La liste d'entiers
 * @size: Nombre d'éléments dans @array
 *
 * Return: Le nombre de chiffres maximum trouvé
 */
int max_digit(int *array, size_t size)
{
	int max = 0;

	for (size_t i = 0; i < size; i++)
	{
		int n = array[i];  /* Save le nombre actuel */
		int digits = 0;  /* Variable pour compter les chiffres du nombre */

		if (n == 0)
			digits = 1;

		while (n != 0)  /* Compte les chiffres tant que n n'est pas égal à 0*/
		{
			n /= 10;
			digits++;
		}
		/* Si les chiffres comptés sont supérieur à notre max actuel */
		if (digits > max)
			max = digits;
	}

	return (max);
}

/**
 * sort - Trie le tableau par le digit à la position d
 *
 * @array: La liste d'entiers
 * @size: Nombre d'éléments dans @array
 * @d: position du chiffre par lequel trier la liste
 *
 * Return: La liste trié par le chiffre en position d
 */
void sort(int *array, size_t size, int d)
{
	/* créer un tableau de size éléments de taille d'entiers */
	int *digits = malloc(size * sizeof(int));

	for (size_t i = 0; i < size; i++)
	{
		int n = array[i];  /* Récupère le nombre de la liste à la position i */

		for (int j = 0; j < d; j++)
			n /= 10;
		n = n % 10;
		digits[i] = n;
	}

	int count[10] = {0};

	for (size_t k = 0; k <= size - 1; k++)
		count[digits[k]]++;

	for (size_t l = 1; l <= 9; l++)
		count[l] += count[l - 1];


	int group, position;
	int *output = malloc(size * sizeof(int));

	for (size_t f = size; f > 0; f--)
	{
	group = digits[f - 1];
	position = count[group] - 1;
	output[position] = array[f - 1];
	count[group]--;
	}
	for (size_t z = 0; z <= size - 1; z++)
		array[z] = output[z];

	free(digits);
	free(output);
}

/**
 * radix_sort - Fonction d'entrée pour un algo de trie radix
 *
 * @array: La liste d'entiers
 * @size: Nombre d'éléments dans @array
 *
 */
void radix_sort(int *array, size_t size)
{
	int max = max_digit(array, size);

	for (int d = 0; d < max; d++)
	{
		sort(array, size, d);
		print_array(array, size);
	}
}
