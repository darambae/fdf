/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dabae <dabae@student.42perpignan.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 14:51:19 by dabae             #+#    #+#             */
/*   Updated: 2024/03/27 09:56:33 by dabae            ###   ########.fr       */
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
	param->img = mlx_new_image(param->mlx, param->window_w, param->window_l);
	param->data_addr = mlx_get_data_addr(param->img, &(param->bits_per_pixel),
			&(param->line_len), &(param->endian));
	param->map_wid = 0;
	param->map_len = 0;
	param->is_iso = true;
	param->x_angle = 0;
	param->y_angle = 0;
	param->z_angle = 0;
	param->iso_angle = 1;
	param->scale = 20;
	param->x_offset = 0;
	param->y_offset = 0;
}

int	main(int ac, char **av)
{
	t_map	**map;
	t_param	*param;

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
		setting_controls(param);
		mlx_loop(param->mlx);
	}
	else
		err_msg_exit("Insufficient or too many arguments");
	return (EXIT_SUCCESS);
}