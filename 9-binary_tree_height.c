#include "binary_trees.h"

/**
 * binary_tree_height - Measures the height of a binary tree
 * @tree: Pointer to the root node of the tree
 *
 * Return: Height of the tree, or 0 if the tree is NULL
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
	int num_subnodes_left, num_subnodes_right, height;

	num_subnodes_right = 1;
	num_subnodes_left = 1;

	if (tree)
	{
		if (tree->left)
			num_subnodes_left += binary_tree_height(tree->left);

		if (tree->right)
			num_subnodes_right += binary_tree_height(tree->right);

		if (num_subnodes_right > num_subnodes_left)
			height = num_subnodes_right;
		else
			height = num_subnodes_left;

		if (tree->left == tree->right)/* Both left and right are NULL */
			height = 0;

		return (height);
	}
	return (0);
}
