/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_handle.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tigpetro <tigpetro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 19:56:25 by tigpetro          #+#    #+#             */
/*   Updated: 2024/04/09 20:43:05 by tigpetro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>

static void	game_event(int key, t_game *game)
{
	if (key == KEY_W || key == KEY_UP)
	{
		game->y_player -= 1;
		player_w(game);
	}
	else if (key == KEY_S || key == KEY_DOWN)
	{
		game->y_player += 1;
		player_s(game);
	}
	else if (key == KEY_D || key == KEY_RIGHT)
	{
		game->x_player += 1;
		player_d(game);
	}
	else if (key == KEY_A || key == KEY_LEFT)
	{
		game->x_player -= 1;
		player_a(game);
	}
}

static int	key_event(int key, t_game *game)
{
	if (keycode == KEY_ESC || keycode == KEY_Q)
		exit_game(game);
	else if (!game->endgame)
	{
		game_events(keycode, game);
		ft_putnbr_fd("Moves: ", 1);
		ft_putnbr_fd(game->moves, 1);
		ft_putnbr_fd("\n", 1);
	}
	else if (game->map[game->y_player][game->x_player] == 'E'
			&& game->n_colect == 0)
		exit_game(game);
	return (0);
}


void	event_handle(t_game *game)
{
	mlx_hook(game->win, 2, 1L << 0, key_event, game);
	mlx_hook(game->win, 17, 1L << 17, exit_game, game);
	mlx_hook(game->win, 9, 1L << 21, draw_map, game);
}
