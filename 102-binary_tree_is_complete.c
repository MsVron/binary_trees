#include "binary_trees.h"
#include <stdlib.h>

/**
 * enqueue - Helper function to enqueue a node into a dynamic array (queue).
 * @queue: Double pointer to the dynamic array (queue).
 * @size: Pointer to the size of the queue.
 * @node: The node to enqueue.
 * Return: 1 if successful, 0 otherwise.
 */
static int enqueue(binary_tree_t ***queue, size_t *size, binary_tree_t *node)
{
	/* Reallocate memory for the new size */
	binary_tree_t **new_queue = realloc(*queue, sizeof(binary_tree_t *) * (*size + 1));

	/* Check for memory allocation failure */
	if (!new_queue)
		return (0);

	/* Add the new node to the end of the queue */
	new_queue[*size] = node;

	/* Update the size and the queue pointer */
	*size += 1;
	*queue = new_queue;

	return (1);
}

/**
 * binary_tree_is_complete - Checks if a binary tree is complete.
 * @tree: Pointer to the root node of the tree to check.
 * Return: 1 if the tree is complete, 0 otherwise.
 */
int binary_tree_is_complete(const binary_tree_t *tree)
{
	binary_tree_t **queue;  /* Dynamic array to use as a queue */
	size_t size = 0, i = 0; /* Size of the queue and loop index */
	int null_seen = 0;      /* Flag to indicate if a NULL child has been seen */
	int left_enqueue_success, right_enqueue_success; /* Flags for enqueue success */

	/* Check for empty tree */
	if (!tree)
		return (0);

	/* Initialize the queue with the root node */
	queue = malloc(sizeof(binary_tree_t *));
	if (!queue)
		return (0);
	if (!enqueue(&queue, &size, (binary_tree_t *)tree))
		return (0);

	/* Level-order traversal */
	while (i < size)
	{
		binary_tree_t *node = queue[i];

		/* If a node is non-NULL */
		if (node)
		{
			/* If a NULL child has been seen before, the tree is not complete */
			if (null_seen)
			{
				free(queue);
				return (0);
			}

			/* Enqueue left and right children */
			left_enqueue_success = enqueue(&queue, &size, node->left);
			right_enqueue_success = enqueue(&queue, &size, node->right);

			/* Check for memory allocation failure */
			if (!left_enqueue_success || !right_enqueue_success)
			{
				free(queue);
				return (0);
			}
		}
		else /* If a node is NULL */
		{
			/* Set the flag to indicate that a NULL child has been seen */
			null_seen = 1;
		}

		/* Move to the next node in the queue */
		i++;
	}

	/* Free the queue and return success */
	free(queue);
	return (1);
}