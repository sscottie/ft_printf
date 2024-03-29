/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_st.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sscottie <sscottie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/01 19:39:45 by sscottie          #+#    #+#             */
/*   Updated: 2019/09/06 03:30:41 by sscottie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	reinit_st(t_all *st)
{
	st->flag[0] = 'e';
	st->flag[1] = 'e';
	st->size = '\0';
	st->len = 0;
	st->acc = -1;
}

t_all	*init_st(t_all *st)
{
	st->flag[0] = 'e';
	st->flag[1] = 'e';
	st->flag[2] = 'e';
	st->size = '\0';
	st->len = 0;
	st->acc = -1;
	st->fmt_cp = st->fmt;
	st->count = 0;
	return (st);
}
