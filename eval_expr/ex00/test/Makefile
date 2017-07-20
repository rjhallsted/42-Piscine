#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rhallste <rhallste@student.42.us.org>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/07/14 10:55:19 by rhallste          #+#    #+#              #
#    Updated: 2017/07/14 22:40:53 by rhallste         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = test_tree
SRC = srcs
INC = includes
LIBD = library

LIB = libft.a
EX5 = ex05

EX5LIB = $(LIBD)/ft_strcmp.c $(LIBD)/ft_strlen.c $(LIBD)/ft_split_whitespaces.c $(LIBD)/ft_strlcpy.c $(LIBD)/ft_strdup.c
EX5O = ft_strcmp.o ft_strlen.o ft_split_whitespaces.o ft_strlcpy.o ft_strdup.o

TEST_SRCS = $(SRC)/main.c $(SRC)/display_tree.c $(SRC)/btree_create_node.c $(SRC)/btree_insert_data.c $(SRC)/tools.c $(LIBD)/ft_strcmp.c
5_SRCS = $(SRC)/main5.c $(SRC)/btree_create_node.c $(SRC)/btree_insert_data.c ../ex05/btree_search_item.c $(SRC)/tools.c


all: $(NAME)

5lib: clean
	gcc -c $(EX5LIB)
	ar -rc $(LIB) $(EX5O) 
	ranlib $(LIB)

$(NAME):
	gcc -Wall -Werror -Wextra -o $(NAME) $(TEST_SRCS)

ex5: 5lib
	gcc -Wall -Werror -Wextra -o $(EX5) $(5_SRCS) -L. -lft

clean:
	rm -f $(EX5O) $(LIB)

fclean: clean
	rm -f $(NAME) $(EX5)

re: fclean all