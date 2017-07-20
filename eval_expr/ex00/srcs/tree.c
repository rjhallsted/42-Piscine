/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tree.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhallste <rhallste@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/16 10:13:08 by rhallste          #+#    #+#             */
/*   Updated: 2017/07/16 23:19:21 by rhallste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "../includes/ft.h"
#include "../includes/eval_expr.h"

#include <stdio.h>

t_node	*create_node(int (*func)(int, int), int nbr)
{
	t_node *node;

	printf("Building with %d and %p\n", nbr, func);
	node = malloc(sizeof(t_node));
	node->left = NULL;
	node->right = NULL;
	if (func)
	{
		node->func = func;
		node->nbr = 0;
	}
	else
	{
		node->nbr = nbr;
		node->func = NULL;
	}
	return (node);
}

t_node	*build_tree(char **parts)
{
	t_node	*root;
	t_node	*temp;
	int 	part_count;
	int		parts_used;

	part_count = count_parts(parts);
	root = build_tree_part(parts);
	parts_used = count_nodes(root);
	printf("Filled tree\n");
	while (parts_used < part_count)
	{
		temp = root;
		while (parts[parts_used] && (parts[parts_used][0] > '0' 
			|| parts[parts_used][0] == ')' || parts[parts_used][0] == '('))
			parts_used++;
		printf("At part: %d -> %s\n", parts_used,  parts[parts_used]);
		root = create_node(get_opp_func(parts[parts_used]), 0);
		display_tree(root);
		root->left = temp;
		display_tree(root);
		if (parts[parts_used + 2])
			root->right = build_tree_part(parts + parts_used);
		else
			root->right = create_node(parts[parts_used + 1]);
		display_tree(root);
		parts_used = count_nodes(root);
		printf("Filled tree\n");
		printf("%d vs %d\n", part_count, parts_used);
	}
	printf("%d vs %d\n", part_count, parts_used);
	return (root);
}

t_node	*build_tree_part(char **parts)
{
	t_node *node;
	char **inner_section;

	printf("Currently at: %s\n", parts[0]);

	if (parts[0] && parts[1])
	{
		printf("in here for some reason\n");
		if (parts[0][0] != '(')
		{
			node = create_node(get_opp_func(parts[1]), 0);
			node->left = create_node(NULL, ft_atoi(parts[0]));
			node->right = build_tree_part(parts + 2);
//			printf("Creating node to the left with %d\n", node->left->nbr);
		}
		else
		{
			inner_section = duplicate_inner_parentheses(parts);

			int i = 0;
			while (inner_section[i])
			{
				printf("%s -> ", inner_section[i]);
				i++;
			}
			printf("%s\n", inner_section[i]);

			node = build_tree(inner_section);
			free_parts(inner_section);
		}
	}
	else
	{
		printf("Made to here\n");
		node = create_node(NULL, ft_atoi(parts[0]));
	}
//	print_nodes(node);
//	printf("---------------------\n");
	display_tree(node);
	return (node);
}

int		process_tree(t_node *root)
{
	int left;
	int right;
	int (*op)(int, int);

	if (root->func)
	{
		left = process_tree(root->left);
		right = process_tree(root->right);
		op = root->func;
//		printf("%d by %d = %d\n", left, right, op(left, right));
		return (op(left, right));
	}
	else
		return (root->nbr);
}
