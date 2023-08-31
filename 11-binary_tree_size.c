#include "binary_trees.h"

/**
 * binary_tree_size - Measures the size of a binary tree
 * @tree: Pointer to the root node of the tree
 *
 * Return: Size of the tree, or 0 if the tree is NULL
 */
size_t binary_tree_size(const binary_tree_t *tree)
{
	int size = 1;

	if (tree)
	{
		if (tree->left)
			size += binary_tree_size(tree->left);

		if (tree->right)
			size += binary_tree_size(tree->right);

		return (size);
	}
	return (0);
}
