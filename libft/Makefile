# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cbridget <cbridget@student.21-school.ru    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/11 15:17:31 by cbridget          #+#    #+#              #
#    Updated: 2022/09/15 18:43:14 by cbridget         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

HEAD = headers/ft_printf.h

LIST = ft_printf.c my_parser.c get_extension.c subsidiary.c subsidiary_two.c\
my_realloc.c create_c%.c add_width.c precision_form.c

OBJ = $(addprefix obj/,$(LIST:.c=.o))

BUILD_FOLDER := $(shell mkdir -p obj)

FLAGS = -Wall -Wextra -Werror -O2

CC = gcc

.PHONY : all clean fclean re bonus LIB

all : LIB $(NAME)

$(NAME) : $(OBJ) libft/libft.a
	cp libft/libft.a $(NAME)
	ar rcs $(NAME) $(OBJ) $(HEAD)

obj/%.o : srcs/%.c $(HEAD) Makefile
	$(CC) $(FLAGS) -I headers -I libft -c $< -o $@

LIB :
	@$(MAKE) bonus -C libft

bonus : all

clean :
	rm -f $(OBJ)
	@make clean -C libft

fclean :
	rm -f $(NAME) $(OBJ)
	@make fclean -C libft

re : fclean all
