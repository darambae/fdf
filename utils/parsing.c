/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dabae <dabae@student.42perpignan.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 12:27:31 by dabae             #+#    #+#             */
/*   Updated: 2024/04/03 14:44:18 by dabae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

static void	check_malloc(void *ptr)
{
	if (!ptr)
	{
		free(ptr);
		err_msg_exit("Memory allocation failed");
	}
}

static void	allocate_memory_map(t_param *param, char *filename)
{
	int		fd;
	int		line_len;
	char	*line;
	t_map	**map;

	line_len = param->map_len;
	map = malloc(sizeof(t_map *) * (line_len + 1));
	fd = open(filename, O_RDONLY);
	while (--line_len >= 0)
	{
		line = get_next_line(fd);
		if (!line)
		{
			close(fd);
			free(line);
			get_next_line(-1);
			break ;
		}
		map[line_len] = malloc(sizeof(t_map)
				* (num_word(ft_split(line, ' ')) + 1));
		free(line);
		line = NULL;
	}
	param->map = map;
	close(fd);
}

static void	cal_mem_map(char *filename, t_param *param)
{
	int		fd;
	char	*line;
	int		tmp;

	tmp = 0;
	fd = open(filename, O_RDONLY);
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
		{
			close(fd);
			free(line);
			get_next_line(-1);
			break ;
		}
		if (num_word(ft_split(line, ' ')) > tmp)
			tmp = num_word(ft_split(line, ' '));
		free(line);
		line = NULL;
		param->map_len++;
	}
	param->map_max_wid = tmp;
	close(fd);
}

static void	save_positions(char **positions, int y, t_param *param)
{
	int	x;

	x = 0;
	if (y < 0 || y >= param->map_len)
		return ;
	while (positions[x] && x < param->map_max_wid)
	{
		param->map[y][x].x = x;
		param->map[y][x].y = y;
		param->map[y][x].z = (float)ft_atoi(positions[x]);
		param->map[y][x].is_end_x = false;
		x++;
	}
	param->map[y][x - 1].is_end_x = true;
}

/*parse_map : read a map file(*.fdf) and save the position and its height*/

void	parse_map(char *filename, t_param *param)
{
	int		fd;
	char	*line;
	int		y;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
		err_msg_exit("Unable to open the map file");
	cal_mem_map(filename, param);
	allocate_memory_map(param, filename);
	y = 0;
	while (1)
	{
		line = get_next_line(fd);
		if (!line || y > param->map_len - 1)
		{
			free(line);
			break ;
		}
		save_positions(ft_split(line, ' '), y, param);
		free(line);
		y++;
	}
	param->map[y] = NULL;
	close(fd);
}
