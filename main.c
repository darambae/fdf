/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dabae <dabae@student.42perpignan.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 14:51:19 by dabae             #+#    #+#             */
/*   Updated: 2024/04/02 13:20:46 by dabae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

float	get_scale(t_param *param)
{
	int	scale;

	scale = 0;
	if (param->map_len > param->map_wid)
		scale = param->window_l / param->map_len / 2;
	else
		scale = param->window_w / param->map_wid / 2;
	return (scale);
}

static void	get_offset(t_param *param)
{
	param->x_offset = param->window_w / 2;
	param->y_offset = (param->window_l - param->map_len * param->scale) / 2;
}

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
	if (!param->mlx || !param->window || !param->img || !param->data_addr)
	{
		close_window(param);
		err_msg_exit("mlxlibx failed");
	}
	param->map = NULL;
	param->map_wid = 0;
	param->map_len = 0;
	param->is_iso = true;
	param->x_angle = 0;
	param->y_angle = 0;
	param->z_angle = 0;
	param->iso_angle = 0.5;
	param->z_scale = 0;
}

int	main(int ac, char **av)
{
	t_param	*param;

	if (ac == 2)
	{
		param = (t_param *)malloc(sizeof(t_param));
		if (!param)
			err_msg_exit("Memory allocation failed");
		set_default(param);
		parse_map(av[1], param);
		if (!param->map)
			err_msg_exit("Reading map failed");
		get_max_z(param);
		get_min_z(param);
		set_color(param);
		param->scale = get_scale(param);
		get_offset(param);
		drawlines(param);
		setting_controls(param);
		mlx_loop(param->mlx);
	}
	else
		err_msg_exit("Insufficient or too many arguments");
	return (EXIT_SUCCESS);
}
