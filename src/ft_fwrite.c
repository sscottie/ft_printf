/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fwrite.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sscottie <sscottie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/01 19:10:32 by sscottie          #+#    #+#             */
/*   Updated: 2019/10/02 19:46:44 by sscottie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char			buf[SIZE];
static size_t		pos;
size_t				i;

int	ft_fwrite_c(const char flag, const char *input, size_t len)
{
    int count;
    
    if (flag == 0)
    {
        i = 0;
		if (*input == '\0')
		{	
			buf[pos++] = input[i];
			return (0);
		}
		while (*input && i < len )
        {
            buf[pos++] = input[i++];
            if (pos == SIZE)
            {
                write(1, buf, pos);
                pos = 0;
            }
        }
    }
    else
    {
        count = ft_strlen(buf);
		write(1, buf, pos);
        ft_bzero(buf, pos);
        pos = 0;
		return (count);
    }
	return (0);
}


int	ft_fwrite(const char flag, const char *input, size_t len)
{
    int count;

	if (flag == 0)
    {
        i = 0;
		while (*input && i < len )
        {
            buf[pos++] = input[i++];
            if (pos == SIZE)
            {
                write(1, buf, pos);
                pos = 0;
            }
        }
    }
    else
    {
		count = ft_strlen(buf);
		write(1, buf, pos);
        ft_bzero(buf, pos);
        pos = 0;
		return (count);
	}
	return (0);
}
