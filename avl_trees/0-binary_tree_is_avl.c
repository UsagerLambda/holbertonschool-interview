#include "binary_trees.h"

/**
 * check_balance - Recursively checks if a tree is a valid AVL.
 *
 * Returns -1 for NULL node, -2 on error, or the subtree height.
 *
 * @tree: current node
 * @min: ancestor node whose value is the lower bound
 * @max: ancestor node whose value is the upper bound
 * Return: height of subtree, -1 if empty, -2 if invalid
 */
int check_balance(const binary_tree_t *tree,
	const binary_tree_t *min, const binary_tree_t *max)
{
	int left, right;

	if (!tree)
		return (-1);
	if (min && tree->n <= min->n)
		return (-2);
	if (max && tree->n >= max->n)
		return (-2);
	left = check_balance(tree->left, min, tree);
	if (left == -2)
		return (-2);
	right = check_balance(tree->right, tree, max);
	if (right == -2)
		return (-2);
	if (abs(left - right) > 1)
		return (-2);
	return (1 + (left > right ? left : right));
}

/**
 * binary_tree_is_avl - Vérifie si un arbre binaire est un AVL.
 *
 * Un AVL est un arbre BST dont chaque sous-arbre est équilibré
 * (différence de hauteur entre enfant gauche et droit ≤ 1).
 *
 * @tree: pointeur vers la racine de l'arbre
 * Return: 1 si l'arbre est un AVL valide, 0 sinon
 */
int binary_tree_is_avl(const binary_tree_t *tree)
{
	if (!tree)
		return (0);

	if (check_balance(tree, NULL, NULL) == -2)
		return (0);

	return (1);
}
