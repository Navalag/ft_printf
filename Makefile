NAME = libftprintf.a
FLAG =  -Wall -Werror -Wextra -O3
SRC =	choose_type_of_arg.c		\
		free_memory.c 				\
		ft_printf.c					\
		ft_uintmxtoa.c				\
		fun_to_pars_key.c			\
		hamdle_d.c					\
		is_someone.c				\
		make_some_value.c			\
		prepare_string_to_print.c	\
		switch_on_flags.c			\
		switch_on_wchar_flags.c		\
		wchar_lib.c					\
		wchar_t_unicode.c			\
		work_with_arg.c				\
		work_with_c_utf_c.c			\
		work_with_d_utf_d_u_s.c		\
		work_with_wchar_s.c			\

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	make -C libft
	ar rc $(NAME) $(OBJ) libft/*.o
	ranlib $(NAME)

%.o: %.c
	gcc $(FLAG) -c -o $@ $<

clean:
	rm -f $(OBJ)
	make clean -C libft

fclean: clean
	rm -f $(NAME)
	make fclean -C libft

re: fclean all