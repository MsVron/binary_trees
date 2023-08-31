#include "binary_trees.h"

/**
 * binary_tree_balance_helper - Helper function to calculate balance factor
 * @tree: Pointer to the root node of the tree
 *
 * Return: Balance factor of the subtree rooted at 'tree'
 */
int binary_tree_balance_helper(const binary_tree_t *tree)
{
	int num_subnodes_left, num_subnodes_right, height;

	num_subnodes_right = 1;
	num_subnodes_left = 1;
	if (tree)
	{
		if (tree->left)
			num_subnodes_left += binary_tree_balance_helper(tree->left);

		if (tree->right)
			num_subnodes_right += binary_tree_balance_helper(tree->right);

		if (num_subnodes_right > num_subnodes_left)
			height = num_subnodes_right;
		else
			height = num_subnodes_left;

		return (height);
	}
	return (0);
}

/**
 * binary_tree_balance - Measures the balance factor of a binary tree
 * @tree: Pointer to the root node of the tree
 *
 * Return: Balance factor of the tree, or 0 if the tree is NULL
 */
int binary_tree_balance(const binary_tree_t *tree)
{
	int balance, left_height, right_height;

	right_height = 0;
	left_height = 0;
	if (tree)
	{
		if (tree->left)
			left_height = binary_tree_balance_helper(tree->left);

		if (tree->right)
			right_height = binary_tree_balance_helper(tree->right);

		balance = left_height - right_height;

		return (balance);
	}
	return (0);
}
