#include "binary_trees.h"

/**
 * binary_tree_is_full - Checks if a binary tree is full
 * @tree: Pointer to the root node of the tree
 *
 * Return: 1 if the tree is full, 0 otherwise
 */
int binary_tree_is_full(const binary_tree_t *tree)
{
	int is_full = 1;

	if (tree)
	{
		if ((tree->left == NULL && tree->right != NULL) ||
				(tree->left != NULL && tree->right == NULL))
			return (0);

		if (tree->left)
			is_full = binary_tree_is_full(tree->left);

		if (is_full == 0)
			return (0);

		if (tree->right)
			is_full = binary_tree_is_full(tree->right);

		return (is_full);
	}
	return (0);
}
