# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nparker <nparker@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/12/11 17:22:58 by nparker           #+#    #+#              #
#    Updated: 2018/12/20 14:54:02 by nparker          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc

FLAGS = -Wall -Wextra -Werror

NAME = gnl

INCL = get_next_line.h

SOURCES = get_next_line.c

OBJECT = $(SOURCES:.c=.o)

$(NAME):
	$(CC) $(FLAGS) $(SOURCES) $(INCL) -L ./libft/ -lft

all: $(NAME)

clean:
	rm -r $(OBJECT)

fclean: clean
	rm -r $(NAME)

re: fclean all

.PHONY: clean fclean
