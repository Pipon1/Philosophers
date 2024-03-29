# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hefurrer <marvin@42lausanne.ch>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/25 08:08:22 by hefurrer          #+#    #+#              #
#    Updated: 2023/09/25 08:08:25 by hefurrer         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

ECHO = @echo
PRINT = @printf
RED = \033[31m
GREEN = \033[32m
YELLOW = \033[33m
INVERT = \033[7m
RESETTXT = \033[0m
BOLD = \033[1m

SRC_PATH = src/
SRC = main.c thread.c utils.c init_utils.c utils2.c utils3.c
SRCS = $(addprefix $(SRC_PATH),$(SRC))

OBJ_PATH = obj/
OBJ = $(SRC:%.c=%.o)
OBJS = $(addprefix $(OBJ_PATH),$(OBJ))

NAME 	= Philosopher
AR 		= ar rcs
CC		= gcc
RM		= rm -f

INCLUDES = -I includes/

CFLAGS = -g -pthread -Werror -Wextra -Wall #-fsanitize=thread

all: $(NAME)

$(NAME): $(OBJ)
		$(ECHO) "$(YELLOW)Compilation de Philosopher...$(RESETTXT)"
		@ gcc $(CFLAGS) $(INCLUDES) $(OBJS) -o $@
		$(ECHO) "$(GREEN)$(BOLD)Compilation Terminée !!!$(RESETTXT)"

%.o:$(SRC_PATH)%.c
		$(PRINT) "$(YELLOW)Generation des objets...$(RESETTXT)\r"
		@mkdir -p $(OBJ_PATH)
		@$(CC) $(INCLUDES) $(CFLAGS) -c $< -o $(OBJ_PATH)$@

clean:
		$(ECHO) "$(RED)Suppression des objets...$(RESETTXT)"
		@$(RM) $(OBJS)
		$(ECHO) "$(GREEN)$(BOLD)Terminé !$(RESETTXT)"

fclean:	clean
		$(ECHO) "$(RED)Suppression de pipex et libft.a...$(RESETTXT)"
		@$(RM) $(NAME)
		$(ECHO) "$(GREEN)$(BOLD)Terminé !$(RESETTXT)"

re:		fclean all

.PHONY: all clean fclean re
