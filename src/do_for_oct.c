/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_for_oct.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sscottie <sscottie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/04 23:38:41 by sscottie          #+#    #+#             */
/*   Updated: 2019/09/04 23:51:11 by sscottie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	oct_with_flags(t_all *st, char *s, int len)
{
	if (st->flag[0] == '-')
	{
		write(1, s, len);
		while (st->len-- - len > 0)
			write(1, " ", 1);
	}
	else if (st->flag[0] == '0')
	{
		while (st->len-- - len > 0)
			write(1, "0", 1);
		write(1, s, len);
	}
	else
	{
		while (st->len-- - len > 0)
			write(1, " ", 1);
		if (st->flag[1] != 'e')
		{
			write(1, " ", 1);
			write(1, &st->flag[1], 1);
		}
		write(1, s, len);
	}
}

void	do_for_oct(t_all *st)
{
	int			buf;
	char		*s;
	int			len;
	char		*s_buf;

	buf = (int)va_arg(st->args, unsigned int);
	s = ft_itoa_base(abs(buf), 8);
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
	oct_with_flags(st, s, len);
}
