/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tigpetro <tigpetro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 20:55:25 by tigpetro          #+#    #+#             */
/*   Updated: 2024/04/10 20:31:18 by tigpetro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>

static void	img_draw(t_game *game, void *image, int x, int y)
{
	mlx_put_image_to_window
		(game->mlx, game->win, image, x * 64, y * 64);
}

static void	open_exit_draw(t_game *game)
{
	mlx_xpm_file_to_image
		(game->mlx, "assets/Gate/Gate_3.xpm", &game->img_width, &game->img_height);
}

static void	exit_opening(t_game *game)
{
	mlx_destroy_image(game->mlx, game->img_exit);
	if (game->exit_flag == 3)
		game->img_exit = mlx_xpm_file_to_image
			(game->mlx, "assets/Gate/Gate_1.xpm", &game->img_width, &game->img_height);
	else if (game->exit_flag == 2)
		game->img_exit = mlx_xpm_file_to_image
			(game->mlx, "assets/Gate/Gate_2.xpm", &game->img_width, &game->img_height);
	else
		game->img_exit = mlx_xpm_file_to_image
			(game->mlx, "assets/Gate/Gate_3.xpm", &game->img_width, &game->img_height);
}

static void	exit_draw(t_game *game, int x, int y)
{
	if (game->head_count == 0 && game->exit_flag)
	{
		exit_opening(game);
		game->exit_flag--;
	}
	if (game->exit_flag == 3)
		img_draw(game, game->img_exit, x, y);
	else if (!game->exit_flag)
		open_exit_draw(game);
}

void	draw_map(t_game *game)
{
	int	y;
	int	x;

	y = 0;
	while (game->map[y])
	{
		x = 0;
		while (game->map[y][x])
		{
			if (game->map[y][x] == '1')
				img_draw(game, game->img_wall, x, y);
			else if (game->map[y][x] == '0')
				img_draw(game, game->img_floor, x, y);
			else if (game->map[y][x] == 'P')
				img_draw(game, game->img_player, x, y);
			else if (game->map[y][x] == 'C')
				img_draw(game, game->img_head, x, y);
			// else if (game->map[y][x] == 'G')
			// 	img_draw(game, game->img_enemy, x, y);
			else if (game->map[y][x] == 'E')
				exit_draw(game, x, y);
			x++;
		}
		y++;
	}
}
