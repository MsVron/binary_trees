#include "binary_trees.h"
#include <stdlib.h>
#include <stdio.h>

/**
 * height - Measures the height of a binary tree
 * @tree: Pointer to the root node of the tree to measure the height
 * Return: The height of the tree
 */
int height(const binary_tree_t *tree)
{
    int left_height, right_height;

    if (!tree)
        return (0);

    left_height = height(tree->left);
    right_height = height(tree->right);

    if (left_height > right_height)
        return (left_height + 1);
    return (right_height + 1);
}

/**
 * binary_tree_is_avl - Checks if a binary tree is a valid AVL Tree
 * @tree: Pointer to the root node of the tree to check
 * Return: 1 if tree is a valid AVL Tree, and 0 otherwise
 */
int binary_tree_is_avl(const binary_tree_t *tree)
{
    int balance_factor;

    if (!tree)
        return (0);

    /* Check if it's a BST */
    if (tree->left && tree->left->n >= tree->n)
        return (0);
    if (tree->right && tree->right->n <= tree->n)
        return (0);

    /* Check balance factor */
    balance_factor = height(tree->left) - height(tree->right);
    if (balance_factor > 1 || balance_factor < -1)
        return (0);

    /* Check left and right subtrees */
    if (tree->left && !binary_tree_is_avl(tree->left))
        return (0);
    if (tree->right && !binary_tree_is_avl(tree->right))
        return (0);

    return (1);
}
