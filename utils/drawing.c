/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dabae <dabae@student.42perpignan.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 10:19:26 by dabae             #+#    #+#             */
/*   Updated: 2024/03/18 11:06:52 by dabae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

void	drawline(t_map **map, t_param *param)
{
	float	dx;
	float	dy;
	float	p;
    
	dx = map->-x0;  
    dy = y1-y0;  
    x = x0;  
    y = y0;
    p = 2 * dy - dx;  
    while (x < x1)  
    {
		if(p>=0)  
		{  
			mlx_pixel_put();  
            y++; 
            p=p+2*dy-2*dx;  
        }  
        else  
        {  
            putpixel(x,y,7);  
            p=p+2*dy;
		}  
        x++;  
    }  
}  