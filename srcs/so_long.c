/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tigpetro <tigpetro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/29 19:34:18 by senate            #+#    #+#             */
/*   Updated: 2024/04/10 19:28:37 by tigpetro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>

int	err(void)
{
	ft_putstr_fd("Error\nInvalid input\n", 2);
	return (1);
}

int	exit_game(t_game *game)
{
	ft_destroy(game->map);
	mlx_destroy_image(game->mlx, game->img_floor);
	mlx_destroy_image(game->mlx, game->img_wall);
	mlx_destroy_image(game->mlx, game->img_head);
	mlx_destroy_image(game->mlx, game->img_player);
	mlx_destroy_image(game->mlx, game->img_exit);
	mlx_destroy_window(game->mlx, game->win);
	// mlx_destroy_image(game->mlx, game->img_enemy);
	exit(0);
	return (0);
}

static void	img_init(t_game *game)
{
	game->img_floor = mlx_xpm_file_to_image
		(game->mlx, "assets/Floor/Floor_0.xpm", &game->img_width, &game->img_height);
	game->img_wall = mlx_xpm_file_to_image
		(game->mlx, "assets/Wall/Wall_0.xpm", &game->img_width, &game->img_height);
	game->img_player = mlx_xpm_file_to_image
		(game->mlx, "assets/Player/Player_0.xpm", &game->img_width, &game->img_height);
	game->img_head = mlx_xpm_file_to_image
		(game->mlx, "assets/Item/Head_0.xpm", &game->img_width, &game->img_height);
	game->img_exit = mlx_xpm_file_to_image
		(game->mlx, "assets/Gate/Gate_0.xpm", &game->img_width, &game->img_height);
	// game->img_enemy = mlx_xpm_file_to_image
	// 	(game->mlx, "assets/Enemy/Enemy_0.xpm", &game->img_width, &game->img_height);
}

void	mlx_handle(t_game *game)
{
	game->mlx = mlx_init();
	if (!game->mlx)
		return ;
	game->map_width = game->map_cord->x * 62;
	game->map_height = game->map_cord->y * 62;
	game->win = mlx_new_window(game->mlx, game->map_width, game->map_height, "My GAY/TYOM");
	game->moves = 0;
	game->endgame = 0;
	img_init(game);
	draw_map(game);
}

int	main(int ac, char **av)
{
	t_game	game;

	if (ac != 2)
		return (1);
	check_map(av[1], &game);
	if (!game.map)
		return (err());
	game.map_cord = map_size(game.map);
	// printf("map y = %d | map x = %d", game.map_cord->y, game.map_cord->x);
	game.player_cord = find_player(game.map);
	// printf("player y = %d | player x = %d", game.player_cord->y, game.player_cord->x);
	mlx_handle(&game);
	event_handle(&game);
	mlx_loop(game.mlx);
	system("leaks so_long");
	return (0);
}

//


