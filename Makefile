# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mmpofu <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/01/09 15:21:06 by mmpofu            #+#    #+#              #
#    Updated: 2018/01/25 14:56:51 by mmpofu           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = thor

SRCS = main.c save_map.c placement.c\
	   save_valid.c ai.c\

LIB = -L libft -lft

FLAGS = # -Wall -Werror -Wextra

OBJ = $(SRCS:.c=.o)

all: $(NAME)

$(NAME):
	make -C libft/ fclean && make -C libft/
	clang $(FLAGS) $(SRCS) $(LIB) -o $(NAME)

clean:
	@rm -f $(OBJ)

fclean: clean
	@rm -f $(NAME)

re:		fclean all

