/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tigpetro <tigpetro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 18:26:00 by tigpetro          #+#    #+#             */
/*   Updated: 2024/04/05 20:11:56 by tigpetro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>

// char **creat_map(int wid, int len)
// {
// 	char **map;
// 	int i = 0;
// 	int j;

// 	map = (char **)malloc(wid * sizeof(char *));
// 	while (i < wid)
// 	{
// 		j = 0;
// 		map[i] = (char *)malloc(len);
// 		while (j < len)
// 		{
// 			if (i == 0 || i == wid - 1 || j == 0 || j == len - 1)
// 				map[i][j++] = '1';
// 			else
// 				map[i][j++] = '0';
// 		}
// 		i++;
// 	}
// 	return (map);
// }

static int	_check_type(char *av)
{
	int		i;

	i = ft_strlen(av);
	i -= 4;
	return (!ft_strncmp(av + i, ".ber", 4));
}

static int	_check_map(int fd, int count)
{
	int		i;
	int		j;
	int		len;
	char	**map;

	i = 0;
	map = (char **)malloc(count + 1);
	if (!map)
		return (0);
	map[count] = 0;
	while (i < count)
	{
		j = -1;
		map[i] = get_next_line(fd);
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
	ft_destroy(map);
	return (1);
}

// static int	_check_road(char *av)
// {
// 	int		i;

// 	i = ft_strlen(av);
// 	i -= 4;
// 	return (!ft_strncmp(av + i, ".ber", 4));
// }

static int	check_count(char *av)
{
	int		count;
	char	*tmp;
	int		fd;

	fd = open(av, O_RDONLY);
	count = 0;
	while ((tmp = get_next_line(fd)))
	{
		free(tmp);
		count++;
	}
	close(fd);
	return (count);
}

int check_map(char *av)
{
	int		fd;
	int		count;

	count = check_count(av);
	if (!_check_type(av))
		return (0);
	fd = open(av, O_RDONLY);
	if (!_check_map(fd, count))
		return (0);
	close(fd);
	return (1);
}
