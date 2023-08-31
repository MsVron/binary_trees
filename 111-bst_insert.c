#include "binary_trees.h"

/**
 * bst_insert - Inserts a value in a Binary Search Tree.
 * @tree: Double pointer to the root node of the BST to insert the value.
 * @value: Value to store in the node to be inserted.
 *
 * Return: Pointer to the created node, or NULL on failure.
 */
bst_t *bst_insert(bst_t **tree, int value)
{
	/* If the tree is empty, create the root node */
	if (*tree == NULL)
	{
		*tree = binary_tree_node(NULL, value);
		return (*tree);
	}

	/* If value is already present, ignore it */
	if ((*tree)->n == value)
		return (NULL);

	/* If value is less than the current node's value, go left */
	if (value < (*tree)->n)
	{
		if ((*tree)->left == NULL)
		{
			(*tree)->left = binary_tree_node(*tree, value);
			return ((*tree)->left);
		}
		return (bst_insert(&((*tree)->left), value));
	}

	/* If value is greater than the current node's value, go right */
	if ((*tree)->right == NULL)
	{
		(*tree)->right = binary_tree_node(*tree, value);
		return ((*tree)->right);
	}
	return (bst_insert(&((*tree)->right), value));
}
