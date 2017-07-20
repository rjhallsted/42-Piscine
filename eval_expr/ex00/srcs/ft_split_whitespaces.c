/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_whitespaces.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhallste <rhallste@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/05 19:09:33 by rhallste          #+#    #+#             */
/*   Updated: 2017/07/16 22:23:34 by rhallste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "../includes/ft.h"

int				is_splitter(char c)
{
	if (c > 0 && c < 33)
		return (1);
	else
		return (0);
}

int				is_not_space(char c)
{
	if (c > 32)
		return (1);
	else
		return (0);
}

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
			if ((i > 0 && is_splitter(str[i]) && is_not_space(str[i - 1]))
				|| (str[i] == '(' || str[i] == ')'))
				count++;
			i++;
		}
		if (is_not_space(str[i - 1]))
			count++;
	}
	return (count);
}

int				find_end_of_word(char *str)
{
	int i;

	i = 0;
	if (str[i] == '(' || str[i] == ')')
		return (1);
	while (is_not_space(str[i]) && str[i] != '(' && str[i] != ')')
		i++;
	return (i);
}

#include <stdio.h>

char			**build_words(char *str, char **words, int word_count)
{
	int		i;
	int		word_length;

	i = 0;
	while (i < word_count)
	{
		word_length = find_end_of_word(str);
		if (*str == '(')
			words[i] = ft_strndup("(", 1);
		else if (*str == ')')
			words[i] = ft_strndup(")", 1);
		else
			words[i] = ft_strndup(str, word_length);
//		printf("Part %d: %s\n", i, words[i]);
		if (i++ < word_count - 1)
		{
			str += word_length;
			while (is_splitter(*str))
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
	str_hld = ft_strndup(str, ft_strlen(str));
	word_count = count_words(str_hld);
	if (!(words = malloc(sizeof(char *) * (word_count + 1))))
		return (NULL);
	return (build_words(str_hld, words, word_count));
}
