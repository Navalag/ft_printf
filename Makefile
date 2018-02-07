# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: agalavan <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/02/07 13:16:08 by agalavan          #+#    #+#              #
#    Updated: 2018/02/07 13:16:10 by agalavan         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

FLAGS = -Wall -Wextra -Werror -O3

SRCS =	main.c \
		ft_printf.c \
		valid_func.c \
		unicod_func.c \
		read_flag.c \
		print_res_func.c \
		set_flag_func.c \
		cast_func.c \
		solve_func.c \
		itoa_func.c

OBJS = $(SRCS:%.c=%.o)

all: $(NAME)

$(NAME): $(OBJS)
	make -C libft
	ar rc $(NAME) $(OBJS) libft/*.o
	ranlib $(NAME)

%.o: %.c
	gcc $(FLAGS) -c -o $@ $<

clean:
	-rm -f $(OBJS)
	make clean -C libft

fclean: clean
	-rm -f $(NAME)
	make fclean -C libft

re: fclean all

.PHONY: all clean fclean re
