# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aguillot <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/10/23 17:11:35 by aguillot          #+#    #+#              #
#    Updated: 2018/11/29 11:52:50 by aguillot         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC_PATH = src/

SRC_NAME = main.c\
		arg_list_controller.c\
		colors_printer.c\
		errors_controller.c\
		ft_select.c\
		signal_handler.c\
		view_controller.c\
		get_input.c\
		movement_manager.c\
		selection_manager.c\
		action_manager.c\
		utils.c\

OBJ_PATH = build/

CPPFLAGS = -I include -I libft

LDLIBS = libft/libft.a

NAME = ft_select

CC = gcc

CFLAGS = -Wall -Wextra -Werror

OBJ_NAME = $(SRC_NAME:.c=.o)

SRC = $(addprefix $(SRC_PATH),$(SRC_NAME))

OBJ = $(addprefix $(OBJ_PATH),$(OBJ_NAME))

all:$(NAME)

$(NAME): $(OBJ)
	make -C libft
	$(CC) -ltermcap $(LDLIBS) $^ -o $@

$(OBJ_PATH)%.o: $(SRC_PATH)%.c
	@mkdir $(OBJ_PATH) 2> /dev/null || true
	$(CC) $(CFLAGS) $(CPPFLAGS) -o $@ -c $<

clean:
	rm -fv $(OBJ)
	@rmdir $(OBJ_PATH) 2> /dev/null || true

fclean: clean
	rm -fv $(NAME)

re: fclean all

norme:
	norminette src/*
	norminette libft/**.[ch]
	norminette include/ft_select.h
.PHONY: all, clean, fclean, re
