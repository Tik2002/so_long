/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tigpetro <tigpetro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/29 19:34:18 by senate            #+#    #+#             */
/*   Updated: 2024/04/08 21:14:22 by tigpetro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>

int	err(void)
{
	ft_putstr_fd("Error\n", 2);
	return (1);
}

// Es key-ery lriv pti veranayvi

int	keys(int key, t_game *game)
{
	if (key == ESCAPE_KEY)
		exit(0);
	else if (key == UP_ARROW_KEY)
		game->player->y -= 1;
	else if (key == DOWN_ARROW_KEY)
		game->player->y += 1;
	else if (key == LEFT_ARROW_KEY)
		game->player->x -= 1;
	else if (key == RIGHT_ARROW_KEY)
		game->player->x += 1;
	mlx_clear_window(game->mlx, game->win);
	mlx_pixel_put(game->mlx, game->win, game->player->x, game->player->y, 0xFFFFFF);
	return (0);
}

// hors arev te hly minilibx-ic normal ban em jogel, vorde inch vor harmar mexanizm em man gali
// menak linuxi vra a ashxatum, mac-i hamar harmar ban chka pixely nkar sarqelu hamar

int	main(int ac, char **av)
{
	t_game	game;
	char	**map;

	if (ac != 2)
		return (1);
	map = check_map(av[1]);
	if (!map)
		return (err());
	game.map = map_size(map);
	printf("map y = %d | map x = %d", game.map->y, game.map->x);
	game.player = find_player(map);
	printf("player y = %d | player x = %d", game.player->y, game.player->x);
	game.mlx = mlx_init();
	if (!game.mlx)
		return (1);
	game.win = mlx_new_window(game.mlx, HEIGHT, WIDTH, "My window");
	mlx_xpm_file_to_image(game.mlx, "./assets/Floor/Floor_0.xpm", 40, 40);
	mlx_put_image_to_window(game.mlx, game.win, void *img_ptr, int x, int y);
	mlx_key_hook(game.win, keys, &game);
	mlx_loop(game.mlx);
	mlx_destroy_window(game.mlx, game.win);
	free (game.mlx);
	system("leaks so_long");
	return (0);
}

//


