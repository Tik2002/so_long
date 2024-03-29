/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: senate <senate@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/29 19:34:18 by senate            #+#    #+#             */
/*   Updated: 2024/03/29 20:47:40 by senate           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>

char **creat_map(int wid, int len, t_point pers)
{
	char **map;
	int i = 0;
	int j;

	map = (char **)malloc(wid * sizeof(char *));
	while (i < wid)
	{
		j = 0;
		map[i] = (char *)malloc(len);
		while (j < len)
		{
			if (i == 0 || i == wid - 1 || j == 0 || j == len - 1)
				map[i][j++] = '1';
			else
				map[i][j++] = '0';
		}
		i++;
	}
	map[pers.y][pres.x] = 'P';
	return (map);
}

int main(void)
{
	int i = 0;
	int len = 20;
	int wid = 10;
	char **map;
	t_point pers;

	pers = {3, 3};

	map = creat_map(wid, len);

	while (i < wid)
		printf("%s\n", map[i++]);
	free (map);
	system ("leaks");
	return 0;
}
