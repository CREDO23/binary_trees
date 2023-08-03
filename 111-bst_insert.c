#include "binary_trees.h"

/**
 * bst_insert - Inserts a value in a Binary Search Tree.
 * @tree: A double pointer to the root node of the BST to insert the value.
 * @value: The value to store in the node to be inserted.
 * Return: A pointer to the created node, or NULL on failure.
 */
bst_t *bst_insert(bst_t **tree, int value)
{
	bst_t *cu, *new_nd;

	if (tree != NULL)
	{
		cu = *tree;

		if (cu == NULL)
		{
			new_nd = binary_tree_node(cu, value);
			if (new_nd == NULL)
				return (NULL);
			return (*tree = new_nd);
		}

		if (value < cu->n) /* insert in left subtree */
		{
			if (cu->left != NULL)
				return (bst_insert(&cu->left, value));

			new_nd = binary_tree_node(cu, value);
			if (new_nd == NULL)
				return (NULL);
			return (cu->left = new_nd);
		}
		if (value > cu->n) /* insert in right subtree */
		{
			if (cu->right != NULL)
				return (bst_insert(&cu->right, value));

			new_nd = binary_tree_node(cu, value);
			if (new_nd == NULL)
				return (NULL);
			return (cu->right = new_nd);
		}
	}
	return (NULL);
}
