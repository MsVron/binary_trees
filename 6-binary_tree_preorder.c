#include "binary_trees.h"

/**
 * binary_tree_preorder - Performs a preorder traversal on a binary tree
 * @tree: Pointer to the root node of the tree
 * @func: Pointer to a function to be called on each node's value
 *
 * Return: None
 */
void binary_tree_preorder(const binary_tree_t *tree, void (*func)(int))
{
	if (tree != NULL && func != NULL)
	{
		func(tree->n);

		if (tree->left)
			binary_tree_preorder(tree->left, func);

		if (tree->right)
			binary_tree_preorder(tree->right, func);
	}
}
