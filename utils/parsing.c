/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dabae <dabae@student.42perpignan.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 12:27:31 by dabae             #+#    #+#             */
/*   Updated: 2024/03/15 10:16:17 by dabae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

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
		}
		ft_free_tab(positions);
		free(line);
		y++;
    }
	close(fd);
}