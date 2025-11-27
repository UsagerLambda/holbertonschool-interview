#include "search.h"

/**
 * linear_skip - Recherche une valeur dans une skip list triée
 * @list: Pointeur vers la tête de la skip list
 * @value: Valeur à rechercher
 *
 * Return: Pointeur vers le nœud contenant la valeur, ou NULL si non trouvé
 *
 * Algorithme en 2 phases:
 * 1. Saut rapide via la voie express pour localiser l'intervalle
 * 2. Recherche linéaire classique dans l'intervalle identifié
 */
skiplist_t *linear_skip(skiplist_t *list, int value)
{
	skiplist_t *left, *right;

	if (!list)
		return (NULL);

	left = right = list;

	while (right->express)
	{
		printf("Value checked at index [%lu] = [%d]\n",
		       right->express->index, right->express->n);

		if (right->express->n >= value)
			break;

		left = right->express;
		right = right->express;
	}

	if (right->express)
		right = right->express;
	else
	{
		while (right->next)
			right = right->next;
	}
	printf("Value found between indexes [%lu] and [%lu]\n",
	       left->index, right->index);

	while (left && left->index <= right->index)
	{
		printf("Value checked at index [%lu] = [%d]\n", left->index, left->n);

		if (left->n == value)
			return (left);

		left = left->next;
	}
	return (NULL);
}
