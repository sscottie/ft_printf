/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_for_sized_u.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sscottie <sscottie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/06 01:03:10 by sscottie          #+#    #+#             */
/*   Updated: 2019/09/06 04:18:15 by sscottie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	do_for_l_uns(t_all *st)
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
		s = ft_l_itoa(buf);
		len = ft_strlen(s);
		if (st->acc > len && (s_buf = ft_memalloc(st->acc - len)) != NULL)
		{
			s = ft_strcat(ft_memset(s_buf, '0', st->acc - len), s);
			len = ft_strlen(s);
			free(s_buf);
		}
		if (st->flag[0] != 'e')
		{
			if (st->flag[1] != 'e')
				write(1, &st->flag[1], 1);
		}
		u_int_with_flags(st, s, len);
	}
}

void	do_for_ll_uns(t_all *st)
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
		s = ft_ll_itoa(buf);
		len = ft_strlen(s);
		if (st->acc > len && (s_buf = ft_memalloc(st->acc - len)) != NULL)
		{
			s = ft_strcat(ft_memset(s_buf, '0', st->acc - len), s);
			len = ft_strlen(s);
			free(s_buf);
		}
		if (st->flag[0] != 'e')
		{
			if (st->flag[1] != 'e')
				write(1, &st->flag[1], 1);
		}
		u_int_with_flags(st, s, len);
	}
}

void	do_for_h_uns(t_all *st)
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
		s = ft_ll_itoa(buf);
		len = ft_strlen(s);
		if (st->acc > len && (s_buf = ft_memalloc(st->acc - len)) != NULL)
		{
			s = ft_strcat(ft_memset(s_buf, '0', st->acc - len), s);
			len = ft_strlen(s);
			free(s_buf);
		}
		if (st->flag[0] != 'e')
		{
			if (st->flag[1] != 'e')
				write(1, &st->flag[1], 1);
		}
		u_int_with_flags(st, s, len);
	}
}

void	do_for_hh_uns(t_all *st)
{
	int			buf;
	char		*s;
	int			len;
	char		*s_buf;

	buf = (int)va_arg(st->args, unsigned int);
	if (buf == '0' && st->acc != -1)
		null_with_acc(st);
	else
	{
		s = ft_ll_itoa(llabs(buf));
		len = ft_strlen(s);
		if (st->acc > len && (s_buf = ft_memalloc(st->acc - len)) != NULL)
		{
			s = ft_strcat(ft_memset(s_buf, '0', st->acc - len), s);
			len = ft_strlen(s);
			free(s_buf);
		}
		if (st->flag[0] != 'e')
		{
			if (st->flag[1] != 'e')
				write(1, &st->flag[1], 1);
		}
		u_int_with_flags(st, s, len);
	}
}
