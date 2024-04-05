/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tigpetro <tigpetro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/29 19:34:18 by senate            #+#    #+#             */
/*   Updated: 2024/04/05 18:32:32 by tigpetro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>

int	err(void)
{
	ft_putstr_fd("Error\n", 2);
	return (1);
}

int main(int ac, char **av)
{
	if (ac != 2)
		return (1);
	if (!check_map(av[1]))
		return (err());
	system("leaks so_long");
	return (0);
}

	// void	*mlx_window;
	// void	*mlx_connection;
	// t_map	my_map;

	// my_map.x = 800;
	// my_map.y = 800;
	// mlx_connection = mlx_init();
	// if (!mlx_connection)
	// 	return (1);
	// mlx_window = mlx_new_window(mlx_connection, my_map.x, my_map.y, "My window");
	// mlx_loop(mlx_connection);
	// mlx_destroy_window(mlx_connection, mlx_window);
	// free (mlx_connection);
