#include "binary_trees.h"

/**
 * binary_tree_insert_left - Inserts a node as a left-child of
 *                           of another in a binary tree.
 * @parent: A pointer to the node to insert the left-child in.
 * @value: The value to store in the new node.
 * Return: a pointer to the new node.
 */
binary_tree_t *binary_tree_insert_left(binary_tree_t *parent, int value)
{
	binary_tree_t *new_nd;

	if (parent == NULL)
		return (NULL);

	new_nd = binary_tree_node(parent, value);
	if (new_nd == NULL)
		return (NULL);

	if (parent->left != NULL)
	{
		new_nd->left = parent->left;
		parent->left->parent = new_nd;
	}
	parent->left = new_nd;

	return (new_nd);
}
