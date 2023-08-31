#include "binary_trees.h"
#include <stdlib.h>

/**
 * binary_tree_balance - Measures the balance factor of a binary tree
 * @tree: Pointer to the root node of the tree to measure the balance factor
 * Return: Balance factor
 */
int binary_tree_balance(const binary_tree_t *tree);

/**
 * binary_tree_rotate_left - Rotates a binary tree to the left
 * @tree: Pointer to the root node of the tree to rotate
 * Return: Pointer to the new root node
 */
binary_tree_t *binary_tree_rotate_left(binary_tree_t *tree);

/**
 * binary_tree_rotate_right - Rotates a binary tree to the right
 * @tree: Pointer to the root node of the tree to rotate
 * Return: Pointer to the new root node
 */
binary_tree_t *binary_tree_rotate_right(binary_tree_t *tree);

/**
 * avl_insert - Inserts a value into an AVL tree
 * @tree: Double pointer to the root node of the AVL tree
 * @value: Value to insert
 * Return: Pointer to the created node, or NULL on failure
 */
avl_t *avl_insert(avl_t **tree, int value)
{
	int balance;
	avl_t *new_node;

	if (!tree)
		return (NULL);

	/* Insert as in BST */
	if (!*tree)
	{
		*tree = binary_tree_node(NULL, value);
		return (*tree);
	}

	if (value < (*tree)->n)
	{
		new_node = avl_insert(&((*tree)->left), value);
		if (!new_node)
			return (NULL);
		new_node->parent = *tree;
	}
	else if (value > (*tree)->n)
	{
		new_node = avl_insert(&((*tree)->right), value);
		if (!new_node)
			return (NULL);
		new_node->parent = *tree;
	}
	else
	{
		return (NULL);
	}

	/* Update balance factor and perform rotations */
	balance = binary_tree_balance(*tree);

	if (balance > 1 && value < (*tree)->left->n)
		return (binary_tree_rotate_right(*tree));
	if (balance < -1 && value > (*tree)->right->n)
		return (binary_tree_rotate_left(*tree));
	if (balance > 1 && value > (*tree)->left->n)
	{
		(*tree)->left = binary_tree_rotate_left((*tree)->left);
		return (binary_tree_rotate_right(*tree));
	}
	if (balance < -1 && value < (*tree)->right->n)
	{
		(*tree)->right = binary_tree_rotate_right((*tree)->right);
		return (binary_tree_rotate_left(*tree));
	}

	return (new_node);
}
