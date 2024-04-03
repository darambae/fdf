/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dabae <dabae@student.42perpignan.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 10:19:26 by dabae             #+#    #+#             */
/*   Updated: 2024/04/03 10:31:05 by dabae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

static t_map	projection(t_map a, t_param *param)
{
	a.x *= param->scale;
	a.y *= param->scale;
	a.z *= param->scale + param->z_scale;
	rotation_x(&a, param);
	rotation_y(&a, param);
	rotation_z(&a, param);
	if (param->is_iso)
		isometric(&a, param);
	a.x += param->x_offset;
	a.y += param->y_offset;
	return (a);
}

static void	my_mlx_pixel_put(t_param *param, int x, int y, int color)
{
	char	*dst;

	dst = param->data_addr + (y * param->line_len + x
			* (param->bits_per_pixel / 8));
	*(unsigned int *) dst = color;
}

static void	line(t_map a, t_map b, t_param *param)
{
	int		err[2];
	t_map	cur;

	err[0] = absolute(b.x - a.x) - absolute(b.y - a.y);
	cur = a;
	while ((int)(cur.x - b.x) || (int)(cur.y - b.y))		
	{
		if (cur.x > param->window_w || cur.y > param->window_l
			|| cur.y < 0 || cur.x < 0)
			break ;
		my_mlx_pixel_put(param, (int)cur.x, (int)cur.y, a.color);
		err[1] = 2 * err[0];
		if (err[1] >= -absolute(b.y - a.y))
		{
			err[0] += -absolute(b.y - a.y);
			cur.x += is_positive(b.x - a.x);
		}
		else if (err[1] <= absolute(b.x - a.x))
		{
			err[0] += absolute(b.x - a.x);
			cur.y += is_positive(b.y - a.y);
		}
	}
}

static void	print_menu(t_param *param)
{
	mlx_string_put(param->mlx, param->window, 20, 20,
		create_trgb(0, 50, 100, 205), "Zoom: +/-");
	mlx_string_put(param->mlx, param->window, 20, 40,
		create_trgb(0, 50, 100, 205), "Change height: H/L");
	mlx_string_put(param->mlx, param->window, 20, 60,
		create_trgb(0, 50, 100, 205), "Move: Arrows");
	mlx_string_put(param->mlx, param->window, 20, 80,
		create_trgb(0, 50, 100, 205), "Rotate in x-axis: 1/4");
	mlx_string_put(param->mlx, param->window, 20, 100,
		create_trgb(0, 50, 100, 205), "Rotate in y-axis: 5/6");
	mlx_string_put(param->mlx, param->window, 20, 120,
		create_trgb(0, 50, 100, 205), "Rotate in z-axis: 7/8");
	mlx_string_put(param->mlx, param->window, 20, 140,
		create_trgb(0, 50, 100, 205), "Switching 2D/3D: 2/3");
	mlx_string_put(param->mlx, param->window, 20, 160,
		create_trgb(0, 50, 100, 205), "Reset: 0");
	mlx_string_put(param->mlx, param->window, 20, 180,
		create_trgb(0, 50, 100, 205), "Exit: ESC");
}

void	drawlines(t_param *param)
{
	int		x;
	int		y;

	y = -1;
	while (++y < param->map_len)
	{
		x = -1;
		while (++x < param->map_max_wid && param->map[y][x].is_end_x == false)
		{
			if (x != param->map_max_wid - 1)
				line(projection(param->map[y][x], param),
					projection(param->map[y][x + 1], param), param);
			if (y != param->map_len - 1)
				line(projection(param->map[y][x], param),
					projection(param->map[y + 1][x], param), param);
		}
		if (x < param->map_max_wid && param->map[y][x].is_end_x == true)
		{
			if (y != param->map_len - 1)
				line(projection(param->map[y][x], param),
					projection(param->map[y + 1][x], param), param);
		}
	}
	mlx_put_image_to_window(param->mlx, param->window, param->img, 0, 0);
	print_menu(param);
}
