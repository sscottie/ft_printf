/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_for_pointer.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sscottie <sscottie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/04 23:50:38 by sscottie          #+#    #+#             */
/*   Updated: 2019/09/19 08:03:08 by sscottie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	do_for_point(t_all *st, char *s, int len)
{
	if (st->len != 0 && st->len > len)
		while (st->len-- - len > 0)
			write(1, " ", 1);
	else if (st->len != 0 && st->len > len)
		while (st->len-- - len > 1)
			write(1, " ", 1);
	write(1, "0x10", 4);
	write(1, s, len);
}

// static char	*fill_with_address(t_all *st, char *s, char *s_buf, int len)
// {
// 	s = ft_strcat(ft_memset(s_buf, '0', st->acc - len), s);
// 	free(s_buf);
// 	return (s);
// }

static char	*do_lowcase(char *s)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
	{
		s[i] = ft_tolower(s[i]);
		i++;
	}
	return (s);
}

static void	pointer_with_flags(t_all *st, char *s, int len)
{
	if (st->flag[0] == '-')
	{
		write(1, "0x10", 4);
		write(1, s, len);
		while (st->len-- - len > 0)
			write(1, " ", 1);
	}
	else if (st->flag[0] == '0' && st->acc == -1)
	{
		write(1, "0x10", 4);
		write(1, s, len);
		while (st->len-- - len > 0)
			write(1, "0", 1);
	}
	else
		do_for_point(st, s, len);
}

void		do_for_pointer(t_all *st)
{
	unsigned long long	buf;
	char				*s;
	int					len;
	// char				*s_buf;

	buf = (unsigned long long)va_arg(st->args, void *);
	if (buf == 0 && st->acc != -1)
		null_p_with_acc(st);
	else if (buf == 0 && st->flag[0] == 'e' && st->len == 0 && st->acc == -1)
		write(1, "0x0", 3);
	else
	{
		s = ft_itoa_base(buf, 16);
		s = do_lowcase(s);
		len = ft_strlen(s);
		// if (st->acc > len && (s_buf = ft_memalloc(st->acc - len)) != NULL)
		// {
		// 	s = fill_with_address(st, s, s_buf, len);
		// 	len = ft_strlen(s);
		// }
		pointer_with_flags(st, s, len);
	}
}
