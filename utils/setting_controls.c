/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setting_controls.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dabae <dabae@student.42perpignan.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 07:02:41 by dabae             #+#    #+#             */
/*   Updated: 2024/04/02 11:09:52 by dabae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

static int	close_window(t_param *param)
{
	(void)param;
	exit(0);
}

static void	key_press(int key, t_param *param)
{
	if (key == MAIN_PAD_ESC)
	{
		free_map(param);
		mlx_destroy_window(param->mlx, param->window);
		exit(0);
	}
	if (key == NUM_PLUS
		|| key == NUM_MINUS)
		zoom(key, param);
	else if (key == LEFT_KEY || key == RIGHT_KEY
		|| key == UP_KEY || key == DOWN_KEY)
		move(key, param);
	else if (key == NUM_1 || key == NUM_4
		|| key == NUM_5 || key == NUM_6
		|| key == NUM_7 || key == NUM_8
		|| key == NUM_0 || key == MAIN_PAD_1
		|| key == MAIN_PAD_4 || key == MAIN_PAD_5
		|| key == MAIN_PAD_6 || key == MAIN_PAD_7
		|| key == MAIN_PAD_8 || key == MAIN_PAD_0)
		rotate(key, param);
	else if (key == NUM_3 || key == NUM_2)
		change_projection(key, param);
	else if (key == NUM_0 || key == MAIN_PAD_0)
		reset_camera(key, param);
}

static int	rerendering(int key, t_param *param)
{
	ft_bzero(param->data_addr, sizeof(int) * param->window_l * param->window_w);
	key_press(key, param);
	drawlines(param);
	return (0);
}

void	setting_controls(t_param *param)
{
	mlx_hook(param->window, 2, 1L << 0, rerendering, param);
	mlx_hook(param->window, 17, 0, close_window, param);
}
