#include "sort.h"


/**
 * merge - Fusionne deux sous-tableaux adjacents en un seul tableau trié
 * @array: Pointeur vers le début du premier sous-tableau
 * @temp: Tableau temporaire pour stocker le résultat de la fusion
 * @left_size: Taille du sous-tableau de gauche
 * @right_size: Taille du sous-tableau de droite
 */
void merge(int *array, int *temp, size_t left_size, size_t right_size)
{
	size_t i = 0, j = 0, k = 0;
	size_t total = left_size + right_size;

	/* Affichage des sous-tableaux avant la fusion */
	printf("Merging...\n");
	printf("[left]: ");
	print_array(array, left_size);
	printf("[right]: ");
	print_array(array + left_size, right_size);

	/* Tant que i & j n'ont pas fini de parcourir left & right size */
	/* (les deux segments) */
	while (i < left_size && j < right_size)
	{
		/* Compare les éléments courants des deux sous-tableaux */
		/* et insère le plus petit dans temp */
		if (array[i] <= array[left_size + j])
			temp[k++] = array[i++];
		else
			temp[k++] = array[left_size + j++];
	}

	/* Copie les éléments restants du sous-tableau gauche */
	while (i < left_size)
		temp[k++] = array[i++];

	/* Copie les éléments restants du sous-tableau droit */
	while (j < right_size)
		temp[k++] = array[left_size + j++];

	/* Recopie le tableau fusionné et trié dans le tableau original */
	for (i = 0; i < total; i++)
		array[i] = temp[i];

	/* Affichage du résultat après la fusion */
	printf("[Done]: ");
	print_array(array, total);
}


/**
 * merge_rec - Fonction récursive qui divise et fusionne le tableau
 * @array: Tableau à trier
 * @temp: Tableau temporaire pour la fusion
 * @size: Taille du segment à trier
 */
void merge_rec(int *array, int *temp, size_t size)
{
	size_t mid;

	if (size < 2)
		return;

	mid = size / 2;

	merge_rec(array, temp, mid);
	merge_rec(array + mid, temp, size - mid);
	merge(array, temp, mid, size - mid);
}


/**
 * merge_sort - Trie un tableau d'entiers avec l'algorithme merge sort
 * @array: Tableau à trier
 * @size: Taille du tableau
 */
void merge_sort(int *array, size_t size)
{
	int *temp;

	if (!array || size < 2)
		return;

	temp = malloc(sizeof(int) * size);
	if (!temp)
		return;

	merge_rec(array, temp, size);
	free(temp);
}
