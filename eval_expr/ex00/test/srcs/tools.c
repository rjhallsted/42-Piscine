/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhallste <rhallste@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/14 14:47:12 by rhallste          #+#    #+#             */
/*   Updated: 2017/07/14 15:50:42 by rhallste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_btree.h"
#include "../library/ft.h"

t_btree	*build_tree(char **inputs)
{
	t_btree *root;
	int	i;

	i = 0;
	root = 0;
	while (inputs[i])
		btree_insert_data(&root, inputs[i++], &ft_strcmp);
	return (root);
}
