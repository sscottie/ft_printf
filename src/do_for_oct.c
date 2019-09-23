/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_for_oct.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sscottie <sscottie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/04 23:38:41 by sscottie          #+#    #+#             */
/*   Updated: 2019/09/19 04:31:03 by sscottie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*fill_with_oct(t_all *st, char *s, char *s_buf, int len)
{
	char *s_res;
	
	s_res = (char *)ft_memalloc(sizeof((s) + 1));
	if (st->acc != -1)
		s = ft_strcat(ft_memset(s_buf, '0', st->acc - len), s);
	s_res = s;
	if (st->flag[2] == '#')
		s_res = ft_strcat("0", s);
	return (s_res);
}

void	oct_with_flags(t_all *st, char *s, int len)
{
	if (st->flag[0] == '-')
	{
		if (st->flag[1] != 'e')
		{
			write(1, &st->flag[1], 1);
			st->len--;
		}
		write(1, s, len);
		while (st->len-- - len > 0)
			write(1, " ", 1);
	}
	else if (st->flag[0] == '0' && st->acc == -1)
	{
		if (st->flag[1] != 'e')
		{
			write(1, &st->flag[1], 1);
			st->len--;
		}
		while (st->len-- - len > 0)
			write(1, "0", 1);
		write(1, s, len);
	}
	else
		do_for_positive(st, s, len);
}

void	do_for_oct(t_all *st)
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
		s = ft_l_itoa_base(buf, 8);
		len = ft_strlen(s);
		if (st->acc > len && (s_buf = ft_memalloc(st->acc - len)) != NULL)
		{
			s = fill_with_oct(st, s, s_buf, len);
			len = ft_strlen(s);
		}
		if (st->flag[2] == '#' && (s_buf = ft_memalloc(2)) != NULL)
			s = ft_strcat(fill_with_oct(st, s, s_buf, len), s);
		if (st->flag[0] != 'e')
		{
			if (st->flag[1] != 'e')
				write(1, &st->flag[1], 1);
		}
		oct_with_flags(st, s, len);
	}
}
