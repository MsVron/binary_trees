#include "binary_trees.h"

/**
 * sorted_array_to_avl_helper - Helper function to build AVL tree
 * @array: pointer to the first element of the array to be converted
 * @start: start index of the array/subarray
 * @end: end index of the array/subarray
 * @parent: pointer to the parent node
 *
 * Return: pointer to the root node of the created AVL tree, or NULL on failure
 */
avl_t *sorted_array_to_avl_helper(int *array, size_t start, size_t end,
								  avl_t *parent)
{
	avl_t *new_node;
	size_t mid;

	if (start > end)
		return (NULL);

	mid = (start + end) / 2;
	new_node = binary_tree_node(parent, array[mid]);
	if (!new_node)
		return (NULL);

	if (mid != start)
		new_node->left = sorted_array_to_avl_helper(array, start, mid - 1,
												new_node);
	if (mid != end)
		new_node->right = sorted_array_to_avl_helper(array, mid + 1, end,
													new_node);

	return (new_node);
}

/**
 * sorted_array_to_avl - builds an AVL tree from a sorted array
 * @array: pointer to the first element of the array to be converted
 * @size: number of elements in the array
 *
 * Return: pointer to the root node of the created AVL tree, or NULL on failure
 */
avl_t *sorted_array_to_avl(int *array, size_t size)
{
	if (!array || size == 0)
		return (NULL);

	return (sorted_array_to_avl_helper(array, 0, size - 1, NULL));
}
