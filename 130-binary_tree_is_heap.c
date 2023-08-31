#include "binary_trees.h"

/**
 * is_complete - Checks if a binary tree is complete
 * @tree: pointer to the root node of the tree to check
 * @index: index of the node
 * @nodes: total number of nodes in the tree
 *
 * Return: 1 if complete, 0 otherwise
 */
int is_complete(const binary_tree_t *tree, size_t index, size_t nodes)
{
	if (!tree)
		return (1);
	if (index >= nodes)
		return (0);
	return (is_complete(tree->left, 2 * index + 1, nodes) &&
			is_complete(tree->right, 2 * index + 2, nodes));
}

/**
 * binary_tree_size - Measures the size of a binary tree
 * @tree: pointer to the root node of the tree to measure the size
 *
 * Return: size of the tree, 0 if tree is NULL
 */
size_t binary_tree_size(const binary_tree_t *tree)
{
	if (!tree)
		return (0);
	return (1 + binary_tree_size(tree->left) + binary_tree_size(tree->right));
}

/**
 * is_heap - Checks if a binary tree is a valid Max Binary Heap
 * @tree: pointer to the root node of the tree to check
 *
 * Return: 1 if tree is a valid Max Binary Heap, 0 otherwise
 */
int is_heap(const binary_tree_t *tree)
{
	if (!tree->left && !tree->right)
		return (1);
	if (!tree->right && tree->n >= tree->left->n)
		return (is_heap(tree->left));
	if (tree->n >= tree->left->n && tree->n >= tree->right->n)
		return (is_heap(tree->left) && is_heap(tree->right));
	return (0);
}

/**
 * binary_tree_is_heap - Checks if a binary tree is a valid Max Binary Heap
 * @tree: pointer to the root node of the tree to check
 *
 * Return: 1 if tree is a valid Max Binary Heap, 0 otherwise
 */
int binary_tree_is_heap(const binary_tree_t *tree)
{
	size_t nodes;

	if (!tree)
		return (0);

	nodes = binary_tree_size(tree);
	if (is_complete(tree, 0, nodes) && is_heap(tree))
		return (1);
	return (0);
}
