#include "binary_trees.h"

/**
 * binary_tree_leaves - Counts the leaves in a binary tree
 * @tree: Pointer to the root node of the tree
 *
 * Return: Number of leaves in the tree, or 0 if the tree is NULL
 */
size_t binary_tree_leaves(const binary_tree_t *tree)
{
	int leaves = 0;

	if (tree)
	{
		if (tree->left)
			leaves += binary_tree_leaves(tree->left);

		if (tree->right)
			leaves += binary_tree_leaves(tree->right);

		if (tree->left == tree->right)
			return (++leaves);

		return (leaves);
	}
	return (0);
}
