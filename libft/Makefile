# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sscottie <sscottie@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/04/04 22:46:37 by sscottie          #+#    #+#              #
#    Updated: 2019/09/16 20:43:09 by sscottie         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

HEADER = libft.h

SRCS = ft_atoi.c ft_bzero.c ft_isalnum.c ft_isalnum.c \
		ft_isascii.c ft_isdigit.c ft_isprint.c ft_itoa.c \
		ft_memalloc.c ft_memccpy.c ft_memchr.c ft_memcmp.c \
		ft_memdel.c ft_memmove.c ft_memset.c ft_putchar_fd.c \
		ft_putchar.c ft_putendl_fd.c ft_putendl.c ft_putnbr.c \
		ft_putnbr_fd.c ft_putstr_fd.c ft_putstr.c ft_strcat.c \
		ft_strchr.c ft_strclr.c ft_strcmp.c ft_strcpy.c \
		ft_strdel.c ft_strdup.c ft_strequ.c ft_striter.c \
		ft_striteri.c ft_strjoin.c ft_strlcat.c ft_strlen.c \
		ft_strmap.c ft_strmapi.c ft_strncat.c ft_strncmp.c \
		ft_strncpy.c ft_strnequ.c ft_strnew.c ft_strnstr.c \
		ft_strrchr.c ft_strrev.c ft_strsplit.c ft_strstr.c \
		ft_strsub.c ft_strtrim.c ft_swap.c ft_tolower.c \
		ft_toupper.c ft_memcpy.c ft_isalpha.c ft_lstadd.c \
		ft_lstdelone.c ft_lstdel.c ft_lstiter.c ft_lstnew.c \
		ft_lstmap.c ft_swap_bits.c ft_reverse_bits.c \
		ft_print_bits.c ft_is_power_of_n.c ft_strnchr.c ft_intsize.c \
		ft_itoa_base.c ft_l_itoa.c ft_ll_itoa.c ft_l_itoa_base.c \
		ft_ll_itoa_base.c ft_atoi_base.c ft_power.c ft_isnan.c ft_ftoa.c \
		ft_reverse_int.c ft_l_ftoa.c ft_double_power.c ft_strjoinfree.c \
		ft_round.c

OBJ = $(SRCS:%.c=%.o)

FLAG = -Wall -Wextra -Werror -g

all: $(NAME)

$(NAME): $(OBJ) $(HEADER)
	@ar rc $(NAME) $(OBJ)
	@ranlib $(NAME)

%.o: %.c $(HEADER)
	gcc $(FLAG) -c $<

.PHONY: clean fclean re

clean:
	@/bin/rm -f $(OBJ)

fclean: clean
	@/bin/rm -f $(NAME)

re: fclean all

test:
	echo $(OBJ)