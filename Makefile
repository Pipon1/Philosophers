# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hefurrer <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/06/05 08:08:48 by hefurrer          #+#    #+#              #
#    Updated: 2023/06/05 08:08:51 by hefurrer         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := philo
SRC_DIR := src/
OBJ_DIR := obj/
SRC_FILES := main utils parsing
SRC := $(addprefix $(SRC_DIR), $(addsuffix .c, $(SRC_FILES)))
OBJ := $(addprefix $(OBJ_DIR), $(addsuffix .o, $(SRC_FILES)))
CC := gcc -Wall -Werror -Wextra

all: $(NAME)

$(OBJ_DIR)%.o: $(SRC_DIR)%.c
	mkdir -p obj
	$(CC) $< -c -o $@

$(NAME): $(OBJ)
	$(CC) $(OBJ) -o $(NAME)

clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
