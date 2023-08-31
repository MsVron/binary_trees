#include "binary_trees.h"

/**
 * find_min - Finds the node with the smallest value in a BST.
 * @node: The root of the BST.
 *
 * Return: The node with the smallest value.
 */
static bst_t *find_min(bst_t *node)
{
	while (node->left)
		node = node->left;
	return (node);
}

/**
 * bst_remove - Removes a node from a Binary Search Tree.
 * @root: The root of the BST.
 * @value: The value to remove.
 *
 * Return: The new root of the BST.
 */
bst_t *bst_remove(bst_t *root, int value)
{
	if (!root)
		return (NULL);

	/* Step 1: Perform standard BST delete */
	if (value < root->n)
		root->left = bst_remove(root->left, value);
	else if (value > root->n)
		root->right = bst_remove(root->right, value);
	else
	{
		if (!root->left)
		{
			bst_t *temp = root->right;
			if (temp)
				temp->parent = root->parent;
			free(root);
			return (temp);
		}
		else if (!root->right)
		{
			bst_t *temp = root->left;
			if (temp)
				temp->parent = root->parent;
			free(root);
			return (temp);
		}

		/* Step 2: Node with two children, get the inorder successor */
		bst_t *temp = find_min(root->right);

		/* Copy the inorder successor's content to this node */
		root->n = temp->n;

		/* Delete the inorder successor */
		root->right = bst_remove(root->right, temp->n);
	}
	return (root);
}
