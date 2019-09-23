/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_for_null.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sscottie <sscottie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/05 20:52:14 by sscottie          #+#    #+#             */
/*   Updated: 2019/09/07 23:50:21 by sscottie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	null_no_flags(t_all *st)
{
	while (st->len-- - st->acc > 1)
		write(1, " ", 1);
	if (st->flag[1] == '+')
		write(1, "+", 1);
	else
		write(1, " ", 1);
	while (st->acc-- > 0)
		write(1, "0", 1);
}

static void	pointer_no_flags(t_all *st)
{
	while (st->len-- - st->acc > 2)
		write(1, " ", 1);
	write(1, "0x", 2);
	while (st->acc-- > 0)
		write(1, "0", 1);
}

void		null_with_acc(t_all *st)
{
	int i;

	i = 0;
	if (st->len == 0 && st->acc == 0 && st->flag[1] == 'e')
		exit(EXIT_FAILURE);
	else if (st->len <= st->acc)
	{
		if (st->flag[1] != 'e')
			write(1, &st->flag[1], 1);
		while (st->acc-- > 0)
			write(1, "0", 1);
	}
	else if (st->len > st->acc)
	{
		if (st->flag[0] == '-')
		{
			if (st->flag[1] != 'e')
			{
				write(1, &st->flag[1], 1);
				st->len--;
			}
			while (st->acc - i++ > 0)
				write(1, "0", 1);
			while (st->len-- - st->acc > 0)
				write(1, " ", 1);
		}
		else
			null_no_flags(st);
	}
}

void		null_p_with_acc(t_all *st)
{
	int i;

	i = 0;
	if (st->len == 0 && st->acc == 0 && st->flag[1] == 'e')
		write(1, "0x", 2);
	else if (st->len <= st->acc)
	{
		write(1, "0x", 2);
		while (st->acc-- > 0)
			write(1, "0", 1);
	}
	else if (st->len > st->acc)
	{
		if (st->flag[0] == '-')
		{
			write(1, "0x", 2);
			while (st->acc - i++ > 0)
				write(1, "0", 1);
			while (st->len-- - st->acc > 0)
				write(1, " ", 1);
		}
		else
			pointer_no_flags(st);
	}
}
