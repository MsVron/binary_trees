#include "binary_trees.h"

/**
 * binary_tree_uncle - Finds the uncle of a node in a binary tree
 * @node: Pointer to the node to find the uncle of
 *
 * Return: Pointer to the uncle node, or NULL if no uncle or node is NULL
 */
binary_tree_t *binary_tree_uncle(binary_tree_t *node)
{
	binary_tree_t *parent, *grand_parent;

	if (node != NULL && node->parent != NULL && node->parent->parent != NULL)
	{
		parent = node->parent;
		grand_parent = node->parent->parent;

		if (grand_parent->left != parent && grand_parent->left != NULL)
			return (grand_parent->left);

		if (grand_parent->right != parent && grand_parent->right != NULL)
			return (grand_parent->right);
	}
	return (NULL);
}
