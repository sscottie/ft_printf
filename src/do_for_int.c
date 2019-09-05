/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_for_int.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sscottie <sscottie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/01 23:05:27 by sscottie          #+#    #+#             */
/*   Updated: 2019/09/05 20:00:50 by sscottie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

void	do_for_negative(t_all *st, char *s, int len)
{
	if (st->flag[0] == '-')
	{
		write(1, "-", 1);
		write(1, s, len);
		while (--st->len - len > 0)
			write(1, " ", 1);
	}
	else if (st->flag[0] == '0' && st->acc == -1)
	{
		write(1, "-", 1);
		while (--st->len - len > 0)
			write(1, "0", 1);
		write(1, s, len);
	}
	else
	{
		while (st->len-- - len > 1)
			write(1, " ", 1);
		write(1, "-", 1);
		write(1, s, len);
	}
}

void	int_with_flags(t_all *st, char *s, int len)
{
	if (st->flag[0] == '-')
	{
		write(1, s, len);
		while (st->len-- - len > 0)
			write(1, " ", 1);
	}
	else if (st->flag[0] == '0' && st->acc == -1)
	{
		while (st->len-- - len > 0)
			write(1, "0", 1);
		write(1, s, len);
	}
	else
	{
		if (st->len != 0 && st->len > len && st->flag[1] == 'e')
			while (st->len-- - len > 0)
				write(1, " ", 1);
		else if (st->len != 0 && st->len > len && st->flag[1] != 'e')
			while (st->len-- - len > 1)
				write(1, " ", 1);
		if (st->flag[1] != 'e')
			write(1, &st->flag[1], 1);
		write(1, s, len);
	}
}

void	do_for_int(t_all *st)
{
	int			buf;
	char		*s;
	int			len;
	char		*s_buf;
	int			minus;

	buf = (int)va_arg(st->args, int);
	minus = (buf < 0) ? 1 : 0;
	s = ft_itoa(abs(buf));
	len = ft_strlen(s);
	if (st->acc > len && (s_buf = ft_memalloc(st->acc - len)) != NULL)
	{
		s = ft_strcat(ft_memset(s_buf, '0', st->acc - len), s);
		len = ft_strlen(s);
		free(s_buf);
	}
	if (st->flag[0] != 'e' && st->flag[1] != 'e' && minus != 1 && (st->len < st->acc || st->acc == -1))
	{
		write(1, &st->flag[1], 1);
		st->len--;
	}
	if (minus == 1)
		do_for_negative(st, s, len);
	else
		int_with_flags(st, s, len);
}
