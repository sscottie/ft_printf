# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sscottie <sscottie@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/09/01 19:44:17 by sscottie          #+#    #+#              #
#    Updated: 2019/10/01 19:13:47 by sscottie         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =		libftprintf.a
LIBFT_A =	libft.a

COMP =		gcc -Wall -Werror -Wextra -g $(PRINTF_H) $(LIBFT_H) -c -o

PRINTF_H =	-I include/
LIBFT_H = 	-I libft/

OBJ_DIR =	obj/
SRC_DIR =	src/
LIB_DIR =	libft/

CFILE =		ft_printf.c \
			init_st.c \
			parse.c \
			format.c \
			do_for_string.c \
			do_for_char.c \
			do_for_int.c \
			do_for_u_int.c \
			do_for_oct.c \
			do_for_hex.c \
			do_for_null.c \
			crossroads.c \
			do_for_sized_int.c \
			do_for_sized_u.c \
			do_for_sized_oct.c \
			do_for_sized_hex.c \
			do_for_pointer.c \
			do_for_floats.c \
			ft_fwrite.c

CFIND =		$(CFILE:%=$(SRC_DIR)%)

OFILE =		$(CFILE:%.c=%.o)

OBJ =		$(addprefix $(OBJ_DIR), $(OFILE))

all: $(OBJ_DIR) $(NAME) $(CFIND)

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)
	@echo Create: ft_printf Object directory

$(NAME): $(OBJ)
	@echo LIBFT START
	@make -C $(LIB_DIR)
	@echo Copying $(LIBFT_A) to root.
	@cp $(LIB_DIR)$(LIBFT_A) .
	@mv $(LIBFT_A) $(NAME)
	@ar rc $(NAME) $(addprefix $(OBJ_DIR), $(OFILE))
	@ranlib $(NAME)
	@echo Merged: $(NAME) with $(LIBFT_A)
	@echo FT_PRINTF COMPLETE

$(OBJ): $(CFIND)
	@$(MAKE) $(OFILE)

$(OFILE):
	@echo Create: $(@:obj/%=%)
	@$(COMP) $(OBJ_DIR)$@ $(SRC_DIR)$(@:%.o=%.c)

clean:
	@/bin/rm -rf $(OBJ_DIR)
	@make -C $(LIB_DIR) clean
	@echo Cleaned ft_printf object files

fclean: clean
	@/bin/rm -f $(NAME)
	@make -C $(LIB_DIR) fclean
	@echo Cleaned $(NAME)

re: fclean all

.PHONY: all clean flcean re