#include "binary_trees.h"

/**
 * binary_tree_nodes - Counts the nodes with at least
 * one child in a binary tree
 * @tree: Pointer to the root node of the tree
 *
 * Return: Number of nodes with at least one child, or 0 if the tree is NULL
 */
size_t binary_tree_nodes(const binary_tree_t *tree)
{
	int nodes = 0;

	if (tree)
	{
		if (tree->left)
			nodes += binary_tree_nodes(tree->left);

		if (tree->right)
			nodes += binary_tree_nodes(tree->right);

		if (tree->left != tree->right)
			return (++nodes);

		return (nodes);
	}
	return (0);
}
