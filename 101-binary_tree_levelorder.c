#include "binary_trees.h"
#include <stdlib.h>

/**
 * enqueue - Enqueues a node into a queue.
 * @queue: Double pointer to the queue.
 * @size: Pointer to the size of the queue.
 * @node: Node to enqueue.
 *
 * Return: 1 on success, 0 on failure.
 */
static int enqueue(binary_tree_t ***queue, size_t *size, binary_tree_t *node)
{
	binary_tree_t **new_queue;

	new_queue = realloc(*queue, sizeof(binary_tree_t *) * (*size + 1));
	if (new_queue == NULL)
		return (0);
	new_queue[*size] = node;
	*size += 1;
	*queue = new_queue;
	return (1);
}

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

	queue = malloc(sizeof(binary_tree_t *));
	if (queue == NULL)
		return;
	queue[0] = (binary_tree_t *)tree;
	size = 1;

	while (i < size)
	{
		binary_tree_t *node = queue[i];
		func(node->n);

		if (node->left && !enqueue(&queue, &size, node->left))
		{
			free(queue);
			return;
		}

		if (node->right && !enqueue(&queue, &size, node->right))
		{
			free(queue);
			return;
		}

		i++;
	}
	free(queue);
}
