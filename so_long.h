/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfaure <mfaure@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 14:48:42 by mfaure            #+#    #+#             */
/*   Updated: 2025/10/11 16:39:23 by mfaure           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stddef.h>

typedef struct s_player
{
	int		x;
	int		y;
	int		moves;
}			t_player;

typedef struct	s_game {
	int			collectible_count;
	int			map_bottom;
	int			map_wall;
	t_player	player;
	char		**map;
}				t_game;

int		ft_strlen(const char *str);
char	*get_next_line(int fd);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strdup(char *src);
char	**ft_split(char const *s, char c);
char	*ft_strjoin(char const *s1, char const *s2);
size_t	ft_strcat(char *dst, const char *src);
size_t	ft_strlcpy(char *dest, const char *src, size_t size);
char	*ft_strdup(char *src);
char 	*ft_realloc_str(char *str, size_t new_len);
int 	check_map(char **map);
int		check_map_elements(const char *str);

#endif