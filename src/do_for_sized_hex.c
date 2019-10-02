/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_for_sized_hex.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sscottie <sscottie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/06 02:15:21 by sscottie          #+#    #+#             */
/*   Updated: 2019/10/02 19:53:20 by sscottie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	do_for_l_hex(t_all *st)
{
	unsigned long	buf;
	char			*s;
	int				len;
	char			*s_buf;

	buf = (unsigned long)va_arg(st->args, unsigned long);
	if (buf == 0 && st->acc != -1)
		null_with_acc(st);
	else
	{
		s = ft_l_itoa_base(buf, 16);
		check_letter(s, st);
		len = ft_strlen(s);
		if (st->acc > len && (s_buf = ft_memalloc(st->acc - len)) != NULL)
		{
			s = fill_with_hex(st, s, s_buf, len);
			len = ft_strlen(s);
		}
		if (st->flag[0] != 'e')
		{
			if (st->flag[1] != 'e')
				ft_fwrite(0, &st->flag[1], 1);
		}
		hex_with_flags(st, s, len);
	}
}

void	do_for_ll_hex(t_all *st)
{
	unsigned long long	buf;
	char				*s;
	int					len;
	char				*s_buf;

	buf = (unsigned long long)va_arg(st->args, unsigned long long);
	if (buf == 0 && st->acc != -1)
		null_with_acc(st);
	else
	{
		s = ft_ll_itoa_base(buf, 16);
		check_letter(s, st);
		len = ft_strlen(s);
		if (st->acc > len && (s_buf = ft_memalloc(st->acc - len)) != NULL)
		{
			s = fill_with_hex(st, s, s_buf, len);
			len = ft_strlen(s);
		}
		if (st->flag[0] != 'e')
		{
			if (st->flag[1] != 'e')
				ft_fwrite(0, &st->flag[1], 1);
		}
		hex_with_flags(st, s, len);
	}
}

void	do_for_h_hex(t_all *st)
{
	unsigned short int	buf;
	char				*s;
	int					len;
	char				*s_buf;

	buf = (unsigned short int)va_arg(st->args, unsigned int);
	if (buf == 0 && st->acc != -1)
		null_with_acc(st);
	else
	{
		s = ft_ll_itoa_base(buf, 16);
		check_letter(s, st);
		len = ft_strlen(s);
		if (st->acc > len && (s_buf = ft_memalloc(st->acc - len)) != NULL)
		{
			s = fill_with_hex(st, s, s_buf, len);
			len = ft_strlen(s);
		}
		if (st->flag[0] != 'e')
		{
			if (st->flag[1] != 'e')
				ft_fwrite(0, &st->flag[1], 1);
		}
		hex_with_flags(st, s, len);
	}
}

void	do_for_hh_hex(t_all *st)
{
	unsigned int	buf;
	char			*s;
	int				len;
	char			*s_buf;

	buf = (unsigned int)va_arg(st->args, unsigned int);
	if (buf == 0 && st->acc != -1)
		null_with_acc(st);
	else
	{
		s = ft_ll_itoa_base(buf, 16);
		check_letter(s, st);
		len = ft_strlen(s);
		if (st->acc > len && (s_buf = ft_memalloc(st->acc - len)) != NULL)
		{
			s = fill_with_hex(st, s, s_buf, len);
			len = ft_strlen(s);
		}
		if (st->flag[0] != 'e')
		{
			if (st->flag[1] != 'e')
				ft_fwrite(0, &st->flag[1], 1);
		}
		hex_with_flags(st, s, len);
	}
}
