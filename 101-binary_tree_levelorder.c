#include "binary_trees.h"
#include <stdlib.h>

/**
 * binary_tree_levelorder - Goes through a binary tree using level-order
 *                          traversal.
 * @tree: Pointer to the root node of the tree to traverse.
 * @func: Pointer to a function to call for each node.
 *
 * Return: Nothing.
 */
void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
	binary_tree_t **queue;
	size_t size = 0, i = 0;

	if (tree == NULL || func == NULL)
		return;

	/* Initialize the queue and enqueue the root */
	queue = malloc(sizeof(binary_tree_t *));
	if (queue == NULL)
		return;
	queue[0] = (binary_tree_t *)tree;
	size = 1;

	while (i < size)
	{
		/* Dequeue the front node and process it */
		binary_tree_t *node = queue[i];
		func(node->n);

		/* Enqueue the left child if it exists */
		if (node->left != NULL)
		{
			queue = realloc(queue, sizeof(binary_tree_t *) * (size + 1));
			if (queue == NULL)
				return;
			queue[size] = node->left;
			size++;
		}

		/* Enqueue the right child if it exists */
		if (node->right != NULL)
		{
			queue = realloc(queue, sizeof(binary_tree_t *) * (size + 1));
			if (queue == NULL)
				return;
			queue[size] = node->right;
			size++;
		}

		i++;
	}

	/* Free the queue */
	free(queue);
}
