#include "binary_trees.h"
#include <stdlib.h>

/**
 * enqueue - Helper function to enqueue a node.
 * @queue: The queue.
 * @size: The size of the queue.
 * @node: The node to enqueue.
 * Return: 1 if successful, 0 otherwise.
 */
static int enqueue(binary_tree_t ***queue, size_t *size, binary_tree_t *node)
{
	binary_tree_t **new_queue = realloc(*queue, sizeof(binary_tree_t *) * (*size + 1));
	if (!new_queue)
		return (0);
	new_queue[*size] = node;
	*size += 1;
	*queue = new_queue;
	return (1);
}

/**
 * binary_tree_is_complete - Checks if a binary tree is complete.
 * @tree: Pointer to the root node of the tree to check.
 *
 * Return: 1 if the tree is complete, 0 otherwise.
 */
int binary_tree_is_complete(const binary_tree_t *tree)
{
	binary_tree_t **queue;
	size_t size = 0, i = 0;
	int null_seen = 0;

	if (!tree)
		return (0);

	queue = malloc(sizeof(binary_tree_t *));
	if (!queue)
		return (0);
	if (!enqueue(&queue, &size, (binary_tree_t *)tree))
		return (0);

	while (i < size)
	{
		binary_tree_t *node = queue[i];
		if (node)
		{
			if (null_seen)
			{
				free(queue);
				return (0);
			}
			if (!enqueue(&queue, &size, node->left) || !enqueue(&queue, &size, node->right))
			{
				free(queue);
				return (0);
			}
		}
		else
		{
			null_seen = 1;
		}
		i++;
	}
	free(queue);
	return (1);
}
