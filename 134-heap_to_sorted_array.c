#include "binary_trees.h"
#include <stdlib.h>

/**
 * heap_to_sorted_array - Converts a Max Binary Heap to a sorted array of ints.
 * @heap: Pointer to the root node of the heap to convert.
 * @size: Address to store the size of the array.
 *
 * Return: Pointer to the sorted array, or NULL on failure.
 */
int *heap_to_sorted_array(heap_t *heap, size_t *size)
{
	int *sorted_array;
	size_t i;
	int value;

	if (!heap || !size)
		return (NULL);

	/* Calculate the size of the heap */
	*size = binary_tree_size(heap);

	/* Allocate memory for the sorted array */
	sorted_array = malloc(sizeof(int) * (*size));
	if (!sorted_array)
		return (NULL);

	/* Extract elements from the heap and insert them into the array */
	for (i = 0; i < *size; i++)
	{
		value = heap_extract(&heap);
		if (!value)
		{
			free(sorted_array);
			return (NULL);
		}
		sorted_array[i] = value;
	}

	return (sorted_array);
}

/**
 * binary_tree_size - Measures the size of a binary tree.
 * @tree: Pointer to the root node of the tree to measure the size.
 *
 * Return: Size of the tree, or 0 if tree is NULL.
 */
size_t binary_tree_size(const binary_tree_t *tree)
{
	if (!tree)
		return (0);
	return (1 + binary_tree_size(tree->left) + binary_tree_size(tree->right));
}
