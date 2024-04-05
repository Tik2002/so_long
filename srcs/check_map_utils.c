/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: senate <senate@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 22:09:38 by senate            #+#    #+#             */
/*   Updated: 2024/04/06 00:32:08 by senate           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>

static int	_find(char **map, t_point size, t_point cur, char **visited)
{
	if (visited[cur.y][cur.x] == 1)
		return (0);
	visited[cur.y][cur.x] = 1;
	if (cur.y <= 0 || cur.y >= size.y || cur.x <= 0 || cur.x >= size.x
		|| map[cur.y][cur.x] == '1')
		return (0);
	else if (map[cur.y][cur.x] == 'E')
		return (1);
	return (_find(map, size, (t_point){cur.x + 1, cur.y}, visited) ||
	_find(map, size, (t_point){cur.x, cur.y + 1}, visited) ||
	_find(map, size, (t_point){cur.x - 1, cur.y}, visited) ||
	_find(map, size, (t_point){cur.x, cur.y - 1}, visited));
}

static int	_find_way(char **map, t_point size, t_point begin)
{
	char	**visited;
	int		i;

	visited = (char **)malloc((size.y + 1) * sizeof(char *));
	visited[size.y] = 0;
	while (i < size.y)
	{
		visited[i++] = ft_calloc(size.x, 1);
	}
	return(_find(map, size, begin, visited));
}

int	_check_road(char **map, int count)
{
	t_point	size;
	t_point	begin;

	size.y = count;
	size.x = ft_strlen(map[0]) - 1;
	begin.y = 1;
	while (map[begin.y])
	{
		begin.x = 0;
		while(map[begin.y][begin.x])
		{
			if (map[begin.y][begin.x] == 'P')
				break ;
			begin.x++;
		}
		if (map[begin.y][begin.x] == 'P')
			break;
		begin.y++;
	}
	printf("x = %d\ny = %d\n", begin.x, begin.y);
	printf("x = %d\ny = %d\n", size.x, size.y);
	return (_find_way(map, size, begin));
}

int	_check_member(char **map, char c)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while(map[i][j])
		{
			if (map[i][j] == c)
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	_check_map_design(char **map)
{
	int		i;
	int		j;
	int		len;

	i = 0;
	while (map[i])
	{
		j = -1;
		ft_printf("%s", map[i]);
		len = ft_strlen(map[i]) - 1;
		if (!i || !map[i][len])
			while (j++ < (int)len - 1)
				if (map[i][j] != '1')
					return (0);
		if (i && map[i][len])
			if (map[i][0] != '1' || map[i][len - 1] != '1')
				return (0);
		i++;
	}
	return (1);
}
