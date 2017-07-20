/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_whitespaces.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhallste <rhallste@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/05 19:09:33 by rhallste          #+#    #+#             */
/*   Updated: 2017/07/14 14:58:24 by rhallste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft.h"

int				count_words(char *str)
{
	int i;
	int	count;

	i = 0;
	count = 0;
	if (ft_strlen(str) > 0)
	{
		while (str[i])
		{
			if (i > 0 && (str[i] > 0 && str[i] < 33) && (str[i - 1] > 32))
				count++;
			i++;
		}
		if (str[i - 1] > 32)
			count++;
	}
	return (count);
}

int				find_end_of_word(char *str)
{
	int i;

	i = 0;
	while (str[i] > 32)
		i++;
	return (i);
}

char			**build_words(char *str, char **words, int word_count)
{
	int		i;
	int		word_length;

	i = 0;
	while (i < word_count)
	{
		word_length = find_end_of_word(str);
		*(str + word_length) = '\0';
		words[i] = ft_strdup(str);
		if (i++ < word_count - 1)
		{
			str += word_length + 1;
			while (*str > 0 && *str < 33)
				str++;
		}
	}
	words[i] = NULL;
	return (words);
}

char			**ft_split_whitespaces(char *str)
{
	char	**words;
	char	*str_hld;
	int		word_count;

	while (*str > 0 && *str < 33)
		str++;
	str_hld = ft_strdup(str);
	word_count = count_words(str_hld);
	if (!(words = malloc(sizeof(char *) * (word_count + 1))))
		return (NULL);
	return (build_words(str_hld, words, word_count));
}
