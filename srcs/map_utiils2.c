/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utiils2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tigpetro <tigpetro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 18:14:22 by tigpetro          #+#    #+#             */
/*   Updated: 2025/01/15 19:01:59 by tigpetro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>

int	ft_counter_check(t_game *game)
{
	int	i;
	int	j;
	int	exit_count;

	i = 0;
	exit_count = 0;
	game->head_count = 0;
	while (game->map[i])
	{
		j = 0;
		while (game->map[i][j])
		{
			if (game->map[i][j] == 'E')
				exit_count++;
			else if (game->map[i][j] == 'C')
				game->head_count++;
			++j;
		}
		++i;
	}
	if (exit_count > 1)
		return (0);
	return (game->head_count);
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

int	_check_player(char **map, char c)
{
	int	i;
	int	j;
	int	flag;

	flag = 0;
	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == c)
				flag++;
			j++;
		}
		i++;
	}
	return (flag == 1);
}

int	_check_map_design(char **map)
{
	int	i;
	int	j;
	int	len;

	i = 0;
	while (map[i])
	{
		j = -1;
		len = ft_strlen(map[i]) - 1;
		while (j++ < (int)len - 1)
			if (((i && map[i][len]) && (map[i][0] != '1' || map[i][len
				- 1] != '1' || (j && j < (int)len - 2
				&& (map[i][j] != 'C' && map[i][j] != 'P'
				&& map[i][j] != '0' && map[i][j] != '1'
				&& map[i][j] != 'G' && map[i][j] != 'E'))))
				|| ((!i || !map[i][len]) && map[i][j] != '1'))
				return (0);
		i++;
	}
	return (1);
}
