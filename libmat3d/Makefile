# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vkaron <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/09/23 17:12:18 by vkaron            #+#    #+#              #
#    Updated: 2019/10/16 21:00:31 by vkaron           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY: all, clean, fclean, re

FLAGS = -Wall -Wextra -Werror

C_FILES = 	abs_delta_v2.c eqal_v2.c mult_vm.c set_v4.c sign_v2.c\
			set_m4_s.c set_m4_pc.c set_m4_rx.c set_m4_rz.c

O_FILES = $(C_FILES:.c=.o)

NAME = libmat3d.a

all: $(NAME)

$(NAME): $(O_FILES)
	ar rc $(NAME) $(O_FILES)

%.o: %.c
	gcc	$(FLAGS) -c $^ 

clean:
	rm -f $(O_FILES)

fclean : clean
	rm -f $(NAME)

re: fclean all
