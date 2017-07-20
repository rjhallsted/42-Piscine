/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhallste <rhallste@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/16 09:58:27 by rhallste          #+#    #+#             */
/*   Updated: 2017/07/16 16:31:19 by rhallste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_H
# define FT_H

int		ft_atoi(char *str);
void	ft_putchar(char c);
void	ft_putnbr(int nb);
char	**ft_split_whitespaces(char *str);
char	*ft_strndup(char *str, int length);
int		ft_strlen(char *str);

#endif
