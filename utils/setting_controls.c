/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setting_controls.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dabae <dabae@student.42perpignan.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 07:02:41 by dabae             #+#    #+#             */
/*   Updated: 2024/03/27 10:13:59 by dabae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

static void	close(t_param *param)
{
	(void)param;
	exit(0);
}

static void	key_press(int key, t_param *param, t_map **map)
{
	if (key == MAIN_PAD_ESC)
	{
		ft_free_tab(map);
		exit(0);
	}
	if (key == NUM_PLUS || key == MAIN_PAD_PLUS
		|| key == NUM_MINUS || key == MAIN_PAD_MINUS)
		zoom(key, param, map);
	else if (key == LEFT_KEY || key == RIGHT_KEY
		|| key == UP_KEY || key == DOWN_KEY)
		move(key, param, map);
	else if (key == NUM_1 || key == NUM_4
		|| key == NUM_5 || key == NUM_6
		|| key == NUM_7 || key == NUM_8
		|| key == NUM_0 || key == MAIN_PAD_1
		|| key == MAIN_PAD_4 || key == MAIN_PAD_5
		|| key == MAIN_PAD_6 || key == MAIN_PAD_7
		|| key == MAIN_PAD_8 || key == MAIN_PAD_0)
		rotate(key, param, map);
	else if (key == NUM_3 || key == NUM_2)
		change_projection(key, param, map);
}

void	setting_controls(t_param *param)
{
	mlx_hook(param->window, 2, 0, key_press, param);
	mlx_hook(param->window, 17, 0, close, param);
}
