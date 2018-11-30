# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aguillot <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/15 18:57:13 by aguillot          #+#    #+#              #
#    Updated: 2018/11/28 16:23:30 by aguillot         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

FLAG = -Wextra -Werror -Wall

SRC  = ./ft_isalpha.c ft_memccpy.c ft_memmove.c ft_putendl_fd.c ft_strcat.c \
	   ft_strdel.c ft_strjoin.c ft_strncat.c ft_strnstr.c ft_tolower.c \
	   ft_isascii.c ft_memchr.c ft_memset.c ft_putnbr.c ft_strchr.c \
	   ft_strdup.c ft_strlcat.c ft_strncmp.c ft_strrchr.c ft_toupper.c \
	   ft_atoi.c ft_isdigit.c ft_memcmp.c ft_putchar.c ft_putnbr_fd.c  \
	   ft_strclr.c ft_strequ.c ft_strlen.c ft_strncpy.c ft_strstr.c  \
	   ft_bzero.c ft_isprint.c ft_memcpy.c ft_putchar_fd.c ft_putstr.c \
	   ft_strcmp.c ft_striter.c ft_strmap.c ft_strnequ.c ft_strsub.c \
	   ft_isalnum.c ft_memalloc.c ft_memdel.c ft_putendl.c ft_putstr_fd.c \
	   ft_strcpy.c ft_striteri.c ft_strmapi.c ft_strnew.c  ft_strtrim.c \
	   ft_itoa.c ft_strsplit.c ft_strnchr.c ft_strnnchr.c ft_power.c \
	   ft_strflen.c ft_nblen.c ft_putoff_t.c ft_strlink.c ft_off_t_len.c \
	   ft_count_char.c ft_splitwhitespaces.c ft_tabdup.c ft_strlinktochar.c\
	   ft_strichr.c ft_strndup.c ft_strjoinfree.c ft_strlenuntilc.c\
	   get_next_line.c ft_putchar_int.c ft_finishes_by.c ft_ascii_art.c

OBJ = ./ft_isalpha.o ft_memccpy.o ft_memmove.o ft_putendl_fd.o ft_strcat.o \
	   ft_strdel.o ft_strjoin.o ft_strncat.o ft_strnstr.o ft_tolower.o \
	   ft_isascii.o ft_memchr.o ft_memset.o ft_putnbr.o ft_strchr.o \
	   ft_strdup.o ft_strlcat.o ft_strncmp.o ft_strrchr.o ft_toupper.o \
	   ft_atoi.o ft_isdigit.o ft_memcmp.o ft_putchar.o ft_putnbr_fd.o  \
	   ft_strclr.o ft_strequ.o ft_strlen.o ft_strncpy.o ft_strstr.o  \
	   ft_bzero.o ft_isprint.o ft_memcpy.o ft_putchar_fd.o ft_putstr.o \
	   ft_strcmp.o ft_striter.o ft_strmap.o ft_strnequ.o ft_strsub.o \
	   ft_isalnum.o ft_memalloc.o ft_memdel.o ft_putendl.o ft_putstr_fd.o \
	   ft_strcpy.o ft_striteri.o ft_strmapi.o ft_strnew.o  ft_strtrim.o \
	   ft_itoa.o ft_strsplit.o ft_strnchr.o ft_strnnchr.o ft_power.o \
	   ft_strflen.o ft_nblen.o ft_putoff_t.o ft_strlink.o ft_off_t_len.o \
	   ft_count_char.o ft_splitwhitespaces.o ft_tabdup.o ft_strlinktochar.o\
	   ft_strichr.o ft_strndup.o ft_strjoinfree.o ft_strlenuntilc.o\
	   get_next_line.o ft_putchar_int.o ft_finishes_by.o ft_ascii_art.o

all: $(NAME)

$(NAME):
	gcc $(FLAG) -c $(SRC)
	ar rc $(NAME) $(OBJ)
	ranlib $(NAME)

clean:
	/bin/rm -f $(OBJ)

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all
