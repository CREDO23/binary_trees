#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "binary_trees.h"

/**
 * print_t - Stores recursively each level in an array of strings
 * @tree: Pointer to the node to print
 * @offset: Offset to print
 * @depth: Depth of the node
 * @s: Buffer
 * Return: length of printed tree after process
 */
static int print_t(const binary_tree_t *tree, int offset, int depth, char **s)
{
	char b[6];
	int wdth, left, right, is_left, i;

	if (!tree)
		return (0);
	is_left = (tree->parent && tree->parent->left == tree);
	wdth = sprintf(b, "(%03d)", tree->n);
	left = print_t(tree->left, offset, depth + 1, s);
	right = print_t(tree->right, offset + left + wdth, depth + 1, s);
	for (i = 0; i < wdth; i++)
		s[depth][offset + left + i] = b[i];
	if (depth && is_left)
	{
		for (i = 0; i < wdth + right; i++)
			s[depth - 1][offset + left + wdth / 2 + i] = '-';
		s[depth - 1][offset + left + wdth / 2] = '.';
	}
	else if (depth && !is_left)
	{
		for (i = 0; i < left + wdth; i++)
			s[depth - 1][offset - wdth / 2 + i] = '-';
		s[depth - 1][offset + left + wdth / 2] = '.';
	}
	return (left + wdth + right);
}

/**
 * _height - Measures the hght of a binary tree
 * @tree: Pointer to the node to measures the hght
 * Return: The hght of the tree starting at @node
 */
static size_t _height(const binary_tree_t *tree)
{
	size_t hght_l;
	size_t hght_r;

	hght_l = tree->left ? 1 + _height(tree->left) : 0;
	hght_r = tree->right ? 1 + _height(tree->right) : 0;
	return (hght_l > hght_r ? hght_l : hght_r);
}

/**
 * binary_tree_print - Prints a binary tree
 * @tree: Pointer to the root node of the tree to print
 */
void binary_tree_print(const binary_tree_t *tree)
{
	char **s;
	size_t hght, i, j;

	if (!tree)
		return;
	hght = _height(tree);
	s = malloc(sizeof(*s) * (hght + 1));
	if (!s)
		return;
	for (i = 0; i < hght + 1; i++)
	{
		s[i] = malloc(sizeof(**s) * 255);
		if (!s[i])
			return;
		memset(s[i], 32, 255);
	}
	print_t(tree, 0, 0, s);
	for (i = 0; i < hght + 1; i++)
	{
		for (j = 254; j > 1; --j)
		{
			if (s[i][j] != ' ')
				break;
			s[i][j] = '\0';
		}
		printf("%s\n", s[i]);
		free(s[i]);
	}
	free(s);
}
