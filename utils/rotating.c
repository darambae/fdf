/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotating.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dabae <dabae@student.42perpignan.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 09:51:21 by dabae             #+#    #+#             */
/*   Updated: 2024/03/26 13:29:03 by dabae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../fdf.h"

void	rotation_x(t_map a, t_param *param)
{
	a.y = a.y * cos(param->angle) - a.z * sin(param->angle);
	a.z = a.y * sin(param->angle) + a.z * cos(param->angle);
}

void	rotation_y(t_map a, t_param *param)
{
	a.x = a.x * cos(param->angle) + a.z * sin(param->angle);
	a.z = a.z * cos(param->angle) - a.x * sin(param->angle);
}

void	rotation_z(t_map a, t_param *param)
{
	a.x = a.x * cos(param->angle) - a.y * sin(param->angle);
	a.y = a.y * sin(param->angle) + a.y * cos(param->angle);
}

void	isometric(t_map a, t_param *param)
{
	a.x = (a.x - a.y) * cos(param->angle);
	a.y = (a.x + a.y) * sin(param->angle) - a.z;
}
