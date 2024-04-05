/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setting_controls.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dabae <dabae@student.42perpignan.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 14:16:36 by dabae             #+#    #+#             */
/*   Updated: 2024/04/03 14:48:45 by dabae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

/*When ESC or X button is pressed, free all with or without error case*/
int	close_window(t_param *param, int is_error)
{
	if (is_error != 1)
		is_error = 0;
	free_map(param);
	mlx_destroy_image(param->mlx, param->img);
	mlx_destroy_window(param->mlx, param->window);
	mlx_destroy_display(param->mlx);
	free(param->mlx);
	free(param);
	if (is_error == 1)
		err_msg_exit("Error");
	exit(is_error);
}

static int	key_press(int key, t_param *param)
{
	if (key == MAIN_PAD_ESC)
		close_window(param, 0);
	return (0);
}

void	setting_controls(t_param *param)
{
	mlx_hook(param->window, 2, 1L << 0, key_press, param);
	mlx_hook(param->window, 17, 0, close_window, param);
}
