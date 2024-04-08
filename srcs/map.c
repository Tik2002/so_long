/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tigpetro <tigpetro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 18:26:00 by tigpetro          #+#    #+#             */
/*   Updated: 2024/04/08 20:54:32 by tigpetro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>

static int	_check_size(char **map)
{
	size_t	len;
	int		i;

	i = 0;
	len = ft_strlen(map[i]);
	while (map[i])
	{
		if (len != ft_strlen(map[i]))
			return (0);
		i++;
	}
	return (1);
}

static int	_check_type(char *av)
{
	int	i;

	i = ft_strlen(av);
	i -= 4;
	return (!ft_strncmp(av + i, ".ber", 4));
}

static int	_count(char *av)
{
	int		count;
	char	*tmp;
	int		fd;

	fd = open(av, O_RDONLY);
	count = 0;
	tmp = get_next_line(fd);
	while (tmp)
	{
		free(tmp);
		count++;
		tmp = get_next_line(fd);
	}
	close(fd);
	return (count);
}

static char	**_creat_map(char *av, int count)
{
	int		fd;
	int		i;
	char	**map;

	fd = open(av, O_RDONLY);
	i = 0;
	map = (char **)malloc((count + 1) * sizeof(char *));
	if (!map)
		return (0);
	map[count] = 0;
	while (i < count)
	{
		map[i] = get_next_line(fd);
		i++;
	}
	close(fd);
	return (map);
}

char	**check_map(char *av)
{
	int		count;
	char	**map;

	if (!_check_type(av))
		return (0);
	count = _count(av);
	map = _creat_map(av, count);
	if (_check_map_design(map) && _check_size(map) && _check_member(map, 'P')
		&& _check_member(map, 'C') && _check_member(map, 'E')
		&& _check_road(map, count))
		return (map);
	ft_destroy(map);
	return (0);
}
