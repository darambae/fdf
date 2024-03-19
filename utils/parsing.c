/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dabae <dabae@student.42perpignan.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 12:27:31 by dabae             #+#    #+#             */
/*   Updated: 2024/03/18 18:00:51 by dabae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

static void	allocate_memory_map(t_map **map, t_param *param)
{
	map = malloc(sizeof(t_map *) * (param->map_len + 1));
	if (!map)
	{
		free(map);
		return ;
	}
	while (param->map_len >= 0)
	{
		map[param->map_len] = malloc(sizeof(t_map) * (param->map_wid + 1));
		if (!map[param->img_len])
		{
			free(map[param->img_len]);
			return ;
		}
	}
}

static int	num_word(char **arr)
{
	int	i;

	i = 0;
	while (arr[i])
		i++;
	return (i);
}

static t_map	**cal_mem_map(char *filename, t_map **map, t_param *param)
{
	int		fd;
	char	*line;
	char	**words;
	int		num_lines;

	fd = open(filename, O_RDONLY, 0);
	num_lines = 1;
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
		{
			free(line);
			break ;
		}
		words = ft_split(line, ' ');
		param->map_wid = num_word(words);
		ft_free_tab(words);
		free(line);
		num_lines++;
	}
	param->map_len = num_lines;
	close(fd);
	return (map);
}

static void	save_positions(char **positions, t_map **map, int y)
{
	int	x;

	x = 0;
	while (positions[x])
	{
		map[y][x].x = x;
		map[y][x].y = y;
		map[y][x].z = ft_atoi(positions[x]);
		x++;
	}
}

/*parse_map : read a map file(*.fdf) and save the position and its height*/

void	parse_map(char *filename, t_map **map, t_param *param)
{
	int		fd;
	char	*line;
	char	**positions;
	int		y;

	fd = open(filename, O_RDONLY, 0);
	if (fd < 0)
		err_msg_exit("Unable to open the map file");
	cal_mem_map(filename, map, param);
	allocate_memory_map(map, param);
	y = 0;
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
		{
			free(line);
			break ;
		}
		positions = ft_split(line, ' ');
		save_positions(positions, map, y++);
		ft_free_tab(positions);
		free(line);
	}
	close(fd);
}
