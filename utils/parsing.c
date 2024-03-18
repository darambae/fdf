/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dabae <dabae@student.42perpignan.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 12:27:31 by dabae             #+#    #+#             */
/*   Updated: 2024/03/18 11:50:37 by dabae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

int	len_lenth(char **str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
}

t_map	allocate_memory_map(int	fd, t_map **map)
{
	char	*line;
	char	**words;
	int		num_lines;
	int		num_wd;
	
	num_lines = 0;
	while ((line = get_next_line(fd)) != NULL)
	{
		num_wd = 0;
		words = ft_split(line, ' ');
		while (words[num_wd])
			num_wd++;
		map[num_lines] = malloc(sizeof(t_map *) * (num_wd));
		num_lines++;
		
	}		
}

/*parse_map : read a map file(*.fdf) and save the position and its height*/
void	parse_map(char *filename, t_map **map)
{
    int     fd;
    char    *line;
	char	**positions;
	int		x;
	int		y;
	
    fd = open(filename, O_RDONLY, 0);
    if (fd < 0)
        err_msg_exit("Unable to open the map file");
	y = 0;
    while ((line = get_next_line(fd)) != NULL)
    {
		positions = ft_split(line, ' ');
		x = 0;
		while (positions[x])
		{
			map[y][x].x = x;
			map[y][x].y = y;
			map[y][x].z = ft_atoi(positions[x]);
			x++;
			if (!positions[x])
				map[y][x - 1].len_x = x - 1;
		}
		ft_free_tab(positions);
		free(line);
		y++;
    }
	map[y - 1][x - 1].len_y = y - 1;
	close(fd);
}