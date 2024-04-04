/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dabae <dabae@student.42perpignan.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 14:20:26 by dabae             #+#    #+#             */
/*   Updated: 2024/04/03 14:38:40 by dabae            ###   ########.fr       */
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

# define MAIN_PAD_ESC   65307

typedef struct s_map
{
	float	x;
	float	y;
	float	z;
	bool	is_end_x;
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
	int		map_max_wid;
	float	max_z;
	float	min_z;
	int		window_l;
	int		window_w;
	float	scale;
	float	z_scale;
	int		is_iso;
	double	x_angle;
	double	y_angle;
	double	z_angle;	
	double	iso_angle;
	int		x_offset;
	int		y_offset;
	t_map	**map;
}			t_param;

int		num_word(char **arr);
float	absolute(float a);
int		is_positive(float a);
void	err_msg_exit(char *err_msg);
void	parse_map(char *filename, t_param *param);
void	rotation_x(t_map *a, t_param *param);
void	rotation_y(t_map *a, t_param *param);
void	rotation_z(t_map *a, t_param *param);
void	isometric(t_map *a, t_param *param);
void	get_scale(t_param *param);
void	get_max_z(t_param *param);
void	get_min_z(t_param *param);

void	drawlines(t_param *param);
void	setting_controls(t_param *param);
int		create_trgb(int t, int r, int g, int b);
void	set_color(t_param *param);
int		close_window(t_param *param, int is_error);
void	free_map(t_param *param);

#endif