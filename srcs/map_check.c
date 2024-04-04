/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tigpetro <tigpetro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 18:26:00 by tigpetro          #+#    #+#             */
/*   Updated: 2024/04/04 20:25:22 by tigpetro         ###   ########.fr       */
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

static int	_check_map(int fd)
{
	int		i;
	int		j;
	char	*map;

	i = 0;
	while ((map = get_next_line(fd)))
	{
		j = 0;
		ft_printf("%s", map);
		if (i == 0 || map[ft_strlen(map) - 1] == 0)
		{
			while (j < (int)ft_strlen(map) - 1)
			{
				if (map[j] != '1')
					return (0);
				j++;
			}
		}
		else
			if (map[0] != '1' || map[ft_strlen(map) - 2] != '1')
				return (0);
		i++;
	}
	return (1);
}

// static int	_check_road(char *av)
// {
// 	int		i;

// 	i = ft_strlen(av);
// 	i -= 4;
// 	return (!ft_strncmp(av + i, ".ber", 4));
// }

int check_map(char *av)
{
	int	fd;
	fd = open(av, O_RDONLY);

	if (!_check_type(av) || !_check_map(fd))
		return (0);

	close(fd);
	return (1);
}
