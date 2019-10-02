/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_for_sized_oct.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sscottie <sscottie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/06 01:22:56 by sscottie          #+#    #+#             */
/*   Updated: 2019/10/02 19:54:19 by sscottie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	do_for_l_oct(t_all *st)
{
	unsigned long int	buf;
	char				*s;
	int					len;
	char				*s_buf;

	buf = (unsigned long)va_arg(st->args, unsigned long int);
	if (buf == 0 && st->acc != -1)
		null_with_acc(st);
	else
	{
		s = ft_l_itoa_base(buf, 8);
		len = ft_strlen(s);
		if (st->acc > len && (s_buf = ft_memalloc(st->acc - len)) != NULL)
		{
			s = fill_with_oct(st, s, s_buf, len);
			len = ft_strlen(s);
		}
		if (st->flag[0] != 'e')
		{
			if (st->flag[1] != 'e')
				ft_fwrite(0, &st->flag[1], 1);
		}
		oct_with_flags(st, s, len);
	}
}

void	do_for_ll_oct(t_all *st)
{
	long long unsigned	buf;
	char				*s;
	int					len;
	char				*s_buf;

	buf = (unsigned long long)va_arg(st->args, unsigned long long);
	if (buf == 0 && st->acc != -1)
		null_with_acc(st);
	else
	{
		s = ft_ll_itoa_base(buf, 8);
		len = ft_strlen(s);
		if (st->acc > len && (s_buf = ft_memalloc(st->acc - len)) != NULL)
		{
			s = fill_with_oct(st, s, s_buf, len);
			len = ft_strlen(s);
		}
		if (st->flag[0] != 'e')
		{
			if (st->flag[1] != 'e')
				ft_fwrite(0, &st->flag[1], 1);
		}
		oct_with_flags(st, s, len);
	}
}

void	do_for_h_oct(t_all *st)
{
	unsigned short int	buf;
	char				*s;
	int					len;
	char				*s_buf;

	buf = (short int)va_arg(st->args, unsigned int);
	if (buf == 0 && st->acc != -1)
		null_with_acc(st);
	else
	{
		s = ft_ll_itoa_base(buf, 8);
		len = ft_strlen(s);
		if (st->acc > len && (s_buf = ft_memalloc(st->acc - len)) != NULL)
		{
			s = fill_with_oct(st, s, s_buf, len);
			len = ft_strlen(s);
		}
		if (st->flag[0] != 'e')
		{
			if (st->flag[1] != 'e')
				ft_fwrite(0, &st->flag[1], 1);
		}
		oct_with_flags(st, s, len);
	}
}

void	do_for_hh_oct(t_all *st)
{
	int			buf;
	char		*s;
	int			len;
	char		*s_buf;

	buf = (short int)va_arg(st->args, unsigned int);
	if (buf == 0 && st->acc != -1)
		null_with_acc(st);
	else
	{
		s = ft_ll_itoa_base(buf, 8);
		len = ft_strlen(s);
		if (st->acc > len && (s_buf = ft_memalloc(st->acc - len)) != NULL)
		{
			s = fill_with_oct(st, s, s_buf, len);
			len = ft_strlen(s);
		}
		if (st->flag[0] != 'e')
		{
			if (st->flag[1] != 'e')
				ft_fwrite(0, &st->flag[1], 1);
		}
		oct_with_flags(st, s, len);
	}
}
