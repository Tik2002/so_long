/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tigpetro <tigpetro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/29 19:34:18 by senate            #+#    #+#             */
/*   Updated: 2024/04/06 18:37:40 by tigpetro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>

int	err(void)
{
	ft_putstr_fd("Error\n", 2);
	return (1);
}

int	keys(int key, t_game *game)
{
	if (key == ESCAPE_KEY)
		exit(0);
	else if (key == UP_ARROW_KEY)
		game->player_y -= 10;
	else if (key == DOWN_ARROW_KEY)
		game->player_y += 10;
	else if (key == LEFT_ARROW_KEY)
		game->player_x -= 10;
	else if (key == RIGHT_ARROW_KEY)
		game->player_x += 10;
	mlx_clear_window(game->mlx, game->win);
	mlx_pixel_put(game->mlx, game->win, game->player_x, game->player_y, 0xFFFFFF);
	return (0);
}

int	main(int ac, char **av)
{
	t_game	game;
	t_point	my_map;

	if (ac != 2)
		return (1);
	if (!check_map(av[1]))
		return (err());
	game.mlx = mlx_init();
	if (!game.mlx)
		return (1);
	my_map.x = 800;
	my_map.y = 800;
	game.player_x = 400;
	game.player_y = 300;
	game.win = mlx_new_window(game.mlx, my_map.x, my_map.y, "My window");
	mlx_key_hook(game.win, keys, &game);
	mlx_loop(game.mlx);
	mlx_destroy_window(game.mlx, game.win);
	free (game.mlx);
	system("leaks so_long");
	return (0);
}

//


