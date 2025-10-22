/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfaure <mfaure@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/17 18:24:05 by mfaure            #+#    #+#             */
/*   Updated: 2025/10/20 15:55:03 by mfaure           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	*render_sprite(t_game *game, int x, int y)
{
	if (game->map[y][x] == '1')
		return (game->wall.ptr);
	else if (game->map[y][x] == '0')
		return (game->grass.ptr);
	else if (game->map[y][x] == 'C')
		return (game->coins.ptr);
	else if (game->map[y][x] == 'E')
		return (game->door.ptr);
	else if (game->map[y][x] == 'D')
		return (game->enemis.ptr);
	else
	{
		game->player.x = x;
		game->player.y = y;
		return (game->p1.ptr);
	}
}

int	render_map(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	while (y < game->map_bottom)
	{
		x = 0;
		while (x < game->map_width)
		{
			mlx_put_image_to_window(game->vars.mlx, game->vars.mlx_window,
				render_sprite(game, x, y), x * 64, y * 64);
			x++;
		}
		y++;
	}
	return (0);
}
