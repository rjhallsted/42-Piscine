/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_btree.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhallste <rhallste@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/13 21:46:10 by rhallste          #+#    #+#             */
/*   Updated: 2017/07/14 15:51:56 by rhallste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_BTREE_H
# define FT_BTREE_H

typedef struct		s_btree
{
	struct s_btree	*left;
	struct s_btree	*right;
	void			*item;
}					t_btree;

t_btree				*btree_create_node(void *item);
void				display_tree(t_btree *root);
void				btree_insert_data(t_btree **root, void *item, int (*cmpf)());
t_btree				*build_tree(char **inputs);
t_btree				*btree_search_item(t_btree *root, void *data_ref, int (*cmpf)(void *, void *));

#endif
