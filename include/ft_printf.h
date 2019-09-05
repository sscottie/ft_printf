/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sscottie <sscottie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/01 19:35:27 by sscottie          #+#    #+#             */
/*   Updated: 2019/09/04 23:51:45 by sscottie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTF_H
# define PRINTF_H

# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include "libft.h"

/*
** %[flags][len][.acc][size]type
*/

typedef struct		s_all
{
	char			flag[3];
	char			*fmt;
	char			*fmt_cp;
	int				i;
	va_list			args;
	int				len;
	int				acc;
	int				size;
	char			type;
	
}					t_all;

t_all	*init_st(t_all *st);
int		ft_printf(const char *fmt, ...);
void	reinit_st(t_all *st);
int		parse(t_all *st);
int		pre_format(t_all *st);
void	fill_flags(t_all *st);
void	fill_len_acc(t_all *st);
void	fill_size(t_all *st);
void	do_for_string(t_all *st);
void	string_with_flags(t_all *st, char *s, int len);
void	do_for_char(t_all *st);
void	do_for_percent(t_all *st);
void	do_for_int(t_all *st);
void	do_for_u_int(t_all *st);
void	u_int_with_flags(t_all *st, char *s, int len);
void	do_for_oct(t_all *st);
void	do_for_hex(t_all *st);

#endif
