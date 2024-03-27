/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotating.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dabae <dabae@student.42perpignan.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 09:51:21 by dabae             #+#    #+#             */
/*   Updated: 2024/03/26 14:24:22 by dabae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../fdf.h"

void	rotation_x(t_map *a, t_param *param)
{
	a->y = a->y * cos(param->x_angle) - a->z * sin(param->x_angle);
	a->z = a->y * sin(param->x_angle) + a->z * cos(param->x_angle);
}

void	rotation_y(t_map *a, t_param *param)
{
	a->x = a->x * cos(param->y_angle) + a->z * sin(param->y_angle);
	a->z = a->z * cos(param->y_angle) - a->x * sin(param->y_angle);
}

void	rotation_z(t_map *a, t_param *param)
{
	a->x = a->x * cos(param->z_angle) - a->y * sin(param->z_angle);
	a->y = a->y * sin(param->z_angle) + a->y * cos(param->z_angle);
}

void	isometric(t_map *a, t_param *param)
{
	a->x = (a->x - a->y) * cos(param->iso_angle);
	a->y = (a->x + a->y) * sin(param->iso_angle) - a->z;
}
