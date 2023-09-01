#include "binary_trees.h"

/**
 * binary_tree_is_avl - Checks if a binary tree is a valid AVL Tree
 * @tree: Pointer to the root node of the tree to check
 *
 * Return: 1 if tree is a valid AVL Tree, 0 otherwise or if tree is NULL
 */
int binary_tree_is_avl(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);

	int is_bst = binary_tree_is_bst(tree, NULL, NULL);
	int is_avl = binary_tree_is_avl_recursive(tree);

	return (is_bst && is_avl);
}

/**
 * binary_tree_is_bst - Checks if a binary tree is a valid BST
 * @tree: Pointer to the root node of the tree to check
 * @min: Pointer to the minimum value allowed in the tree
 * @max: Pointer to the maximum value allowed in the tree
 *
 * Return: 1 if tree is a valid BST, 0 otherwise or if tree is NULL
 */
int binary_tree_is_bst(const binary_tree_t *tree, const binary_tree_t *min, const binary_tree_t *max)
{
	if (tree == NULL)
		return (1);

	if ((min != NULL && tree->n <= min->n) || (max != NULL && tree->n >= max->n))
		return (0);

	return (binary_tree_is_bst(tree->left, min, tree) && binary_tree_is_bst(tree->right, tree, max));
}

/**
 * binary_tree_is_avl_recursive - Checks if a binary tree is a valid AVL Tree
 * @tree: Pointer to the root node of the tree to check
 *
 * Return: 1 if tree is a valid AVL Tree, 0 otherwise
 */
int binary_tree_is_avl_recursive(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (1);

	int balance_factor = binary_tree_balance(tree);
	int left_height = (int)binary_tree_height(tree->left);
	int right_height = (int)binary_tree_height(tree->right);

	if (balance_factor < -1 || balance_factor > 1)
		return (0);

	if (abs(left_height - right_height) > 1)
		return (0);

	return (binary_tree_is_avl_recursive(tree->left) && binary_tree_is_avl_recursive(tree->right));
}