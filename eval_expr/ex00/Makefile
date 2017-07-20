#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rhallste <rhallste@student.42.us.org>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/07/16 13:05:38 by rhallste          #+#    #+#              #
#    Updated: 2017/07/16 23:06:38 by rhallste         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = eval_expr
LIB_NAME = libft.a

SRC = srcs
INC = includes

LIB_SRCS = $(SRC)/ft_split_whitespaces.c $(SRC)/ft_atoi.c $(SRC)/ft_strndup.c \
		$(SRC)/ft_putchar.c $(SRC)/ft_strlen.c $(SRC)/ft_putnbr.c
O_FILES = ft_split_whitespaces.o ft_atoi.o ft_strndup.o ft_putchar.o \
		ft_strlen.o ft_putnbr.o
LIB_CMP = -L. -lft

MAIN_SRCS = $(SRC)/eval_expr.c $(SRC)/operators.c $(SRC)/tree.c \
		$(SRC)/tree_tools.c $(SRC)/main.c $(SRC)/display_tree.c

all: $(NAME)

build_lib:
	gcc -c $(LIB_SRCS)
	ar -rc $(LIB_NAME) $(O_FILES)
	ranlib $(LIB_NAME)
	make clean

$(NAME): build_lib
	gcc -Wall -Werror -Wextra -o $(NAME) $(MAIN_SRCS) $(LIB_CMP)

clean:
	rm -f $(O_FILES)

fclean: clean
	rm -f $(NAME) $(LIB_NAME)