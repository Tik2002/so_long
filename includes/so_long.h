/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tigpetro <tigpetro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/29 19:32:31 by senate            #+#    #+#             */
/*   Updated: 2024/04/09 21:16:13 by tigpetro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# define BUFFER_SIZE 42

# include <ft_printf.h>
# include <libft.h>
# include <fcntl.h>
# include "../mlx/mlx.h"

# define KEY_ESC 53
# define KEY_Q 12
# define KEY_W 13
# define KEY_A 0
# define KEY_S 1
# define KEY_D 2
# define KEY_UP 126
# define KEY_LEFT 123
# define KEY_DOWN 125
# define KEY_RIGHT 124


typedef struct	s_point
{
	int	x;
	int	y;
}	t_point;

typedef struct	s_game
{
	void	*mlx;
	void	*win;
	char	**map;
	void	*img_floor;
	void	*img_wall;
	void	*img_player;
	void	*img_head;
	void	*img_exit;
	int		head_count;
	int		map_width;
	int		map_height;
	int		img_width;
	int		img_height;
	int		moves;
	int		endgame;
	t_point	*map_cord;
	t_point	*player_cord;

}	t_game;

// game
int		exit_game(t_game *game);
void	map_draw(t_game *game);
void	event_handle(t_game *game);
void	mlx_handle(t_game *game);
void	event_handle(t_game *game);

// check_map
t_point	*map_size(char **map);
t_point	*find_player(char **map);
int		ft_counter_check(char **map);
char	**check_map(char *av);
int		_check_member(char **map, char c);
int		_check_map_design(char **map);
void	ft_destroy(char **map);
int		_check_road(char **map, int count);


// GNEL
char	*gnl_strchr(char *s, int c);
void	gnl_strjoin(char **line, char *buff);
void	gnl_new_line(char **line, char *next_lines);
char	*gnl_strdup(char **line);
void	gnl_read(int fd, char **line);
char	*get_next_line(int fd);

#endif //SO_LONG_H
