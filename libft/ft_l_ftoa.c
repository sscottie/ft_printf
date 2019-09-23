/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_l_ftoa.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sscottie <sscottie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/16 00:41:48 by sscottie          #+#    #+#             */
/*   Updated: 2019/09/17 22:37:14 by sscottie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <math.h>

char	*ft_l_ftoa(long double n, int precision)
{
	char		*s;
	long long	tmp;
	long long	t;
	int			length;

	if (!precision)
		return (ft_itoa((int)ft_round(n, 0)));
	tmp = ft_round(n, precision);
	t = (tmp < 0) ? -tmp : tmp;
	length = (n < 0 ? 3 : 2);
	while (tmp /= 10)
		++length;
	(n < 1 && n > -1) ? length = 3 + precision : 0;
	(n >= 0 && n < 1) ? length = 2 + precision : 0;
	if (!(s = (char *)malloc(sizeof(char) * length)))
		return (NULL);
	s[length] = '\0';
	while (length--)
	{
		s[length] = (!precision--) ? '.' : t % 10 + '0';
		t /= (precision + 1) ? 10 : 1;
	}
	if (n < 0)
		s[0] = '-';
	return (s);
}