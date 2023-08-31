/*
 *To check if a binary tree is a valid Binary Search Tree (BST),
 *we perform an in-order traversal and keep track of the last visited node.
 *During the traversal, we check if the current node's value is greater than
 *the last visited node's value. If it is, you continue;
 *otherwise, the tree is not a BST.
*/

#include "binary_trees.h"

/**
 * is_bst_helper - Helper function to check if a binary tree is a BST.
 * @tree: Pointer to the root node of the tree to check.
 * @prev: Pointer to the previous node in the in-order traversal.
 *
 * Return: 1 if the tree is a valid BST, 0 otherwise.
 */
static int is_bst_helper(const binary_tree_t *tree, const binary_tree_t **prev)
{
	if (tree == NULL)
		return (1);

	/* Check the left subtree */
	if (!is_bst_helper(tree->left, prev))
		return (0);

	/* Check the current node */
	if (*prev && (*prev)->n >= tree->n)
		return (0);

	/* Update the previous node */
	*prev = tree;

	/* Check the right subtree */
	return (is_bst_helper(tree->right, prev));
}

/**
 * binary_tree_is_bst - Checks if a binary tree is a valid Binary Search Tree.
 * @tree: Pointer to the root node of the tree to check.
 *
 * Return: 1 if the tree is a valid BST, 0 otherwise.
 */
int binary_tree_is_bst(const binary_tree_t *tree)
{
	const binary_tree_t *prev = NULL;

	if (tree == NULL)
		return (0);

	return (is_bst_helper(tree, &prev));
}
