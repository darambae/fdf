/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dabae <dabae@student.42perpignan.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 14:51:19 by dabae             #+#    #+#             */
/*   Updated: 2024/03/25 08:42:53 by dabae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	set_default(t_param *param)
{
	param->window_w = 1000;
	param->window_l = 700;
	param->mlx = mlx_init();
	param->window = mlx_new_window(param->mlx,
			param->window_w, param->window_l, "FDF");
	param->map_wid = 0;
	param->map_len = 0;
	param->is_iso = true;
	param->angle = 0.523599;
	param->scale = 20;
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
		map = NULL;
		param = (t_param *)malloc(sizeof(t_param));
		if (!param)
			err_msg_exit("Memory allocation failed");
		set_default(param);
		map = parse_map(av[1], param);
		if (!map)
			err_msg_exit("Reading map failed");
		drawlines(map, param);
		mlx_loop(param->mlx);
	}
	else
		err_msg_exit("Insufficient or too many arguments");
	return (EXIT_SUCCESS);
}