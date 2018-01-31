# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mmpofu <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/01/09 15:21:06 by mmpofu            #+#    #+#              #
#    Updated: 2018/01/31 13:28:16 by mmpofu           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = filler

SRCS = main.c save_map.c placement.c\
	   save_valid.c ai.c get_resources.c save_map_re.c\

LIB = -L libft -lft

FLAGS = -Wall -Werror -Wextra

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

