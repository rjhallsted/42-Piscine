/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_tree.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhallste <rhallste@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/14 10:23:19 by rhallste          #+#    #+#             */
/*   Updated: 2017/07/16 23:09:33 by rhallste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "../includes/ft_btree.h"

#include <stdio.h>

void	put_spacing(int	count)
{
	if (count > 0)
	{
		write(1, " ", 1);
		put_spacing(--count);
	}
}

int		tree_depth(t_btree *root)
{
	int	left;
	int	right;

	if (root)
	{
		left = tree_depth(root->left);
		right = tree_depth(root->right);
		return ((left > right) ? left + 1 : right + 1);
	}
	return (0);
}

int		ft_strlen(char *str)
{
	return ((*str) ? 1 + ft_strlen(++str) : 0);
}

void	dive_in_tree(t_btree *root, int level, int spacing, int depth)
{
	if (spacing == -1)
		spacing = (depth * 4);
	else
		spacing = (spacing * 3) / 4;
	if (root && level == 1)
	{
		put_spacing(spacing);
		write(1, root->nbr + '0', 2);
	}
	else if (root)
	{
		dive_in_tree(root->left, level - 1, (spacing * 2) / 3, depth);
		dive_in_tree(root->right, level - 1, spacing, depth);
	}
	else if (level == 1)
	{
		put_spacing(spacing);
		write(1, "N", 1);
	}
	else
	{
		put_spacing(spacing);
		write(1, " ", 1);
	}
}

void display_tree(t_btree *root)
{
	int depth;
	int i;

	depth = tree_depth(root);
	i = 1;
	while (i <= depth)
	{
		dive_in_tree(root, i++, -1, depth);
		write (1, "\n", 1);
	}
}
