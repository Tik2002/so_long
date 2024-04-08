/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utiils2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tigpetro <tigpetro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 18:14:22 by tigpetro          #+#    #+#             */
/*   Updated: 2024/04/08 20:56:19 by tigpetro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>

void	ft_destroy(char **map)
{
	char	**tmp;

	tmp = map;
	while (*tmp)
	{
		free(*tmp);
		tmp++;
	}
	free(map);
}

int	ft_counter_check(char **map)
{
	int	i;
	int	j;
	int	coin_count;
	int	exit_count;

	i = 0;
	exit_count = 0;
	coin_count = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'E')
				++exit_count;
			else if (map[i][j] == 'C')
				++coin_count;
			++j;
		}
		++i;
	}
	if (exit_count > 1)
		return (0);
	return (exit_count + coin_count);
}

t_point	*map_size(char **map)
{
	t_point	*size;

	size = (t_point *)malloc(sizeof(t_point));
	size->x = 0;
	size->y = 0;
	while (map[size->y][size->x])
		(size->x)++;
	while (map[size->y])
		(size->y)++;
	return (size);
}

t_point	*find_player(char **map)
{
	t_point	*player;

	player = (t_point *)malloc(sizeof(t_point));
	player->y = 0;
	while (map[player->y])
	{
		player->x = 0;
		while (map[player->y][player->x])
		{
			if (map[player->y][player->x] == 'P')
				return (player);
			(player->x)++;
		}
		(player->y)++;
	}
	return (0);
}
