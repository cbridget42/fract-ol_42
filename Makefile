# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cbridget <cbridget@student.21-school.ru    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/05 19:40:05 by cbridget          #+#    #+#              #
#    Updated: 2022/09/15 18:37:56by cbridget         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol

HEAD = hdrs/fractol.h

SRC = main.c fractals.c parser.c init_f.c drawing.c hooks_f.c hooks_two.c \
hooks_three.c errors.c

OBJ = $(addprefix obj/,$(SRC:.c=.o))

BUILD_FOLDER := $(shell mkdir -p obj)

FLAGS = -Wall -Werror -Wextra -O2

CC = cc

.PHONY : all clean fclean bonus re LIB MINILIBX

all : LIB MINILIBX $(NAME)

MINILIBX :
	$(MAKE) -C minilibx

LIB :
	$(MAKE) bonus -C libft

$(NAME) : $(OBJ)
	$(CC) $(FLAGS) $(OBJ) minilibx/libmlx.a -framework OpenGL -framework AppKit -Llibft -lftprintf -o $(NAME)

obj/%.o : src/%.c $(HEAD) Makefile libft/libftprintf.a
	$(CC) $(FLAGS) -iquote hdrs -iquote libft/headers -iquote libft/libft -iquote minilibx/ -c $< -o $@

bonus : all

clean :
	rm -rf obj
	$(MAKE) clean -C libft

fclean :
	rm -rf obj
	rm -f $(NAME)
	$(MAKE) fclean -C libft

re :
	rm -r obj/*.o
	rm -f $(NAME)
	$(MAKE) fclean -C libft
	$(MAKE)
