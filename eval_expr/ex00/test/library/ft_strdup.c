/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhallste <rhallste@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/05 10:26:25 by rhallste          #+#    #+#             */
/*   Updated: 2017/07/11 09:40:06 by rhallste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int				ft_strlen(char *str);

unsigned int	ft_strlcpy(char *dest, char *src, unsigned int size);

char			*ft_strdup(char *src)
{
	char	*copy;
	int		size;

	size = ft_strlen(src) + 1;
	copy = malloc(sizeof(char) * size);
	ft_strlcpy(copy, src, size);
	return (copy);
}
