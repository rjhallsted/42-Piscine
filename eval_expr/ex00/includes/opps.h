/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   opps.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhallste <rhallste@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/16 14:06:40 by rhallste          #+#    #+#             */
/*   Updated: 2017/07/16 17:39:09 by rhallste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OPPS_H
# define OPPS_H

typedef struct	s_opps {
	char		symbol;
	int			(*func)(int, int);
}				t_opps;

t_opps			g_opps[] = {
	{'+', &add},
	{'-', &subtract},
	{'*', &multiply},
	{'/', &divide},
	{'%', &modulo}
};

#endif
