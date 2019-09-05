/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sscottie <sscottie@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/24 21:26:05 by sscottie          #+#    #+#             */
/*   Updated: 2019/09/01 19:29:30 by sscottie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_printf(const char *fmt, ...)
{
	t_all		*st;
	int			len;

	if (!(st = (t_all*)malloc(sizeof(t_all))))
		return (-1);
	st->fmt = (char *)fmt;
	st->fmt_cp = st->fmt;
	st->i = 0;
	len = ft_strlen(st->fmt);
	st = init_st(st);
	if (fmt)
	{
		va_start(st->args, fmt);
		st->len = parse(st);
		va_end(st->args);
	}
	len = st->len;
	free(st);
	return (len);
}
