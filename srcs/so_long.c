/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tigpetro <tigpetro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/29 19:34:18 by senate            #+#    #+#             */
/*   Updated: 2024/04/09 21:19:32 by tigpetro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>

static int	head_count(char **map)
{
	int	count;

	count = 0;
	while (count)
}

int	err(void)
{
	ft_putstr_fd("Error\nInvalid input\n", 2);
	return (1);
}

int	exit_game(t_game *game)
{
	ft_destroy(game->map);
	mlx_destroy_image(game->mlx, game->floor);
	mlx_destroy_image(game->mlx, game->wall);
	mlx_destroy_image(game->mlx, game->head);
	mlx_destroy_image(game->mlx, game->player);
	mlx_destroy_image(game->mlx, game->exit);
	mlx_destroy_window(game->mlx, game->win);
	// mlx_destroy_image(game->mlx, game->enemy);
	exit(0);
	return (0);
}

static void	img_init(t_game *game)
{
	game->img_floor = mlx_xpm_file_to_image
		(game->mlx, "assets/Floor/Floor_0.xpm", &game->img_width, &game->img_heigth);
	game->img_wall = mlx_xpm_file_to_image
		(game->mlx, "assets/Wall/Wall_0.xpm", &game->img_width, &game->img_heigth);
	game->img_player = mlx_xpm_file_to_image
		(game->mlx, "assets/Player/Player_0.xpm", &game->img_width, &game->img_heigth);
	game->img_head = mlx_xpm_file_to_image
		(game->mlx, "assets/Item/Head_0.xpm", &game->img_width, &game->img_heigth);
	game->img_exit = mlx_xpm_file_to_image
		(game->mlx, "assets/Gate/Gate_0.xpm", &game->img_width, &game->img_heigth);
	game->img_enemy = mlx_xpm_file_to_image
		(game->mlx, "assets/Enemy/Enemy_0.xpm", &game->img_width, &game->img_heigth);
}

void	mlx_handle(t_game *game)
{
	game->mlx = mlx_init();
	if (!game->mlx)
		return ;
	game->map_width = game->map_cord->x * 32;
	game->map_heigth = game->map_cord->y * 32;
	game->win = mlx_new_window(game->mlx, game->map_width, game->map_height, "My GAY/TYOM");
	game->move = 0;
	game->endgame = 0;
	init_img(game);
	draw_map(game);
	// mlx_destroy_window(game->mlx, game->win);
	// free (game->mlx);
}

int	main(int ac, char **av)
{
	t_game	game;

	if (ac != 2)
		return (1);
	game.map = check_map(av[1]);
	if (!game.map)
		return (err());
	game.map_cord = map_size(game.map);
	printf("map y = %d | map x = %d", game.map_cord->y, game.map_cord->x);
	game.player_cord = find_player(game.map);
	game.head_count = head_count(game.map);
	printf("player y = %d | player x = %d", game.player_cord->y, game.player_cord->x);
	mlx_handle(&game);
	event_handle(&game);
	system("leaks so_long");
	return (0);
}

//


