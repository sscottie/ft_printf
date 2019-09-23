/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sscottie <sscottie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/24 21:54:14 by sscottie          #+#    #+#             */
/*   Updated: 2019/09/19 03:34:59 by sscottie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		pre_format(t_all *st)
{
	st->i++;
	fill_flags(st);
	if (st->fmt_cp[st->i] == 'c' || st->fmt_cp[st->i] == 'C')
		do_for_char(st);
	else if (st->fmt_cp[st->i] == '%')
		do_for_percent(st);
	else if (st->fmt_cp[st->i] == 's' || st->fmt_cp[st->i] == 'S')
		do_for_string(st);
	else if (st->fmt_cp[st->i] == 'p')
		do_for_pointer(st);
	else if (st->fmt_cp[st->i] == 'u')
		crossroad_for_u(st);
	else if (st->fmt_cp[st->i] == 'd' || st->fmt_cp[st->i] == 'i'
				|| st->fmt_cp[st->i] == 'D')
		crossroad_for_int(st);
	else if (st->fmt_cp[st->i] == 'o')
		crossroad_for_oct(st);
	else if (st->fmt_cp[st->i] == 'x' || st->fmt_cp[st->i] == 'X')
		crossroad_for_hex(st);
	else if (st->fmt_cp[st->i] == 'f' || st->fmt_cp[st->i] == 'F')
		crossroad_for_floats(st);
	return (0);
}

int		parse(t_all *st)
{
	int	i;

	i = ft_strnchr(st->fmt_cp, '%');
	if (i == -1)
	{
		write(1, st->fmt_cp, ft_strlen(st->fmt_cp));
		return (0);
	}
	else
		while (st->fmt_cp[st->i] != '\0')
		{
			if (st->fmt_cp[st->i] == '%' && st->fmt_cp[st->i + 1] != '\0')
			{
				pre_format(st);
				reinit_st(st);
			}
			else if (st->fmt_cp[st->i] == '%' && st->fmt_cp[st->i + 1] == '\0')
				return (0);
			else
				write(1, &st->fmt_cp[st->i], 1);
			st->i++;
		}
	return (st->count);
}
