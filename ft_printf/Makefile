# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vtianna <vtianna@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/05/18 23:09:17 by vtianna           #+#    #+#              #
#    Updated: 2020/05/22 19:41:52 by vtianna          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME    = libftprintf.a

CFLAGS  = -Wall -Werror -Wextra

INC	= libftprintf.h

SRC     = count_symbols.c ft_atoi.c ft_bzero.c ft_calloc.c ft_devide_hex_pos.c \
		ft_itoa_size_t.c ft_itoa.c ft_memcpy.c ft_printf.c ft_putchar_fd.c \
		ft_putnbr_fd_hex.c ft_putnbr_fd_size_t.c ft_putnbr_fd.c ft_putstr_fd.c \
		ft_strchr.c ft_strdup.c ft_strlen.c manage_char.c manage_hex.c \
		manage_int.c manage_pointer.c manage_string.c manage_unsigned.c \
		print_space_or_zero.c print_space.c print_zero.c manage_without.c \
		ft_strchr_aster.c check_value.c check_aster.c check_aster_before_dot.c \
		add_values_with_asters.c

OBJ     = $(SRC:%.c=%.o)

all:    $(NAME)

$(NAME):$(OBJ)
	@ar rc $(NAME) $(OBJ)
	@ranlib $(NAME)
	@echo "lib create"

$(OBJ): $(SRC) $(INC)
	@clang $(CFLAGS) -c $(SRC)
	@echo "C O M P I L I N G FINISHED"


clean:
	@rm -f $(OBJ)
	@echo "object files have been  destroyed"


fclean:	clean
	@rm -f $(NAME)
	@echo "lib has been removed"

re:	fclean all

.PHONY: clean fclean all re
