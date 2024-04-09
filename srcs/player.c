/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tigpetro <tigpetro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 21:08:46 by tigpetro          #+#    #+#             */
/*   Updated: 2024/04/09 21:15:29 by tigpetro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>

static void	player_move_image(char key, t_game *game)
{
	mlx_destroy_image(game->mlx, game->img_player);
	// if (key == 'w')
	// 	game->img_player = mlx_xpm_file_to_image
	// 		(game->mlx, "assets/images/PD.xpm", &game->img_w, &game->img_h);
	// else if (key == 's')
	// 	game->img_player = mlx_xpm_file_to_image
	// 		(game->mlx, "assets/images/PA.xpm", &game->img_w, &game->img_h);
	// else if (key == 'd')
	// 	game->img_player = mlx_xpm_file_to_image
	// 		(game->mlx, "assets/images/PD.xpm", &game->img_w, &game->img_h);
	// else if (key == 'a')
	// 	game->img_player = mlx_xpm_file_to_image
	// 		(game->mlx, "assets/images/PA.xpm", &game->img_w, &game->img_h);
}

void	player_w(t_game *game)
{
	player_move_image('w', game);
	if (game->map[game->player_cord->y][game->player_cord->x] == 'E'
			&& game->n_colect == 0)
	{
		mlx_clear_window(game->mlx, game->win);
		game->map[game->player_cord->y + 1][game->player_cord->x] = '0';
		game->moves++;
		game->endgame = 1;
		draw_map(game);
	}
	else if (game->map[game->player_cord->y][game->player_cord->x] == '1'
			|| game->map[game->player_cord->y][game->player_cord->x] == 'E')
		game->y_player += 1;
	else
	{
		mlx_clear_window(game->mlx, game->win);
		if (game->map[game->player_cord->y][game->player_cord->x] == 'C')
			game->n_colect -= 1;
		game->map[game->player_cord->y][game->player_cord->x] = 'P';
		game->map[game->player_cord->y + 1][game->player_cord->x] = '0';
		game->moves++;
		draw_map(game);
	}
}

void	player_s(t_game *game)
{
	player_move_image('s', game);
	if (game->map[game->y_player][game->x_player] == 'E'
			&& game->n_colect == 0)
	{
		mlx_clear_window(game->mlx, game->win);
		game->map[game->y_player - 1][game->x_player] = '0';
		game->moves++;
		game->endgame = 1;
		draw_map(game);
	}
	else if (game->map[game->y_player][game->x_player] == '1'
			|| game->map[game->y_player][game->x_player] == 'E')
		game->y_player -= 1;
	else
	{
		mlx_clear_window(game->mlx, game->win);
		if (game->map[game->y_player][game->x_player] == 'C')
			game->n_colect -= 1;
		game->map[game->y_player][game->x_player] = 'P';
		game->map[game->y_player - 1][game->x_player] = '0';
		game->moves++;
		draw_map(game);
	}
}

void	player_d(t_game *game)
{
	player_move_image('d', game);
	if (game->map[game->y_player][game->x_player] == 'E'
			&& game->n_colect == 0)
	{
		mlx_clear_window(game->mlx, game->win);
		game->map[game->y_player][game->x_player - 1] = '0';
		game->moves++;
		game->endgame = 1;
		draw_map(game);
	}
	else if (game->map[game->y_player][game->x_player] == '1'
			|| game->map[game->y_player][game->x_player] == 'E')
		game->x_player -= 1;
	else
	{
		mlx_clear_window(game->mlx, game->win);
		if (game->map[game->y_player][game->x_player] == 'C')
			game->n_colect -= 1;
		game->map[game->y_player][game->x_player] = 'P';
		game->map[game->y_player][game->x_player - 1] = '0';
		game->moves++;
		draw_map(game);
	}
}

void	player_a(t_game *game)
{
	player_move_image('a', game);
	if (game->map[game->y_player][game->x_player] == 'E'
			&& game->n_colect == 0)
	{
		mlx_clear_window(game->mlx, game->win);
		game->map[game->y_player][game->x_player + 1] = '0';
		game->moves++;
		game->endgame = 1;
		draw_map(game);
	}
	else if (game->map[game->y_player][game->x_player] == '1'
			|| game->map[game->y_player][game->x_player] == 'E')
		game->x_player += 1;
	else
	{
		mlx_clear_window(game->mlx, game->win);
		if (game->map[game->y_player][game->x_player] == 'C')
			game->n_colect -= 1;
		game->map[game->y_player][game->x_player] = 'P';
		game->map[game->y_player][game->x_player + 1] = '0';
		game->moves++;
		draw_map(game);
	}
}
