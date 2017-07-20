/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_insert_data.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhallste <rhallste@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/14 09:24:07 by rhallste          #+#    #+#             */
/*   Updated: 2017/07/14 15:44:55 by rhallste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_btree.h"

void	btree_insert_data(t_btree **root, void *item,
										int (*cmpf)(void *, void *))
{
	t_btree *node;
	
	if (*root)
	{
		node = *root;
		if (cmpf(node->item, item) < 0)
			btree_insert_data(&(node->right), item, cmpf);
		else
			btree_insert_data(&(node->left), item, cmpf);
	}
	else
		*root = btree_create_node(item);
}
