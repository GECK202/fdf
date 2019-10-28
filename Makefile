# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vkaron <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/09/23 17:12:18 by vkaron            #+#    #+#              #
#    Updated: 2019/10/23 17:55:30 by vkaron           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY: all, clean, fclean, re, libr

FLAGS = -Wall -Wextra -Werror -g

C_FILES = 	fdf.c events.c image.c projection.c read_file.c init.c tools.c\
			menu.c draw_interface.c color.c

O_FILES = $(C_FILES:.c=.o)

H_DIR = -Ilibft/Includes -Ilibmat3d -Iminilibx_macos

NAME = fdf

MLX = minilibx

all: $(NAME)

libr:
	make -C libft/ all
	make -C libmat3d/ all
	make -C $(MLX)/ all

$(NAME): libr $(O_FILES)
	gcc $(FLAGS) -o $(NAME) $(O_FILES) $(H_DIR) -Llibmat3d/ -lmat3d -Llibft/ -lft -L$(MLX) -lmlx -framework OpenGL -framework AppKit

%.o: %.c fdf.h
	gcc $(FLAGS) -c $^ $(H_DIR)

clean:
	rm -f $(O_FILES)
	make -C libft/ clean
	make -C $(MLX)/ clean
	make -C libmat3d/ clean

fclean : clean
	rm -f $(NAME)
	make -C libft/ fclean
	make -C libmat3d/ fclean

re: fclean all
