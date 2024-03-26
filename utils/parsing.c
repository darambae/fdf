/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dabae <dabae@student.42perpignan.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 12:27:31 by dabae             #+#    #+#             */
/*   Updated: 2024/03/22 13:11:14 by dabae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

static t_map	**allocate_memory_map(t_param *param)
{
	int		line_len;
	t_map	**map;
	
	line_len = param->map_len;
	map = malloc(sizeof(t_map *) * (param->map_len + 1));
	if (!map)
	{
		free(map);
		return NULL;
	}
	while (--line_len >= 0)
	{
		map[line_len] = malloc(sizeof(t_map) * (param->map_wid));
		if (!map[line_len])
		{
			free(map[line_len]);
			return NULL;
		}
	}
	return (map);
}

static int	num_word(char **arr)
{
	int	i;

	if (!arr || !*arr)
		return (0);
	i = 0;
	while (arr[i])
		i++;
	return (i);
}

static void	cal_mem_map(char *filename, t_param *param)
{
	int		fd;
	char	*line;
	char	**words;
	int		num_lines;
	
	fd = open(filename, O_RDONLY);
	num_lines = 0;
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
		words = ft_split(line, ' ');
		param->map_wid = num_word(words);
		ft_free_tab(words);
		free(line);
		line = NULL;
		num_lines++;
	}
	param->map_len = num_lines;
	close(fd);
}

static void	save_positions(char **positions, t_map **map, int y, t_param *param)
{
	int	x;

	x = 0;
	if (y < 0 || y >= param->map_len)
		return ;
	while (positions[x] && x < param->map_wid)
	{
		map[y][x].x = x;
		map[y][x].y = y;
		map[y][x].z = (float)ft_atoi(positions[x]);
		map[y][x].is_end = false;
		x++;
	}
	map[y][--x].is_end = true;
	
}

/*parse_map : read a map file(*.fdf) and save the position and its height*/

t_map	**parse_map(char *filename, t_param *param)
{
	int		fd;
	char	*line;
	char	**positions;
	t_map	**map;
	int		y;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
		err_msg_exit("Unable to open the map file");
	cal_mem_map(filename, param);
	map = allocate_memory_map(param);
	if (!map)
		err_msg_exit("memory allocation failed");
	y = 0;
	while (1)
	{
		line = get_next_line(fd);
		if (!line || y > param->map_len - 1)
		{
			free(line);
			break ;
		}
		positions = ft_split(line, ' ');
		save_positions(positions, map, y, param);
		ft_free_tab(positions);
		free(line);
		y++;
	}
	map[y] = NULL;
	close(fd);
	return (map);
}
