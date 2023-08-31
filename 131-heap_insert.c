#include "binary_trees.h"

/**
 * heapify - Corrects the heap
 * @node: Inserted node
 *
 * Return: Nothing
 */
void heapify(heap_t *node)
{
	int temp;

	while (node->parent && node->n > node->parent->n)
	{
		temp = node->parent->n;
		node->parent->n = node->n;
		node->n = temp;
		node = node->parent;
	}
}

/**
 * get_size - Gets the size of the binary tree
 * @tree: Root node
 *
 * Return: Size of the tree
 */
size_t get_size(const heap_t *tree)
{
	if (!tree)
		return (0);
	return (1 + get_size(tree->left) + get_size(tree->right));
}

/**
 * insert_node - Inserts the node to the binary tree
 * @tree: Double pointer to the root node
 * @node: Node to be inserted
 * @idx: Index of the node to be inserted
 * @size: Size of the heap
 *
 * Return: Pointer to the inserted node
 */
heap_t *insert_node(heap_t **tree, heap_t *node, size_t idx, size_t size)
{
	if (!*tree)
		return (*tree = node);

	if (idx + 1 > size / 2)
	{
		if (!(*tree)->left)
			return ((*tree)->left = node);
		else
			return ((*tree)->right = node);
	}

	if (idx % 2)
	{
		if (insert_node(&((*tree)->left), node, 2 * idx + 1, size))
			return (node);
	}
	else
	{
		if (insert_node(&((*tree)->right), node, 2 * idx + 2, size))
			return (node);
	}

	return (NULL);
}

/**
 * heap_insert - Inserts a value into a Max Binary Heap
 * @root: Double pointer to the root node of the Heap
 * @value: The value store in the node to be inserted
 *
 * Return: Pointer to the inserted node, or NULL on failure
 */
heap_t *heap_insert(heap_t **root, int value)
{
	heap_t *node;
	size_t size;

	node = binary_tree_node(NULL, value);
	if (!node)
		return (NULL);

	size = get_size(*root);

	node->parent = insert_node(root, node, 0, size);
	if (node->parent)
		heapify(node);

	return (node);
}
