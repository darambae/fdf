/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   control_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dabae <dabae@student.42perpignan.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 09:34:52 by dabae             #+#    #+#             */
/*   Updated: 2024/03/28 08:35:06 by dabae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

void	zoom(int key, t_param *param)
{
	if (key == NUM_PLUS)
		param->scale += 1;
	else if (key == NUM_MINUS)
		param->scale -= 1;
	if (param->scale < 1)
		param->scale = 1;
}

void	move(int key, t_param *param)
{
	if (key == LEFT_KEY)
		param->x_offset -= 5;
	else if (key == RIGHT_KEY)
		param->x_offset += 5;
	else if (key == DOWN_KEY)
		param->y_offset += 5;
	else if (key == UP_KEY)
		param->y_offset -= 5;
}

void	rotate(int key, t_param *param)
{
	if (key == NUM_1 || key == MAIN_PAD_1)
		param->x_angle += 0.05;
	else if (key == NUM_4 || key == MAIN_PAD_4)
		param->x_angle -= 0.05;
	else if (key == NUM_5 || key == MAIN_PAD_5)
		param->y_angle += 0.05;
	else if (key == NUM_6 || key == MAIN_PAD_6)
		param->y_angle -= 0.05;
	else if (key == NUM_7 || key == MAIN_PAD_7)
		param->z_angle += 0.05;
	else if (key == NUM_8 || key == MAIN_PAD_8)
		param->z_angle -= 0.05;
	else if (key == NUM_0 || key == MAIN_PAD_0)
	{
		param->x_angle = 0;
		param->y_angle = 0;
		param->z_angle = 0;
	}
}

void	change_projection(int key, t_param *param)
{
	param->x_angle = 0;
	param->y_angle = 0;
	param->z_angle = 0;
	if (key == NUM_2)
	{
		param->is_iso = false;
		param->iso_angle = 0;
	}
	else if (key == NUM_3)
	{
		param->is_iso = true;
		param->iso_angle = 1;
	}
}
