/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfaure <mfaure@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/17 18:27:33 by mfaure            #+#    #+#             */
/*   Updated: 2025/10/20 21:24:44 by mfaure           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	move_player(t_game *game, int new_x, int new_y)
{
	if (game->map[new_y][new_x] == '1' || (game->map[new_y][new_x] == 'E'
			&& game->collectible_count > 0))
		return ;
	if (game->map[new_y][new_x] == 'D' || (game->map[new_y][new_x] == 'E'
			&& game->collectible_count < 1))
	{
		close_everything(game, game->str, game->fd);
		close_window(game);
		exit(0);
	}
	if (game->map[new_y][new_x] == 'C')
		game->collectible_count--;
	game->map[game->player.y][game->player.x] = '0';
	game->map[new_y][new_x] = 'P';
	game->player.x = new_x;
	game->player.y = new_y;
	ft_putnbr(game->player.moves++);
	ft_putstr("\n");
	render_map(game);
	return ;
}

int	handle_keypress(int keycode, t_game *game)
{
	if (keycode == ESC_KEY)
	{
		close_everything(game, game->str, game->fd);
		close_window(game);
		exit(0);
	}
	else if (keycode == KEY_W || keycode == KEY_UP)
		move_player(game, game->player.x, game->player.y - 1);
	else if (keycode == KEY_S || keycode == KEY_DOWN)
		move_player(game, game->player.x, game->player.y + 1);
	else if (keycode == KEY_A || keycode == KEY_LEFT)
		move_player(game, game->player.x - 1, game->player.y);
	else if (keycode == KEY_D || keycode == KEY_RIGHT)
		move_player(game, game->player.x + 1, game->player.y);
	return (0);
}
