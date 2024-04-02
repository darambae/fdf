/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dabae <dabae@student.42perpignan.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 15:14:16 by dabae             #+#    #+#             */
/*   Updated: 2024/04/02 10:53:32 by dabae            ###   ########.fr       */
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

# define LEFT_KEY       65361
# define RIGHT_KEY      65363
# define UP_KEY         65362
# define DOWN_KEY       65364

# define NUM_0          48
# define NUM_1          49
# define NUM_2          50
# define NUM_3          51
# define NUM_4          52
# define NUM_5          53
# define NUM_6          54
# define NUM_7          55
# define NUM_8          56
# define NUM_PLUS       61
# define NUM_MINUS      45

# define MAIN_PAD_ESC   65307
# define MAIN_PAD_0     65438
# define MAIN_PAD_1     65436
# define MAIN_PAD_2     65433
# define MAIN_PAD_3     65435
# define MAIN_PAD_4     65430
# define MAIN_PAD_5     65437
# define MAIN_PAD_6     65432
# define MAIN_PAD_7     65429
# define MAIN_PAD_8     65431

typedef struct s_map
{
	float	x;
	float	y;
	float	z;
	bool	is_end;
	int		color;
}				t_map;

typedef struct s_param
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
	float	max_z;
	float	min_z;
	int		window_l;
	int		window_w;
	float	scale;
	int		is_iso;
	double	x_angle;
	double	y_angle;
	double	z_angle;	
	double	iso_angle;
	int		x_offset;
	int		y_offset;
	t_map	**map;
}			t_param;

float	absolute(float a);
int		is_positive(float a);
void	err_msg_exit(char *err_msg);
void	parse_map(char *filename, t_param *param);
void	rotation_x(t_map *a, t_param *param);
void	rotation_y(t_map *a, t_param *param);
void	rotation_z(t_map *a, t_param *param);
void	isometric(t_map *a, t_param *param);
float	get_scale(t_param *param);
void	get_max_z(t_param *param);
void	get_min_z(t_param *param);

void	drawlines(t_param *param);

void	setting_controls(t_param *param);
int		create_trgb(int t, int r, int g, int b);
void	set_color(t_param *param);
void	zoom(int key, t_param *param);
void	move(int key, t_param *param);
void	rotate(int key, t_param *param);
void	change_projection(int key, t_param *param);
void	reset_camera(int key, t_param *param);
int		close_window(t_param *param);
void	free_map(t_param *param);

#endif