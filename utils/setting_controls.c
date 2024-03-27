/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setting_controls.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dabae <dabae@student.42perpignan.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 07:02:41 by dabae             #+#    #+#             */
/*   Updated: 2024/03/27 08:12:06 by dabae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

static void close(t_param *param)
{
    exit(0);
}

static void key_press(int key, t_param *param)
{
    if (key == MAIN_PAD_ESC)
}
void    setting_controls(t_param *param)
{
    mlx_hook(param->window, 2, 0, key_press, param);
    mlx_hook(param->window, 2, 0, close, param);
}
