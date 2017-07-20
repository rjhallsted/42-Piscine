/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main5.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhallste <rhallste@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/14 15:33:41 by rhallste          #+#    #+#             */
/*   Updated: 2017/07/14 22:18:27 by rhallste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_btree.h"
#include "../library/ft.h"
#include <stdio.h>

int	main(int argc, char **argv)
{
	char **inputs;
	char *search;
	t_btree *root;
	t_btree *found;

	(void)argc;
	inputs = ft_split_whitespaces(argv[1]);
	search = argv[2];
	root = build_tree(inputs);
	found = btree_search_item(root, search, (void *)ft_strcmp);
	printf("%s\n", found->item);
	return (0);
}
