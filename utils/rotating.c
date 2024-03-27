/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotating.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dabae <dabae@student.42perpignan.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 09:51:21 by dabae             #+#    #+#             */
/*   Updated: 2024/03/27 13:28:35 by dabae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../fdf.h"

void	rotation_x(t_map *a, t_param *param)
{
	t_map	prev;

	prev = *a;
	a->y = prev.y * cos(param->x_angle) - prev.z * sin(param->x_angle);
	a->z = prev.y * sin(param->x_angle) + prev.z * cos(param->x_angle);
}

void	rotation_y(t_map *a, t_param *param)
{
	t_map	prev;

	prev = *a;
	a->x = prev.x * cos(param->y_angle) + prev.z * sin(param->y_angle);
	a->z = prev.z * cos(param->y_angle) - prev.x * sin(param->y_angle);
}

void	rotation_z(t_map *a, t_param *param)
{
	t_map	prev;

	prev = *a;
	a->x = prev.x * cos(param->z_angle) - prev.y * sin(param->z_angle);
	a->y = prev.y * sin(param->z_angle) + prev.y * cos(param->z_angle);
}

void	isometric(t_map *a, t_param *param)
{
	t_map	prev;

	prev = *a;
	a->x = (prev.x - prev.y) * cos(param->iso_angle);
	a->y = (prev.x + prev.y) * sin(param->iso_angle) - prev.z;
}
