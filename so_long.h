/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfaure <mfaure@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 14:48:42 by mfaure            #+#    #+#             */
/*   Updated: 2025/10/22 14:49:55 by mfaure           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

# include <fcntl.h>
# include <mlx.h>
# include <stddef.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/stat.h>
# include <sys/types.h>
# include <unistd.h>

# define KEY_W 119
# define KEY_A 97
# define KEY_S 115
# define KEY_D 100
# define KEY_UP 65362
# define KEY_DOWN 65364
# define KEY_LEFT 65361
# define KEY_RIGHT 65363
# define ESC_KEY 65307

typedef struct s_vars
{
	void		*mlx;
	void		*mlx_window;
}				t_vars;

typedef struct s_img
{
	void		*ptr;
	int			width;
	int			height;
}				t_img;

typedef struct s_player
{
	int			x;
	int			y;
	int			moves;
}				t_player;

typedef struct s_game
{
	int			collectible_count;
	int			map_bottom;
	int			map_width;
	t_player	player;
	t_vars		vars;
	t_img		wall;
	t_img		grass;
	t_img		door;
	t_img		p1;
	t_img		p2;
	t_img		enemis;
	t_img		coins;
	int			frame;
	int			current_sprite;
	char		**map;
	int			fd;
	char		*str;
}				t_game;

int				ft_strlen(const char *str);
char			*get_next_line(int fd);
char			*ft_strjoin(char const *s1, char const *s2);
char			*ft_strdup(char *src);
void			ft_putnbr(int nb);
char			**ft_split(char const *s, char c);
char			*ft_strjoin(char const *s1, char const *s2);
size_t			ft_strcat(char *dst, const char *src);
size_t			ft_strlcpy(char *dest, const char *src, size_t size);
char			*ft_strdup(char *src);
char			*ft_realloc_str(char *str, size_t new_len);
int				check_map(char **map, t_game *game, int count,
					int size_fst_line);
int				check_map_elements(const char *str, t_game *game, int e_count,
					int p_count);
int				open_window(t_game *game);
void			ft_putstr(char *s);
int				is_map_finishable(t_game *game, int i, int j);
int				find_in_str(char *str);
int				render_map(t_game *game);
void			*render_sprite(t_game *game, int x, int y);
int				handle_keypress(int keycode, t_game *game);
int				close_window(t_game *game);
int 			close_everything(t_game *game, char *str, int fd);
void			destroy_sprites(t_game *game);
void			free_game(t_game *game);

#endif