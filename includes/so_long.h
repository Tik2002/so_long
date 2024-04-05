/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: senate <senate@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/29 19:32:31 by senate            #+#    #+#             */
/*   Updated: 2024/04/05 23:32:53 by senate           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42

# endif //BUFFER_SIZE

# include <ft_printf.h>
# include <libft.h>
# include <fcntl.h>
# include "../mlx/mlx.h"

typedef struct	s_point
{
	int			x;
	int			y;
}	t_point;

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
