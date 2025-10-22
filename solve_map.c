/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfaure <mfaure@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/17 16:10:03 by mfaure            #+#    #+#             */
/*   Updated: 2025/10/20 21:13:54 by mfaure           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	is_valid(t_game *game, int x, int y, int **visited)
{
	if (x < 0 || y < 0 || y >= game->map_bottom || x >= game->map_width)
		return (0);
	if (game->map[y][x] == '1' || game->map[y][x] == 'D' || visited[y][x])
		return (0);
	return (1);
}

void	flood_fill(t_game *game, int x, int y, int **visited)
{
	if (!is_valid(game, x, y, visited))
		return ;
	visited[y][x] = 1;
	if (game->map[y][x] == 'E')
		return ;
	flood_fill(game, x + 1, y, visited);
	flood_fill(game, x - 1, y, visited);
	flood_fill(game, x, y + 1, visited);
	flood_fill(game, x, y - 1, visited);
}

int	check_is_finishable(t_game *game, int **visited, int i, int j)
{
	while (i < game->map_bottom)
	{
		j = 0;
		while (j < game->map_width)
		{
			if ((game->map[i][j] == 'C' || game->map[i][j] == 'E')
				&& !visited[i][j])
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

void	free_int_tab(int **visited, t_game *game)
{
	int	i;

	i = 0;
	while (i < game->map_bottom)
	{
		free(visited[i]);
		i++;
	}
	free(visited);
}

int	is_map_finishable(t_game *game, int i, int j)
{
	int	**visited;
	int	finishable;

	finishable = 1;
	visited = malloc(sizeof(int *) * game->map_bottom);
	if (!visited)
		return (0);
	while (i < game->map_bottom)
	{
		j = 0;
		visited[i] = malloc(sizeof(int) * game->map_width);
		if (!visited[i])
			return (0);
		while (j < game->map_width)
		{
			visited[i][j] = 0;
			j++;
		}
		i++;
	}
	flood_fill(game, game->player.x, game->player.y, visited);
	finishable = check_is_finishable(game, visited, 0, 0);
	free_int_tab(visited, game);
	return (finishable);
}
