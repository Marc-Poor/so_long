/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfaure <mfaure@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/30 04:41:47 by mfaure            #+#    #+#             */
/*   Updated: 2025/10/22 14:58:01 by mfaure           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	compare(char *av, int fd)
{
	int		len;
	char	*str;
	int		i;

	str = ".ber\0";
	len = ft_strlen(av) - 4;
	i = 0;
	while (i < 4)
	{
		if (av[len] != str[i])
		{
			close(fd);
			ft_putstr("no .ber\n");
			return (0);
		}
		len++;
		i++;
	}
	return (1);
}

void	find_player(t_game *game, char **map)
{
	int	x;
	int	y;

	y = 0;
	while (map[y] != NULL)
	{
		x = 0;
		while (map[y][x])
		{
			if (map[y][x] == 'P')
			{
				game->player.x = x;
				game->player.y = y;
			}
			x++;
		}
		y++;
	}
}

int	close_everything(t_game *game, char *str, int fd)
{
	int	i;

	i = 0;
	if (game->map)
	{
		while (game->map[i] != NULL)
		{
			free(game->map[i]);
			i++;
		}
		free(game->map);
	}
	if (str)
		free(str);
	if (fd >= 0)
		close(fd);
	return (0);
}

int	error_handling(t_game *game, char *str, int fd)
{
	if (game->str == NULL)
		return (close_everything(game, game->str, game->fd));
	if (check_map_elements(game->str, game, 0, 0) == -1)
		return (close_everything(game, game->str, game->fd));
	game->map = ft_split(game->str, '\n');
	if (game->map == NULL || check_map(game->map, game, 0,
			ft_strlen(game->map[0])) == -1)
		return (close_everything(game, str, fd));
	find_player(game, game->map);
	if (is_map_finishable(game, 0, 0) == 0)
	{
		ft_putstr("non solvable map\n");
		return (close_everything(game, str, fd));
	}
	game->player.moves = 1;
	return (1);
}

int	main(int ac, char **av)
{
	char	*line;
	t_game	game;

	if (ac != 2)
		return (0);
	game.map = NULL;
	game.fd = open(av[1], O_RDONLY);
	if (game.fd < 0 || compare(av[1], game.fd) == 0)
		return (1);
	line = get_next_line(game.fd);
	game.str = ft_strdup("");
	if (line == NULL || game.str == NULL)
		return (0);
	while (line != NULL)
	{
		game.str = ft_realloc_str(game.str, ft_strlen(game.str)
				+ ft_strlen(line));
		ft_strcat(game.str, line);
		free(line);
		line = get_next_line(game.fd);
	}
	if (!error_handling(&game, game.str, game.fd))
		return (0);
	open_window(&game);
	close_everything(&game, game.str, game.fd);
	return (0);
}

// for (int i = 0; game.map[i] != NULL; i++)
//	printf("%s\n", game.map[i]);