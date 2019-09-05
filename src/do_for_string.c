/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_for_string.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sscottie <sscottie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/26 17:49:10 by sscottie          #+#    #+#             */
/*   Updated: 2019/09/04 16:27:34 by sscottie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	string_with_flags(t_all *st, char *s, int len)
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
		write(1, s, len);
	}
}

void	do_for_string(t_all *st)
{
	int		len;
	char	*s;
	char	*buf;

	s = NULL;
	buf = va_arg(st->args, char *);
	if (!buf)
		buf = "(null)";
	if (st->acc < (int)ft_strlen(buf) && st->acc != -1)
	{
		s = (char *)malloc(sizeof(char *));
		s = ft_strncpy(s, buf, st->acc);
	}
	else
		s = buf;

	len = strlen(s);
	if ((st->len == 0 || st->len <= len) && st->flag[0] == 'e')
		write(1, s, len);
	else
		string_with_flags(st, s, len);
	// if (s)
	// 	free(s);
}
