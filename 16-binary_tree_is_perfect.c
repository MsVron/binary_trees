#include "binary_trees.h"

/**
 * binary_tree_is_perfect - Checks if a binary tree is perfect
 * @tree: Pointer to the root node of the tree
 *
 * Return: 1 if the tree is perfect, 0 otherwise
 */
int binary_tree_is_perfect(const binary_tree_t *tree)
{
	int height, leaves, perfect_num_leaves;

	if (tree)
	{
		height = binary_tree_height(tree);
		leaves = binary_tree_leaves(tree);

		perfect_num_leaves = (int) (1 << height);
		if (leaves == perfect_num_leaves)
			return (1);
	}
	return (0);
}

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
