/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tree_tools.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhallste <rhallste@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/16 10:32:08 by rhallste          #+#    #+#             */
/*   Updated: 2017/07/16 22:11:24 by rhallste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "../includes/ft.h"
#include "../includes/eval_expr.h"
#include "../includes/opps.h"

int		is_operator(char *str)
{
	char c;

	c = str[0];
	if (c == '+' || c == '-' || c == '*' || c == '/' || c == '%'
				|| c == '(' || c == ')')
		return (1);
	else
		return (0);
}

void	*get_opp_func(char *str)
{
	char	c;
	int		i;

	c = str[0];
	i = 0;
	while (i < 5)
	{
		if (c == g_opps[i].symbol)
			return (g_opps[i].func);
		i++;
	}
	return (NULL);
}

int		count_parts(char **parts)
{
	int count;
	char **current;

	count = 0;
	current = parts;
	while (*current)
	{
		if (*current[0] != '(' && *current[0] != ')')
			count++;
		current++;
	}
	return (count);
}

#include <stdio.h>

int		count_nodes(t_node *root)
{
	if (root)
		return (1 + count_nodes(root->left) + count_nodes(root->right));
	else
		return (0);
}

int		print_nodes(t_node *root)
{
	if (root)
	{
		printf("%d: %p\n", root->nbr, root->func);
		printf("\tself: %p\n", root);
		printf("\tleft: %p\n", root->left);
		printf("\tright: %p\n", root->right);
		return (1 + print_nodes(root->left) + print_nodes(root->right));
	}
	else
		return (0);
}

char	**duplicate_inner_parentheses(char **parts)
{
	int paren_count;
	char **current;
	int	cut_length;
	char **new;

	paren_count = 1;
	current = parts + 1;
	cut_length = 0;
	while (paren_count > 0)
	{
		if (*current[0] == '(')
			paren_count++;
		if (*current[0] == ')')
			paren_count--;
		cut_length++;
		current++;
	}
	cut_length--;
	paren_count = 0;
	current = parts + 1;
	new = malloc(sizeof(char *) * (cut_length + 1));
	while (paren_count < cut_length)
	{
		new[paren_count] = ft_strndup(*current, ft_strlen(*current));
		paren_count++;
		current++;		
	}
	new[paren_count] = NULL;
	return (new);
}
