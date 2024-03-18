/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dabae <dabae@student.42perpignan.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 14:51:19 by dabae             #+#    #+#             */
/*   Updated: 2024/03/18 11:05:22 by dabae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	set_default(t_param *param)
{
	param->window_w = 1920;
	param->window_l = 1000;
	param->mlx = mlx_init();
	param->window = mlx_new_window(param->mlx, param->window_w, param->window_l, "FDF");

}

// void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
// {
// 	char	*dst;

// 	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
// 	*(unsigned int*)dst = color;
// }



int	main(int ac, char **av)
{
	t_map	**map;
	t_param	*param;
	
	/*Pseudo code*/
	if (ac == 2)
	{
		parse_map(av[1], map);
		set_default(param);
		line_drawing_algorithm(map);
		drawline(map);
	}
	else
		err_msg_exit("Insufficient or too many arguments");
	return (EXIT_SUCCESS);
}