/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dabae <dabae@student.42perpignan.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 10:19:26 by dabae             #+#    #+#             */
/*   Updated: 2024/03/27 05:50:41 by dabae            ###   ########.fr       */
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
	a.x *= param->scale;
	a.y *= param->scale;
	a.z *= 2;
	rotation_x(&a, param);
	rotation_y(&a, param);
	rotation_z(&a, param);
	if (param->is_iso)
		isometric(&a, param);
	a.x += (param->window_w / 3);
	a.y += (param->window_l / 3);
	return (a);
}

static void	my_mlx_pixel_put(t_param *param, int x, int y, int color)
{
	char	*dst;

	dst = param->data_addr + (y * param->line_len + x * (param->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

static void	line(t_map a, t_map b, t_param *param)
{
	float	dx;
	float	dy;
	t_map	cur;
	int		err[2];

	dx = absolute(b.x - a.x);
	dy = -absolute(b.y - a.y);
	err[0] = dx + dy;
	cur = a;
	while ((int)(cur.x - b.x) || (int)(cur.y - b.y))
	{
		if (cur.x > param->window_w || cur.y > param->window_l || cur.y < 0 || cur.x < 0)
			break ;
		my_mlx_pixel_put(param, (int)cur.x, (int)cur.y, color(cur.z, b.z));
		err[1] = 2 * err[0];
		if (err[1] >= dy)
		{
			err[0] += dy;
			cur.x += is_positive(b.x - a.x);
		}
		else if (err[1] <= dx)
		{
			err[0] += dx;
			cur.y += is_positive(b.y - a.y);
		}
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
				line(projection(map[y][x], param), projection(map[y][x + 1], param), param);
			if (y != param->map_len - 1)
				line(projection(map[y][x], param), projection(map[y + 1][x], param), param);
		}
	}
	mlx_put_image_to_window(param->mlx, param->window, param->img, 0, 0);
}
