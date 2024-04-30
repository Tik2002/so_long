/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tigpetro <tigpetro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 20:55:25 by tigpetro          #+#    #+#             */
/*   Updated: 2024/04/28 19:29:34 by tigpetro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>

static void	img_draw(t_game *game, void *image, int x, int y)
{
	mlx_put_image_to_window(game->mlx, game->win, image, x * 64, y * 64);
}

static void	display_moves(t_game *game)
{
	char	*str;

	str = ft_itoa(game->moves);
	mlx_string_put(game->mlx, game->win, 10, 15, 0xFFFF00, "Moves:");
	mlx_string_put(game->mlx, game->win, 60, 15, 0xFFFF00, str);
	free(str);
}

static void	exit_opening(t_game *game)
{
	mlx_destroy_image(game->mlx, game->img_exit);
	if (game->exit_flag == 2)
		game->img_exit = mlx_xpm_file_to_image(game->mlx,
				"textures/Gate/Gate_1.xpm",
				&game->img_width, &game->img_height);
	else if (game->exit_flag == 1)
		game->img_exit = mlx_xpm_file_to_image(game->mlx,
				"textures/Gate/Gate_2.xpm",
				&game->img_width, &game->img_height);
	else if (!game->exit_flag)
		game->img_exit = mlx_xpm_file_to_image(game->mlx,
				"textures/Gate/Gate_3.xpm",
				&game->img_width, &game->img_height);
}

static void	exit_draw(t_game *game, int x, int y)
{
	if (!game->head_count && game->exit_flag >= 0)
	{
		exit_opening(game);
		game->exit_flag--;
	}
	img_draw(game, game->img_exit, x, y);
}

int	draw_map(t_game *game)
{
	int	y;
	int	x;

	y = -1;
	while (game->map[++y])
	{
		x = -1;
		while (game->map[y][++x])
		{
			if (game->map[y][x] == '1')
				img_draw(game, game->img_wall, x, y);
			else if (game->map[y][x] == '0')
				img_draw(game, game->img_floor, x, y);
			else if (game->map[y][x] == 'P')
				img_draw(game, game->img_player, x, y);
			else if (game->map[y][x] == 'C')
				img_draw(game, game->img_head, x, y);
			else if (game->map[y][x] == 'G')
				img_draw(game, game->img_enemy, x, y);
			else if (game->map[y][x] == 'E')
				exit_draw(game, x, y);
		}
	}
	display_moves(game);
	return (0);
}
