/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dabae <dabae@student.42perpignan.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 10:19:26 by dabae             #+#    #+#             */
/*   Updated: 2024/03/26 07:51:04 by dabae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

static int	color(float a, float b)
{
	int	color;

	if (a > 0 || b > 0)
		color = 0xff00aa;
	else
		color = 0x00ffaa;
	return (color);
}

static t_map	projection(t_map a, t_param *param)
{
	a->x *= param->scale;
	a->y *= param->scale;
	rotation_x(a, param);
	rotation_y(a, param);
	rotation_z(a, param);
	if (param->is_iso)
		isometric(a, param);
	a->x += (param->window_w / 4);
	a->y += (param->window_l / 4);
	return (a);
}

static void	line(t_map a, t_map b, t_param *param)
{
	float	dx;
	float	dy;
	float	p;

	dx = b.x - a.x;
	dy = b.y - a.y;
	p = 2 * dy - dx;
	while (a.x <= b.x && a.y <= b.y)
	{
		if (p >= 0)
		{
			mlx_pixel_put(param->mlx, param->window, (int)a.x, (int)a.y, color(a.z, b.z));
			a.y += absolute(dy) / bigger(absolute(dx), absolute(dy));
			p += 2 * dy - 2 * dx;
		}
		else
		{
			mlx_pixel_put(param->mlx, param->window, (int)a.x, (int)a.y, color(a.z, b.z));
			p += 2 * dy;
		}
		a.x += absolute(dx) / bigger(absolute(dx), absolute(dy));
	}
}

void	drawlines(t_map **map, t_param *param)
{
	int		x;
	int		y;

	y = -1;
	while (++y < param->map_len)
	{
		x = -1;
		while (++x < param->map_wid)
		{
			if (x != param->map_wid - 1)
				line(projection(map[y][x]), projection(map[y][x + 1]), param);
			if (y != param->map_len - 1)
				line(projection(map[y][x]), projection(map[y + 1][x]), param);
		}
	}
}
	