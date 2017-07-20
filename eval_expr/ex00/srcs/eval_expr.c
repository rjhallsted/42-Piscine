/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eval_expr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhallste <rhallste@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/16 10:00:43 by rhallste          #+#    #+#             */
/*   Updated: 2017/07/16 18:30:50 by rhallste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "../includes/ft.h"
#include "../includes/eval_expr.h"

/*
** We call func on 1 and 3 to figure out which function it is, because the
** return values of 1 and 3 are different for each function. As follows:
** add(1, 3) = 4
** subtract(1, 3) = -2
** multiply(1, 3) = 3
** divide(1, 3) = 0
** modulo(1, 3) = 1
*/

int		prec_of(int (*func)(int, int))
{
	int test;

	test = func(1, 3);
	if (test == 0 || test == 1 || test == 3)
		return (0);
	else
		return (1);
}

void	sort_tree(t_node **root)
{
	t_node *temp;
	t_node *current;

	current = *root;
	if ((current->func && current->right && current->right->func)
		&& (prec_of(current->func) < prec_of(current->right->func)))
	{
		temp = current->right;
		current->right = temp->left;
		temp->left = current;
		*root = temp;
	}
	if ((*root)->left)
		sort_tree(&((*root)->left));
	if ((*root)->right)
		sort_tree(&((*root)->right));
}

#include <stdio.h>

int		do_evaluation(char **parts)
{
	t_node	*root;

	root = build_tree(parts);
	printf("Built tree\n");
	sort_tree(&root);
	printf("Sorted tree\n");
	return (process_tree(root));
}

/*
** Note that ft_split_whitespaces() has been modified to split on
** parentheses as well as whitespace	
*/

int		eval_expr(char *str)
{
	char	**parts;
	int		result;

	parts = ft_split_whitespaces(str);
	result = do_evaluation(parts);
	free_parts(parts);
	return (result);
}

void	free_parts(char **parts)
{
	while (*parts)
	{
		free(*parts);
		parts++;
	}
	free (*parts);
}
