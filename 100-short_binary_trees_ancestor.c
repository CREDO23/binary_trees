#include "binary_trees.h"

/**
 * binary_trees_ancestor - Finds the lowest common ancestor of two nodes.
 * @first: Pointer to the first node.
 * @second: Pointer to the second node.
 * Return: If no common ancestors return NULL, else return common ancestor.
 */
binary_tree_t *binary_trees_ancestor(const binary_tree_t *first,
		const binary_tree_t *second)
{
	binary_tree_t *m_m, *p_p;

	if (!first || !second)
		return (NULL);
	if (first == second)
		return ((binary_tree_t *)first);

	m_m = first->parent, p_p = second->parent;
	if (first == p_p || !m_m || (!m_m->parent && p_p))
		return (binary_trees_ancestor(first, p_p));
	else if (m_m == second || !p_p || (!p_p->parent && m_m))
		return (binary_trees_ancestor(m_m, second));
	return (binary_trees_ancestor(m_m, p_p));
}
