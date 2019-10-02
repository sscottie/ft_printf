/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_for_int.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sscottie <sscottie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/01 23:05:27 by sscottie          #+#    #+#             */
/*   Updated: 2019/10/01 19:36:26 by sscottie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	do_for_positive(t_all *st, char *s, int len)
{
	if (st->len != 0 && st->len > len && st->flag[1] == 'e')
		while (st->len-- - len > 0)
		{
			ft_fwrite(0, " ", 1);
			st->count++;	
		}
	else if (st->len != 0 && st->len > len && st->flag[1] != 'e')
		while (st->len-- - len > 1)
		{
			ft_fwrite(0, " ", 1);
			st->count++;
		}
	if (st->flag[1] != 'e')
	{
		ft_fwrite(0, &st->flag[1], 1);
		st->count++;	
	}
	ft_fwrite(0, s, len);
	st += len;
}

void	do_for_negative(t_all *st, char *s, int len)
{
	if (st->flag[0] == '-')
	{
		ft_fwrite(0, "-", 1);
		ft_fwrite(0, s, len);
		st->count += 2;
		while (--st->len - len > 0)
		{
			ft_fwrite(0, " ", 1);
			st->count++;
		}
	}
	else if (st->flag[0] == '0' && st->acc == -1)
	{
		ft_fwrite(0, "-", 1);
		while (--st->len - len > 0)
		{
			ft_fwrite(0, "0", 1);
			st->count++;
		}
		ft_fwrite(0, s, len);
		st->count += len + 1;
	}
	else
	{
		while (st->len-- - len > 1)
		{
			ft_fwrite(0, " ", 1);
			st->count++;
		}
		ft_fwrite(0, "-", 1);
		ft_fwrite(0, s, len);
		st->count += len + 1;
	}
}

void	int_with_flags(t_all *st, char *s, int len)
{
	if (st->flag[0] == '-')
	{
		if (st->flag[1] != 'e')
		{
			ft_fwrite(0, &st->flag[1], 1);
			st->count++;
			st->len--;
		}
		ft_fwrite(0, s, len);
		st->count += len;;
		while (st->len-- - len > 0)
		{
			ft_fwrite(0, " ", 1);
			st->count++;	
		}
	}
	else if (st->flag[0] == '0' && st->acc == -1)
	{
		if (st->flag[1] != 'e')
		{
			ft_fwrite(0, &st->flag[1], 1);
			st->len--;
			st->count++;
		}
		while (st->len-- - len > 0)
		{
			ft_fwrite(0, "0", 1);
			st->count++;	
		}
		ft_fwrite(0, s, len);
		st->count += len;
	}
	else
		do_for_positive(st, s, len);
}

void	do_for_int(t_all *st)
{
	int			buf;
	char		*s;
	int			len;
	char		*s_buf;
	int			minus;

	buf = (int)va_arg(st->args, int);
	if (buf == 0 && st->acc != -1)
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
