/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dabae <dabae@student.42perpignan.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 12:27:31 by dabae             #+#    #+#             */
/*   Updated: 2024/04/03 14:40:11 by dabae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf_bonus.h"

static int	check_file_type(char *filename, char *type)
{
	int	i;

	i = 0;
	while (type[i] == filename[(int)ft_strlen(filename) - 4 + i] && i < 4)
		i++;
	if (type[i])
		return (0);
	else
		return (1);
}

static void	allocate_memory_map(t_param *param, char *filename)
{
	int		fd;
	int		line_len;
	char	*line;
	char	**words;

	line_len = param->map_len;
	param->map = malloc(sizeof(t_map *) * (line_len + 1));
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
		words = ft_split(line, ' ');
		param->map[line_len] = malloc(sizeof(t_map) * (num_word(words) + 1));
		ft_free_tab(words);
		free(line);
		line = NULL;
	}
	close(fd);
}

static void	cal_mem_map(char *filename, t_param *param)
{
	int		fd;
	char	*line;
	char	**words;

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
		words = ft_split(line, ' ');
		if (num_word(words) > param->map_max_wid)
			param->map_max_wid = num_word(words);
		ft_free_tab(words);
		free(line);
		line = NULL;
		param->map_len++;
	}
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
	ft_free_tab(positions);
}

/*parse_map : read a map file(*.fdf) and save the position and its height*/

void	parse_map(char *filename, t_param *param)
{
	int		fd;
	char	*line;
	int		y;

	fd = open(filename, O_RDONLY);
	if (fd < 0 || !check_file_type(filename, ".fdf"))
		close_window(param, 1);
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
