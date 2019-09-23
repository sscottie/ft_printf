/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_for_sized_int.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sscottie <sscottie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/01 23:05:27 by sscottie          #+#    #+#             */
/*   Updated: 2019/09/06 00:56:52 by sscottie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

void	do_for_l_int(t_all *st)
{
	long		buf;
	char		*s;
	int			len;
	char		*s_buf;
	int			minus;

	buf = (long int)va_arg(st->args, long long int);
	if (buf == 0 && st->acc != -1)
		null_with_acc(st);
	else
	{
		minus = (buf < 0) ? 1 : 0;
		s = ft_l_itoa(labs(buf));
		len = ft_strlen(s);
		if (st->acc > len && (s_buf = ft_memalloc(st->acc - len)) != NULL)
		{
			s = ft_strcat(ft_memset(s_buf, '0', st->acc - len), s);
			len = ft_strlen(s);
			free(s_buf);
		}
		if (minus == 1)
			do_for_negative(st, s, len);
		else
			int_with_flags(st, s, len);
	}
}

void	do_for_ll_int(t_all *st)
{
	long long	buf;
	char		*s;
	int			len;
	char		*s_buf;
	int			minus;

	buf = (long long int)va_arg(st->args, long long int);
	if (buf == 0 && st->acc != -1)
		null_with_acc(st);
	else
	{
		minus = (buf < 0) ? 1 : 0;
		s = ft_ll_itoa(llabs(buf));
		len = ft_strlen(s);
		if (st->acc > len && (s_buf = ft_memalloc(st->acc - len)) != NULL)
		{
			s = ft_strcat(ft_memset(s_buf, '0', st->acc - len), s);
			len = ft_strlen(s);
			free(s_buf);
		}
		if (minus == 1)
			do_for_negative(st, s, len);
		else
			int_with_flags(st, s, len);
	}
}

void	do_for_h_int(t_all *st)
{
	short int	buf;
	char		*s;
	int			len;
	char		*s_buf;
	int			minus;

	buf = (short int)va_arg(st->args, int);
	if (buf == 0 && st->acc != -1)
		null_with_acc(st);
	else
	{
		minus = (buf < 0) ? 1 : 0;
		s = ft_itoa(abs((int)buf));
		len = ft_strlen(s);
		if (st->acc > len && (s_buf = ft_memalloc(st->acc - len)) != NULL)
		{
			s = ft_strcat(ft_memset(s_buf, '0', st->acc - len), s);
			len = ft_strlen(s);
			free(s_buf);
		}
		if (minus == 1)
			do_for_negative(st, s, len);
		else
			int_with_flags(st, s, len);
	}
}

void	do_for_hh_int(t_all *st)
{
	int			buf;
	char		*s;
	int			len;
	char		*s_buf;
	int			minus;

	buf = (int)va_arg(st->args, int);
	if (buf == '0' && st->acc != -1)
		null_with_acc(st);
	else
	{
		minus = (buf < 0) ? 1 : 0;
		s = ft_itoa(abs(buf));
		len = ft_strlen(s);
		if (st->acc > len && (s_buf = ft_memalloc(st->acc - len)) != NULL)
		{
			s = ft_strcat(ft_memset(s_buf, '0', st->acc - len), s);
			len = ft_strlen(s);
			free(s_buf);
		}
		if (minus == 1)
			do_for_negative(st, s, len);
		else
			int_with_flags(st, s, len);
	}
}
