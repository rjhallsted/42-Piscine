/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eval_expr.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhallste <rhallste@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/16 10:03:49 by rhallste          #+#    #+#             */
/*   Updated: 2017/07/16 23:06:56 by rhallste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EVAL_EXPR_H
# define EVAL_EXPR_H

typedef struct s_node t_node;

struct			s_node {
	t_node		*left;
	t_node		*right;
	int			(*func)(int, int);
	int			nbr;
};

int				add(int a, int b);
int				subtract(int a, int b);
int				multiply(int a, int b);
int				divide(int a, int b);
int				modulo(int a, int b);

t_node			*build_tree(char **parts);
t_node			*build_tree_part(char **parts);
int				count_nodes(t_node *root);
int				count_parts(char **parts);
t_node			*create_node(int (*func)(int, int), int nbr);
int				do_evaluation(char **parts);
char			**duplicate_inner_parentheses(char **parts);
int				eval_expr(char *str);
void			free_parts(char **parts);
void			*get_opp_func(char *str);
int				is_operator(char *str);
void			order_tree(t_node *root);
int				process_tree(t_node *root);


int				print_nodes(t_node *root);
void			display_tree(t_node *root);

#endif
