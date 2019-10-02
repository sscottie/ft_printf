/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_for_u_int.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sscottie <sscottie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/01 23:05:27 by sscottie          #+#    #+#             */
/*   Updated: 2019/10/01 18:23:44 by sscottie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

void	u_int_with_flags(t_all *st, char *s, int len)
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

void	do_for_u_int(t_all *st)
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
		s = ft_itoa(buf);
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
