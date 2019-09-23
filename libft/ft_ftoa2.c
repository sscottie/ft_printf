/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ftoa2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sscottie <sscottie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/17 22:24:27 by sscottie          #+#    #+#             */
/*   Updated: 2019/09/17 22:26:06 by sscottie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int powk(int x, unsigned int y)
{
    if( y == 0)
        return 1;
    else if (y%2 == 0)
        return powk(x, y/2)*powk(x, y/2);
    else
        return x*powk(x, y/2)*powk(x, y/2);
 
}
 

void ftoa(float flt, int after_point)
{
    int int_flt = (int) flt;
	printf("%d" , int_flt);
	printf(".");
	
	int mut_ab = powk(10,after_point);
    int after_point_flt = (int) (flt * mut_ab); //33314
    
    int multiplier = powk(10,(after_point-1));
	//printf("MULTIPLIER : %d\n" , multiplier);
    for(int xy=0; xy<after_point; xy++)
    {
        int muted = (after_point_flt/multiplier);
		//printf("%d\n",muted);
        muted = muted % 10;
        printf("%d", muted);
        
        multiplier/=10;
    }
	
	//printf("%d", after_point_flt);
	
}