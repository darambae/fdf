/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dabae <dabae@student.42perpignan.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 15:14:16 by dabae             #+#    #+#             */
/*   Updated: 2024/03/25 08:34:19 by dabae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "mlx_linux/mlx.h"
# include <stdlib.h>
# include <stdbool.h>
# include <stdio.h>
# include <math.h>
# include <errno.h>
# include "get_next_line/get_next_line.h"
# include "libft/libft.h"

typedef struct s_map
{
	float	x;
	float	y;
	float	z;
	bool	is_end;
	int		color;
}				t_map;

typedef struct	s_param
{
	void	*mlx;
	void	*window;

	int		map_len;
	int		map_wid;
	int		window_l;
	int		window_w;
	int		scale;
	int		is_iso;
	double	angle;
	int		img_len;
	int		img_width;
}				t_param;

float	absolute(float a);
float	bigger(float a, float b);
void	err_msg_exit(char *err_msg);
t_map	**parse_map(char *filename, t_param *param);
int		create_trgb(int t, int r, int g, int b);
void	drawlines(t_map **map, t_param *param);
#endif