/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dabae <dabae@student.42perpignan.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 08:21:22 by dabae             #+#    #+#             */
/*   Updated: 2024/04/03 13:21:19 by dabae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

float	absolute(float a)
{
	if (a < 0)
		return (-a);
	else
		return (a);
}

int	is_positive(float a)
{
	if (a > 0)
		return (1);
	else
		return (-1);
}

int	num_word(char **arr)
{
	int	i;

	if (!arr || !*arr)
		return (0);
	i = 0;
	while (arr[i])
		i++;
	return (i);
}

void	err_msg_exit(char *err_msg)
{
	errno = -1;
	perror(err_msg);
	exit(1);
}

void	free_map(t_param *param)
{
	int		x;
	t_map	**map;

	map = param->map;
	if (map == NULL)
		return ;
	x = 0;
	while (map[x] && x < param->map_len)
	{
		free(map[x]);
		x++;
	}
	free(map);
	map = NULL;
}
