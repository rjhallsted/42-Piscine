/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhallste <rhallste@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/14 10:49:40 by rhallste          #+#    #+#             */
/*   Updated: 2017/07/14 15:46:48 by rhallste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_btree.h"
#include "../library/ft.h"

#include <stdio.h>

int	main(int argc, char **argv)
{
	int i;
	t_btree *root;

	root = 0;
	i = 1;
	while (i < argc)
		btree_insert_data(&root, argv[i++], &ft_strcmp);
	display_tree(root);
	return (0);
}
