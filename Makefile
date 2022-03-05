# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cbridget <cbridget@student-21school.ru>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/05 19:40:05 by cbridget          #+#    #+#              #
#    Updated: 2022/03/05 13:10:16 by cbridget         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol

#NAME_B = checker

HEAD = hdrs/fractol.h

#HEAD_B = hdrs/checker_bonus.h

SRC = fractol.c

#SRC_B =

OBJ = $(addprefix obj/,$(SRC:.c=.o))

#OBJ_B = $(addprefix obj/,$(SRC_B:.c=.o))

BUILD_FOLDER := $(shell mkdir -p obj)

FLAGS = -Wall -Werror -Wextra

CC = cc

.PHONY : all clean fclean bonus re LIB

all : LIB $(NAME)

LIB :
	$(MAKE) bonus -C libft

$(NAME) : $(OBJ)
	$(CC) $(FLAGS) $(OBJ) -Lminilibx-linux -lmlx -o $(NAME)

#$(NAME_B) : $(OBJ_B)
#	$(CC) $(FLAGS) $(OBJ_B) -Llibft -lft -o $(NAME_B)

obj/%.o : src/%.c $(HEAD) Makefile libft/libft.a
	$(CC) $(FLAGS) -iquote hdrs -iquote minilibx-linux -c $< -o $@

#obj/%.o : src/bonus/%.c $(HEAD_B) Makefile libft/libft.a
#	$(CC) $(FLAGS) -iquote hdrs -iquote libft -c $< -o $@

#bonus : LIB $(NAME_B)

clean :
	rm -rf obj
	$(MAKE) clean -C libft

fclean :
	rm -rf obj
	rm -f $(NAME)
	rm -f $(NAME_B)
	$(MAKE) fclean -C libft

re :
	rm -r obj/*.o
	rm -f $(NAME)
	$(MAKE) fclean -C libft
	$(MAKE)
