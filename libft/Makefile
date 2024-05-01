# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pcardin <pcardin@student.42lausanne.ch>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/02 10:43:57 by pcardin           #+#    #+#              #
#    Updated: 2024/04/01 20:30:05 by pcardin          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
SOURCES = \
	ft_tablen.c ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c \
	ft_strlen.c ft_memset.c ft_bzero.c ft_memcpy.c ft_memcpy.c ft_memmove.c \
	ft_strlcpy.c ft_strlcat.c ft_toupper.c ft_tolower.c ft_strchr.c \
	ft_strrchr.c ft_strncmp.c ft_memchr.c ft_memcmp.c ft_strnstr.c ft_atol.c \
	ft_strdup.c ft_calloc.c ft_substr.c ft_strjoin.c ft_strtrim.c ft_strmapi.c \
	ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c \
	ft_striteri.c ft_itoa.c ft_split.c ft_isdigit2.c ft_strjoin2.c ft_strtrim2.c \
	ft_print_c.c ft_print_i.c ft_print_p.c ft_print_s.c ft_print_x.c ft_printf.c \
	get_next_line.c get_next_line_utils.c \

OBJECTS = $(patsubst %.c,obj_dir/%.o,$(SOURCES))
CC = gcc
CFLAGS += -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJECTS)
	@ar rcs $(NAME) $(OBJECTS)

obj_dir/%.o: %.c
	@mkdir -p $(@D)
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@rm -f $(OBJECTS)

fclean: clean
	@rm -f $(NAME)
	@rm -rf obj_dir

re: fclean all

.PHONY: all clean fclean re