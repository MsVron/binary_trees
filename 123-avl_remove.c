#include "binary_trees.h"

/**
 * find_min_value_node - find the node with the minimum value greater than root.
 * @root: root of the tree
 *
 * Return: node with the minimum value greater than root
 */
avl_t *find_min_value_node(avl_t *root)
{
	avl_t *current = root;

	while (current->left)
		current = current->left;
	return (current);
}

/**
 * avl_remove - removes a node from an AVL tree
 * @root: pointer to the root node of the tree for removing a node
 * @value: value to remove in the tree
 *
 * Return: pointer to the new root node of the tree after removing
 */
avl_t *avl_remove(avl_t *root, int value)
{
	int balance;
	avl_t *temp;

	if (!root)
		return (root);

	/* Step 1: Perform standard BST delete */
	if (value < root->n)
		root->left = avl_remove(root->left, value);
	else if (value > root->n)
		root->right = avl_remove(root->right, value);
	else
	{
		if (!root->left || !root->right)
		{
			temp = root->left ? root->left : root->right;
			if (!temp)
			{
				temp = root;
				root = NULL;
			}
			else
				*root = *temp;
			free(temp);
		}
		else
		{
			temp = find_min_value_node(root->right);
			root->n = temp->n;
			root->right = avl_remove(root->right, temp->n);
		}
	}

	if (!root)
		return (root);

	/* Step 2: Update the balance factor of the current node */
	balance = binary_tree_balance(root);

	/* Step 3: Rebalance the tree */
	if (balance > 1 && binary_tree_balance(root->left) >= 0)
		return (binary_tree_rotate_right(root));
	if (balance > 1 && binary_tree_balance(root->left) < 0)
	{
		root->left = binary_tree_rotate_left(root->left);
		return (binary_tree_rotate_right(root));
	}
	if (balance < -1 && binary_tree_balance(root->right) <= 0)
		return (binary_tree_rotate_left(root));
	if (balance < -1 && binary_tree_balance(root->right) > 0)
	{
		root->right = binary_tree_rotate_right(root->right);
		return (binary_tree_rotate_left(root));
	}

	return (root);
}
