/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fwrite.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sscottie <sscottie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/01 19:10:32 by sscottie          #+#    #+#             */
/*   Updated: 2019/10/02 04:28:08 by sscottie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char			buf[SIZE];
static size_t		pos;
size_t				i;
git 
void	ft_fwrite_d(const char flag, const char *input, size_t len)
{
    if (flag == 0)
    {
        i = 0;
		if (*input == '0')
		{	
			buf[pos++] = input[i];
			return ;
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
        write(1, buf, pos);
}

void	ft_fwrite_c(const char flag, const char *input, size_t len)
{
    if (flag == 0)
    {
        i = 0;
		if (*input == '\0')
		{	
			buf[pos++] = input[i];
			return ;
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
        write(1, buf, pos);
}


int	ft_fwrite(const char flag, const char *input, size_t len)
{
    int count;
	int iter;
	
	iter = 0;
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
		return (count);
	}
	return (0);
}
