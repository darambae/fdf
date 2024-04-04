/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dabae <dabae@student.42perpignan.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 14:51:19 by dabae             #+#    #+#             */
/*   Updated: 2024/04/04 06:22:38 by dabae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf_bonus.h"

void	set_z_scale(t_param *param)
{
	float	ratio;

	ratio = param->window_l / (param->max_z - param->min_z);
	if (ratio < 1)
		param->z_scale = 0.7;
	else if (ratio < 2)
		param->z_scale = 1;
	else if (ratio < 4)
		param->z_scale = 1.7;
	else if (ratio < 6)
		param->z_scale = 2;
	else if (ratio < 8)
		param->z_scale = 3;
	else if (ratio < 15)
		param->z_scale = 5;
	else if (ratio >= 15)
		param->z_scale = 12;
}

void	get_scale(t_param *param)
{
	float	longer;

	if (param->map_len > param->map_max_wid)
		longer = param->map_len;
	else
		longer = param->map_max_wid;
	if (longer <= 10)
		param->scale = 50 * (param->window_w / 1000);
	else if (longer <= 20)
		param->scale = 28  * (param->window_w / 1000);
	else if (longer <= 30)
		param->scale = 20  * (param->window_w / 1000);
	else if (longer <= 50)
		param->scale = 11  * (param->window_w / 1000);
	else if (longer <= 100)
		param->scale = 4  * (param->window_w / 1000);
	else if (longer <= 200)
		param->scale = 2.7  * (param->window_w / 1000);
	else if (longer <= 300)
		param->scale = 2  * (param->window_w / 1000);
	else if (longer <= 500)
		param->scale = 1.15  * (param->window_w / 1000);
	else
		param->scale = 0.8  * (param->window_w / 1000);
}

static void	get_offset(t_param *param)
{
	param->x_offset = param->window_w / 2;
	param->y_offset = param->window_l / 4;
}

static void	set_default(t_param *param)
{
	param->window_w = 2000;
	param->window_l = 1400;
	param->mlx = mlx_init();
	param->window = mlx_new_window(param->mlx,
			param->window_w, param->window_l, "FDF");
	param->img = mlx_new_image(param->mlx, param->window_w, param->window_l);
	param->data_addr = mlx_get_data_addr(param->img, &(param->bits_per_pixel),
			&(param->line_len), &(param->endian));
	if (!param->mlx || !param->window || !param->img || !param->data_addr)
		close_window(param, 1);
	param->map = NULL;
	param->map_max_wid = 0;
	param->map_len = 0;
	param->is_iso = true;
	param->x_angle = 0;
	param->y_angle = 0;
	param->z_angle = 0;
	param->iso_angle = 0.5;
	param->z_scale = 1;
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
			close_window(param, 1);
		get_max_z(param);
		get_min_z(param);
		set_color(param);
		get_scale(param);
		set_z_scale(param);
		get_offset(param);
		drawlines(param);
		setting_controls(param);
		mlx_loop(param->mlx);
	}
	else
		err_msg_exit("Insufficient or too many arguments");
	return (EXIT_SUCCESS);
}
