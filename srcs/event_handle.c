/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_handle.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tigpetro <tigpetro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 19:56:25 by tigpetro          #+#    #+#             */
/*   Updated: 2024/04/13 18:28:53 by tigpetro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>

static void	game_event(int key, t_game *game)
{
	if (key == KEY_W || key == KEY_UP)
	{
		game->player_cord->y -= 1;
		go_up(game);
	}
	else if (key == KEY_S || key == KEY_DOWN)
	{
		game->player_cord->y += 1;
		go_down(game);
	}
	else if (key == KEY_D || key == KEY_RIGHT)
	{
		game->player_cord->x += 1;
		go_right(game);
	}
	else if (key == KEY_A || key == KEY_LEFT)
	{
		game->player_cord->x -= 1;
		go_left(game);
	}
}

static int	key_event(int key, t_game *game)
{
	if (key == KEY_ESC || key == KEY_Q)
		exit_game(game);
	else if (!game->endgame)
		game_event(key, game);
	else if (game->endgame)
		exit_game(game);
	return (0);
}

void	event_handle(t_game *game)
{
	mlx_hook(game->win, 2, 1L << 0, key_event, game);
	mlx_hook(game->win, 17, 1L << 17, exit_game, game);
	mlx_hook(game->win, 9, 1L << 21, draw_map, game);
}
