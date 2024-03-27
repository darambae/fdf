/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dabae <dabae@student.42perpignan.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 15:14:16 by dabae             #+#    #+#             */
/*   Updated: 2024/03/27 08:05:16 by dabae            ###   ########.fr       */
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

# define LEFT_KEY	123
# define RIGHT_KEY	124
# define UP_KEY		126
# define DOWN_KEY	125

# define NUM_0			82
# define NUM_1			83
# define NUM_2			84
# define NUM_3			85
# define NUM_4			86
# define NUM_5			87
# define NUM_6			88
# define NUM_7			89
# define NUM_8			91
# define NUM_9			92
# define NUM_PLUS		69
# define NUM_MINUS		78

# define MAIN_PAD_ESC		53
# define MAIN_PAD_I			34
# define MAIN_PAD_P			35
# define MAIN_PAD_0			29
# define MAIN_PAD_1			18
# define MAIN_PAD_2			19
# define MAIN_PAD_3			20
# define MAIN_PAD_4			21
# define MAIN_PAD_5			23
# define MAIN_PAD_6			22
# define MAIN_PAD_7			26
# define MAIN_PAD_8			28
# define MAIN_PAD_9			25
# define MAIN_PAD_PLUS		24
# define MAIN_PAD_MINUS		27
# define MAIN_PAD_LESS		43
# define MAIN_PAD_MORE		47

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
	void	*img;
	char	*data_addr;
	int		bits_per_pixel;
	int		line_len;
	int		endian;
	int		map_len;
	int		map_wid;
	int		window_l;
	int		window_w;
	int		scale;
	int		is_iso;
	double	x_angle;
	double	y_angle;
	double	z_angle;	
	double	iso_angle;
	int		img_len;
	int		img_width;
}				t_param;

float	absolute(float a);
int		is_positive(float a);
void	err_msg_exit(char *err_msg);
t_map	**parse_map(char *filename, t_param *param);
int		create_trgb(int t, int r, int g, int b);
void	rotation_x(t_map *a, t_param *param);
void	rotation_y(t_map *a, t_param *param);
void	rotation_z(t_map *a, t_param *param);
void	isometric(t_map *a, t_param *param);

void	drawlines(t_map **map, t_param *param);

void    setting_controls(t_param *param);

#endif