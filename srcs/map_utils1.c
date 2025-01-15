/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tigpetro <tigpetro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 22:09:38 by senate            #+#    #+#             */
/*   Updated: 2025/01/15 19:02:02 by tigpetro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>

static int	_check(t_game *game, t_point size, t_point cur)
{
	return (cur.y <= 0 || cur.y >= size.y || cur.x <= 0 || cur.x >= size.x
		|| game->map[cur.y][cur.x] == '1' || game->map[cur.y][cur.x] == 'G');
}

static int	_find(t_game *game, t_point size, t_point cur)
{
	static int	count;
	static int	flag;

	if (!count && !flag)
	{
		count = ft_counter_check(game);
		flag = 0;
	}
	if (game->visited[cur.y][cur.x] == 1)
		return (0);
	game->visited[cur.y][cur.x] = 1;
	if (_check(game, size, cur))
		return (0);
	else if (game->map[cur.y][cur.x] == 'E' || game->map[cur.y][cur.x] == 'C')
	{
		if (game->map[cur.y][cur.x] == 'E')
			return (0);
		flag++;
	}
	if (flag == count)
		return (flag);
	return (_find(game, size, (t_point){cur.x + 1, cur.y}) || _find(game,
			size, (t_point){cur.x, cur.y + 1}) || _find(game, size,
			(t_point){cur.x - 1, cur.y}) || _find(game, size,
			(t_point){cur.x, cur.y - 1}));
}

static int	_find_way(t_game *game, t_point size, t_point begin)
{
	int		i;

	i = 0;
	game->visited = (char **)malloc((size.y + 1) * sizeof(char *));
	game->visited[size.y] = 0;
	while (i < size.y)
	{
		game->visited[i++] = ft_calloc(size.x, 1);
	}
	if (_find(game, size, begin))
	{
		ft_destroy(game->visited);
		return (1);
	}
	ft_destroy(game->visited);
	return (0);
}

int	_check_road(t_game *game, int count)
{
	t_point	size;
	t_point	begin;

	size.y = count;
	size.x = ft_strlen(game->map[0]) - 1;
	begin.y = 1;
	while (game->map[begin.y])
	{
		begin.x = 0;
		while (game->map[begin.y][begin.x])
		{
			if (game->map[begin.y][begin.x] == 'P')
				break ;
			begin.x++;
		}
		if (game->map[begin.y][begin.x] == 'P')
			break ;
		begin.y++;
	}
	return (_find_way(game, size, begin));
}

int	_check_member(char **map, char c)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == c)
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}
