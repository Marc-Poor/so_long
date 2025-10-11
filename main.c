/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfaure <mfaure@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/30 04:41:47 by mfaure            #+#    #+#             */
/*   Updated: 2025/10/11 16:53:40 by mfaure           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include "so_long.h"
#define ESC_KEY 65307

typedef struct	s_vars {
	void	*mlx;
	void	*mlx_window;
}				t_vars;

int	handle_keypress(int keycode, t_vars *vars)
{
	if (keycode == ESC_KEY)
	{
		mlx_destroy_window(vars->mlx, vars->mlx_window);
		exit(0);
	}
	return (0);
}

int close_window(void)
{
    exit(0);
    return (0);
}

int	open_window(void)
{
	t_vars	vars;

	vars.mlx = mlx_init();
	vars.mlx_window = mlx_new_window(vars.mlx, 1920, 1080, "Hello world!");
	mlx_key_hook(vars.mlx_window, handle_keypress, &vars);
	mlx_hook(vars.mlx_window, 17, 0, close_window, NULL);
	mlx_loop(vars.mlx);
	return (0);
}


int	main(int ac, char **av)
{
	char	*str;
	char	*line;
	int		fd;
	t_game	game;

	if (ac != 2)
		return (0);
	fd = open(av[1], O_RDONLY);
    if (fd < 0)
    {
        perror("Error opening file");
        return (1);
    }
	line = get_next_line(fd);
	str = ft_strdup(line);
	while ((line = get_next_line(fd)) != NULL)
	{
		str = ft_realloc_str(str, ft_strlen(str) + ft_strlen(line));
		ft_strcat(str, line);
	}
	if (str == NULL || check_map_elements(str, &game) == -1)
		return (0);
	game.map = ft_split(str, '\n');
	for (int i = 0; game.map[i] != NULL; i++)
		printf("%s\n", game.map[i]);
	if (game.map == NULL || check_map(game.map, &game) == -1)
		return 0;
	open_window();
	return 0;
}