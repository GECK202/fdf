# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vkaron <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/09/23 17:12:18 by vkaron            #+#    #+#              #
#    Updated: 2019/10/23 18:02:15 by vkaron           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY: all, clean, fclean, re

FLAGS = -Wall -Wextra -Werror

C_FILES = 	ft_strlen.c ft_strdup.c ft_strdup2.c ft_strndup.c ft_swap.c\
			ft_atoi.c ft_atoi_16.c ft_strrdup.c ft_strmcat.c ft_strfind.c\
			ft_isspace.c ft_strncpy.c ft_strsplit.c get_next_line.c\
			ft_itoa.c ft_pad_left.c ft_max.c ft_min.c ft_clamp.c

O_FILES = $(C_FILES:.c=.o)

H_DIR = -IIncludes

NAME = libft.a

all: $(NAME)

$(NAME): $(O_FILES)
	ar rc $(NAME) $(O_FILES)

%.o: %.c
	gcc	$(FLAGS) -c $^ $(H_DIR)

clean:
	rm -f $(O_FILES)

fclean : clean
	rm -f $(NAME)

re: fclean all
