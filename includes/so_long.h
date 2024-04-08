/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tigpetro <tigpetro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/29 19:32:31 by senate            #+#    #+#             */
/*   Updated: 2024/04/08 18:51:20 by tigpetro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# define BUFFER_SIZE 42

# include <ft_printf.h>
# include <libft.h>
# include <fcntl.h>
# include "../mlx/mlx.h"

# define ESCAPE_KEY 53
# define UP_ARROW_KEY 126
# define DOWN_ARROW_KEY 125
# define LEFT_ARROW_KEY 123
# define RIGHT_ARROW_KEY 124
# define WIDTH 720
# define HEIGHT 720

typedef struct	s_point
{
	int	x;
	int	y;
}	t_point;

typedef struct s_img
{
	void		*img_ptr;
	char		*pixels_ptr;
	int			bpp;
	int			endian;
	int			line_len;
}				t_img;


// typedef struct	s_player
// {
// 	t_point	player;
// }

typedef struct	s_game
{
	void	*mlx;
	void	*win;
	t_point	*map;
	t_point	*player;

}	t_game;

enum {
	ON_KEYDOWN = 2,
	ON_KEYUP = 3,
	ON_MOUSEDOWN = 4,
	ON_MOUSEUP = 5,
	ON_MOUSEMOVE = 6,
	ON_EXPOSE = 12,
	ON_DESTROY = 17
};

// game
int		keys(int key, t_game *game);

// check_map
int		check_map(char *av);
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
