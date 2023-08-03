#include "binary_trees.h"

/**
 * binary_tree_insert_right - Insert a node as the right-child
 *                            of another in a binary tree.
 * @parent: A pointer to the node to insert the right-child in.
 * @value: The value to store in the new_nd node.
 *
 * Return: a pointer to the new node.
 */
binary_tree_t *binary_tree_insert_right(binary_tree_t *parent, int value)
{
	binary_tree_t *new_nd;

	if (parent == NULL)
		return (NULL);

	new_nd = binary_tree_node(parent, value);
	if (new_nd == NULL)
		return (NULL);

	if (parent->right != NULL)
	{
		new_nd->right = parent->right;
		parent->right->parent = new_nd;
	}
	parent->right = new_nd;

	return (new_nd);
}
