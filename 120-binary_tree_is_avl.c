#include "binary_trees.h"
#include <stdlib.h>
#include <stdio.h>

/**
 * height - Measures the height of a binary tree
 * @tree: Pointer to the root node of the tree to measure the height
 * Return: The height of the tree
 */
static int height(const binary_tree_t *tree)
{
	int left_height, right_height;

	if (!tree)
		return (0);

	left_height = height(tree->left);
	right_height = height(tree->right);

	return ((left_height > right_height ? left_height : right_height) + 1);
}

/**
 * is_bst - Checks if a binary tree is a valid Binary Search Tree
 * @tree: Pointer to the root node of the tree to check
 * @min: Minimum value for the current subtree
 * @max: Maximum value for the current subtree
 * Return: 1 if tree is a valid BST, and 0 otherwise
 */
static int is_bst(const binary_tree_t *tree, int min, int max)
{
	if (!tree)
		return (1);

	if (tree->n < min || tree->n > max)
		return (0);

	return (is_bst(tree->left, min, tree->n - 1) &&
		is_bst(tree->right, tree->n + 1, max));
}

/**
 * check_avl - Checks if a binary tree is a valid AVL Tree
 * @tree: Pointer to the root node of the tree to check
 * Return: 1 if tree is a valid AVL Tree, and 0 otherwise
 */
static int check_avl(const binary_tree_t *tree)
{
	int balance_factor;

	if (!tree)
		return (1);

	if (!is_bst(tree, INT_MIN, INT_MAX))
		return (0);

	balance_factor = height(tree->left) - height(tree->right);

	if (balance_factor > 1 || balance_factor < -1)
		return (0);

	return (check_avl(tree->left) && check_avl(tree->right));
}

/**
 * binary_tree_is_avl - Checks if a binary tree is a valid AVL Tree
 * @tree: Pointer to the root node of the tree to check
 * Return: 1 if tree is a valid AVL Tree, and 0 otherwise
 */
int binary_tree_is_avl(const binary_tree_t *tree)
{
	if (!tree)
		return (0);

	return (check_avl(tree));
}
