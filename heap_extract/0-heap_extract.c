#include "binary_trees.h"
#include <stddef.h>
#include <stdlib.h>

/**
 * count_nodes - Compte le nombre de node
 * @node: Pointeur vers le node racine
 *
 * Return: Le nombre total de nodes dans l'arbre
 */
int count_nodes(heap_t *node)
{
	if (node == NULL)
		return (0);
	return (1 + count_nodes(node->left) + count_nodes(node->right));
}

/**
 * get_last_node - Récupère le node le plus bas du heap
 * @root: Pointeur vers le node racine
 * @n: Nombre total de nodes dans l'arbre
 *
 * Return: Pointeur vers le dernier node du heap
 */
heap_t *get_last_node(heap_t *root, int n)
{
	heap_t *current = root;
	int mask;

	for (mask = 1; mask <= n; mask <<= 1)
		;
	mask >>= 2;

	while (mask > 0)
	{
		if (n & mask)
			current = current->right;
		else
			current = current->left;
		mask >>= 1;
	}
	return (current);
}

/**
 * swap - Échange les valeurs de deux nodes
 * @node: Pointeur vers le premier node
 * @largest: Pointeur vers le deuxième node
 */
void swap(heap_t *node, heap_t *largest)
{
	int temp = node->n;

	node->n = largest->n;
	largest->n = temp;
}

/**
 * heapify_down - fonction récursive pour trier l'arbre dans le bon ordre
 * @root: Premier node
 */
void heapify_down(heap_t *root)
{
	heap_t *largest = root;

	if (root->left != NULL && root->left->n > largest->n)
	{
		largest = root->left;
	}

	if (root->right != NULL && root->right->n > largest->n)
	{
		largest = root->right;
	}

	if (largest->n > root->n)
	{
		swap(root, largest);
		heapify_down(largest);
	}
}

/**
 * heap_extract - Extrait le node racine d'un Max Binary Heap
 * @root: Double pointeur vers le node racine du heap
 *
 * Return: La valeur extraite de la racine, ou 0 si le heap est vide
 */
int heap_extract(heap_t **root)
{
	int extracted, n;
	heap_t *last;

	if (root == NULL || *root == NULL)
		return (0);

	extracted = (*root)->n;
	n = count_nodes(*root);
	last = get_last_node(*root, n);

	if ((*root)->left == NULL && (*root)->right == NULL)
	{
		free((*root));
		*root = NULL;
		return (extracted);
	}

	(*root)->n = last->n;

	if (last->parent->left == last)
		last->parent->left = NULL;
	else
		last->parent->right = NULL;

	free(last);
	heapify_down(*root);

	return (extracted);
}
