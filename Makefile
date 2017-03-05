# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jcentaur <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/02/01 15:25:55 by jcentaur          #+#    #+#              #
#    Updated: 2017/03/03 10:12:54 by jcentaur         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC = 	burning_ship.c \
		mandelbrot.c \
		quinticorn.c \
		auto_hook.c \
		fractale.c \
		mandel3.c \
		mandel5.c \
		tricorn.c \
		julia4.c \
		julia.c \
		misc.c \
		draw.c \
		hook.c \
		main.c \

OBJ = $(SRC:%.c=%.o)

NAME = fractol

all: $(NAME)

$(NAME): $(OBJ)
	make -C libft
	make -C mlx
	gcc $(OBJ) -o $(NAME) -framework OpenGL -framework AppKit -lmlx -L./libft -lft

%.o:%.c
	gcc -o $@ -Wall -Werror -Wextra -Ofast -c $<

clean:
	make fclean -C libft
	make clean -C mlx
	/bin/rm -f $(OBJ)

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all
