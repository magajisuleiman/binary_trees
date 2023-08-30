#include "binary_trees.h"

/**
 * binary_tree_is_complete - Checks if a binary tree is complete
 * @tree: Pointer to the root node of the tree to check
 *
 * Return: 1 if the tree is complete, 0 otherwise or if tree is NULL
 */
int binary_tree_is_complete(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);

	return is_complete_recursive(tree, 0, binary_tree_size(tree));
}

/**
 * is_complete_recursive - Helper function to recursively check completeness
 * @tree: Pointer to the current subtree to check
 * @index: Index of the current node
 * @count: Total number of nodes in the entire tree
 *
 * Return: 1 if the subtree is complete, 0 otherwise
 */
int is_complete_recursive(const binary_tree_t *tree, size_t index, size_t count)
{
	if (tree == NULL)
		return (1);

	if (index >= count)
		return (0);

	return (is_complete_recursive(tree->left, 2 * index + 1, count) &&
	        is_complete_recursive(tree->right, 2 * index + 2, count));
}
