/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_for_hex.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sscottie <sscottie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/04 23:50:38 by sscottie          #+#    #+#             */
/*   Updated: 2019/10/02 19:50:16 by sscottie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*fill_with_hex(t_all *st, char *s, char *s_buf, int len)
{
	s = ft_strcat(ft_memset(s_buf, '0', st->acc - len), s);
	if (st->flag[2] == '#')
	{
		s_buf = st->fmt_cp[st->i] == 'X' ? "0X\0" : "0x\0";
		s = ft_strcat(s_buf, s);
		free(s_buf);
	}
	return (s);
}

char	*check_letter(char *s, t_all *st)
{
	int	i;

	i = 0;
	if (st->fmt_cp[st->i] == 'x')
		while (s[i] != '\0')
		{
			s[i] = ft_tolower(s[i]);
			i++;
		}
	else if (st->fmt_cp[st->i] == 'X')
		while (s[i] != '\0')
		{
			s[i] = ft_toupper(s[i]);
			i++;
		}
	return (s);
}

void	hex_with_flags(t_all *st, char *s, int len)
{
	if (st->flag[0] == '-')
	{
		if (st->flag[1] != 'e')
		{
			ft_fwrite(0, &st->flag[1], 1);
			st->len--;
		}
		ft_fwrite(0, s, len);
		while (st->len-- - len > 0)
			ft_fwrite(0, " ", 1);
	}
	else if (st->flag[0] == '0' && st->acc == -1)
	{
		if (st->flag[1] != 'e')
		{
			ft_fwrite(0, &st->flag[1], 1);
			st->len--;
		}
		while (st->len-- - len > 0)
			ft_fwrite(0, "0", 1);
		ft_fwrite(0, s, len);
	}
	else
		do_for_positive(st, s, len);
}

void	do_for_hex(t_all *st)
{
	unsigned int	buf;
	char			*s;
	int				len;
	char			*s_buf;

	buf = (unsigned int)va_arg(st->args, void *);
	if (buf == 0 && st->acc != -1)
		null_with_acc(st);
	else
	{
		s = ft_itoa_base(buf, 16);
		s = check_letter(s, st);
		len = ft_strlen(s);
		if (st->acc > len && (s_buf = ft_memalloc(st->acc - len)) != NULL)
		{
			s = fill_with_hex(st, s, s_buf, len);
			len = ft_strlen(s);
		}
		if (st->flag[2] == '#' && (s_buf = ft_memalloc(2)) != NULL)
			s = ft_strcat(fill_with_hex(st, s, s_buf, len), s);
		hex_with_flags(st, s, len);
	}
}
