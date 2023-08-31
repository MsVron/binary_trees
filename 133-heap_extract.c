#include "binary_trees.h"

/**
 * heapify_down - Shifts down the elements to maintain max heap property
 * @root: Double pointer to the root node of the heap
 */
void heapify_down(heap_t **root)
{
	heap_t *node = *root, *largest;
	int temp;

	while (1)
	{
		largest = node;
		if (node->left && node->left->n > largest->n)
			largest = node->left;
		if (node->right && node->right->n > largest->n)
			largest = node->right;
		if (largest == node)
			return;
		temp = node->n;
		node->n = largest->n;
		largest->n = temp;
		node = largest;
	}
}

/**
 * get_last_node - Gets the last node in level-order traversal
 * @root: Pointer to the root of the heap
 *
 * Return: Pointer to the last node
 */
heap_t *get_last_node(heap_t *root)
{
	heap_t *queue[1024];
	int front = 0, back = 0;

	queue[back++] = root;
	while (front < back)
	{
		root = queue[front++];
		if (root->left)
			queue[back++] = root->left;
		if (root->right)
			queue[back++] = root->right;
	}
	return (root);
}

/**
 * heap_extract - Extracts the root node of a Max Binary Heap
 * @root: Double pointer to the root node of the heap
 *
 * Return: Value stored in the root node, or 0 upon failure
 */
int heap_extract(heap_t **root)
{
	int data;
	heap_t *last_node, *old_root;

	if (!root || !*root)
		return (0);

	old_root = *root;
	data = old_root->n;

	last_node = get_last_node(*root);
	if (last_node != *root)
	{
		if (last_node->parent->left == last_node)
			last_node->parent->left = NULL;
		else
			last_node->parent->right = NULL;
		last_node->left = old_root->left;
		last_node->right = old_root->right;
		if (last_node->left)
			last_node->left->parent = last_node;
		if (last_node->right)
			last_node->right->parent = last_node;
	}
	*root = last_node;
	free(old_root);
	if (*root)
		heapify_down(root);

	return (data);
}
