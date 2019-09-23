/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ftoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sscottie <sscottie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/16 00:41:48 by sscottie          #+#    #+#             */
/*   Updated: 2019/09/17 17:54:46 by sscottie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// C program for implementation of ftoa()
#include "libft.h"
#include <math.h>

// double	ft_round(double d, int pres)
// {
// 	int negative;
// 	int count = 1;
// 	negative = d >= 0 ? 1 : -1;
// 	d = fabs(d);
// 	long ipart = (long)d;
// 	double fpart = (double) d - (double) ipart;
// 	double p = pow(10, pres + 1);
//     long int buf = fpart * p;
// 	while ((long int)(buf * 10 / count) % 10 >= 5)
// 	{
// 		if ((long int)(buf / count) % 2 == 1)
// 		{
// 			buf += count;
// 			count *= 10;	
// 		}
//         else
//             break ;
// 	}
// 	return (negative * (ipart + (double)(buf / p)));
// }
// // reverses a string 'str' of length 'len'
// static void reverse(char *str, int len)
// {
//     int i=0, j=len-1, temp;
//     while (i<j)
//     {
//         temp = str[i];
//         str[i] = str[j];
//         str[j] = temp;
//         i++; j--;
//     }
// }
 
//  // Converts a given integer x to string str[].  d is the number
//  // of digits required in output. If d is more than the number
//  // of digits in x, then 0s are added at the beginning.
// static int intToStr(int x, char str[], int d)
// {
//     int i = 0;
//     while (x)
//     {
//         str[i++] = (x % 10) + '0';
//         x = x / 10;
//     }
 
//     // If number of digits required is more, then
//     // add 0s at the beginning
//     while (i < d)
//         str[i++] = '0';
 
//     reverse(str, i);
//     str[i] = '\0';
//     return i;
// }
 
// // Converts a floating point number to string.
// char *ft_ftoa(double n, char *res, int afterpoint)
// {    // Extract integer part
//     char *zero = "0\0";
//     int ipart = (int)n;
 
//     // Extract floating part
//     float fpart = n - (float)ipart;
 
//     // convert integer part to string
//     int i = intToStr(ipart, res, 0);
 
//     // check for display option after point
//     if (afterpoint != 0)
//     {
//         res[i] = '.';  // add dot
 
//         // Get the value of fraction part upto given no.
//         // of points after dot. The third parameter is needed
//         // to handle cases like 233.007
//         fpart = fpart * pow(10, afterpoint);
 
//         intToStr((int)fpart, res + i + 1, afterpoint);
//     }
//     if (n < 1)
// 		res = ft_strjoin(zero, res);
//     return (res);
// }

char	*ft_ftoa(double n, int precision)
{
	char	*s;
	long	tmp;
	long	t;
	int 	length;

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