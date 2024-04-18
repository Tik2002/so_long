/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tigpetro <tigpetro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 21:08:46 by tigpetro          #+#    #+#             */
/*   Updated: 2024/04/13 18:22:13 by tigpetro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>

void	go_up(t_game *game)
{
	if (game->map[game->player_cord->y][game->player_cord->x] == 'G'
		|| (game->map[game->player_cord->y][game->player_cord->x] == 'E'
			&& game->head_count == 0))
	{
		mlx_clear_window(game->mlx, game->win);
		game->map[game->player_cord->y + 1][game->player_cord->x] = '0';
		game->moves++;
		game->endgame = 1;
		draw_map(game);
	}
	else if (game->map[game->player_cord->y][game->player_cord->x] == '1'
			|| game->map[game->player_cord->y][game->player_cord->x] == 'E')
		game->player_cord->y += 1;
	else
	{
		mlx_clear_window(game->mlx, game->win);
		if (game->map[game->player_cord->y][game->player_cord->x] == 'C')
			game->head_count -= 1;
		game->map[game->player_cord->y][game->player_cord->x] = 'P';
		game->map[game->player_cord->y + 1][game->player_cord->x] = '0';
		game->moves++;
		draw_map(game);
	}
}

void	go_down(t_game *game)
{
	if (game->map[game->player_cord->y][game->player_cord->x] == 'G'
		|| (game->map[game->player_cord->y][game->player_cord->x] == 'E'
			&& game->head_count == 0))
	{
		mlx_clear_window(game->mlx, game->win);
		game->map[game->player_cord->y - 1][game->player_cord->x] = '0';
		game->moves++;
		game->endgame = 1;
		draw_map(game);
	}
	else if (game->map[game->player_cord->y][game->player_cord->x] == '1'
			|| game->map[game->player_cord->y][game->player_cord->x] == 'E')
		game->player_cord->y -= 1;
	else
	{
		mlx_clear_window(game->mlx, game->win);
		if (game->map[game->player_cord->y][game->player_cord->x] == 'C')
			game->head_count -= 1;
		game->map[game->player_cord->y][game->player_cord->x] = 'P';
		game->map[game->player_cord->y - 1][game->player_cord->x] = '0';
		game->moves++;
		draw_map(game);
	}
}

void	go_right(t_game *game)
{
	if (game->map[game->player_cord->y][game->player_cord->x] == 'G'
		|| (game->map[game->player_cord->y][game->player_cord->x] == 'E'
			&& game->head_count == 0))
	{
		mlx_clear_window(game->mlx, game->win);
		game->map[game->player_cord->y][game->player_cord->x - 1] = '0';
		game->moves++;
		game->endgame = 1;
		draw_map(game);
	}
	else if (game->map[game->player_cord->y][game->player_cord->x] == '1'
			|| game->map[game->player_cord->y][game->player_cord->x] == 'E')
		game->player_cord->x -= 1;
	else
	{
		mlx_clear_window(game->mlx, game->win);
		if (game->map[game->player_cord->y][game->player_cord->x] == 'C')
			game->head_count -= 1;
		game->map[game->player_cord->y][game->player_cord->x] = 'P';
		game->map[game->player_cord->y][game->player_cord->x - 1] = '0';
		game->moves++;
		draw_map(game);
	}
}

void	go_left(t_game *game)
{
	if (game->map[game->player_cord->y][game->player_cord->x] == 'G'
		|| (game->map[game->player_cord->y][game->player_cord->x] == 'E'
			&& game->head_count == 0))
	{
		mlx_clear_window(game->mlx, game->win);
		game->map[game->player_cord->y][game->player_cord->x + 1] = '0';
		game->moves++;
		game->endgame = 1;
		draw_map(game);
	}
	else if (game->map[game->player_cord->y][game->player_cord->x] == '1'
			|| game->map[game->player_cord->y][game->player_cord->x] == 'E')
		game->player_cord->x += 1;
	else
	{
		mlx_clear_window(game->mlx, game->win);
		if (game->map[game->player_cord->y][game->player_cord->x] == 'C')
			game->head_count -= 1;
		game->map[game->player_cord->y][game->player_cord->x] = 'P';
		game->map[game->player_cord->y][game->player_cord->x + 1] = '0';
		game->moves++;
		draw_map(game);
	}
}
