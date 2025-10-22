/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_window.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfaure <mfaure@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 16:11:02 by mfaure            #+#    #+#             */
/*   Updated: 2025/10/22 14:47:27 by mfaure           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_sprites(t_game *game)
{
	if (!game->wall.ptr || !game->grass.ptr || !game->p1.ptr || !game->p2.ptr
		|| !game->door.ptr || !game->enemis.ptr)
		return (0);
	return (1);
}

int	load_sprites(t_game *game)
{
	int	width;
	int	height;

	game->wall.ptr = mlx_xpm_file_to_image(game->vars.mlx, "sprites/wall.xpm",
			&width, &height);
	game->grass.ptr = mlx_xpm_file_to_image(game->vars.mlx,
			"sprites/good_grass.xpm", &width, &height);
	game->door.ptr = mlx_xpm_file_to_image(game->vars.mlx, "sprites/black.xpm",
			&width, &height);
	game->p1.ptr = mlx_xpm_file_to_image(game->vars.mlx, "sprites/link01.xpm",
			&width, &height);
	game->p2.ptr = mlx_xpm_file_to_image(game->vars.mlx, "sprites/link02.xpm",
			&width, &height);
	game->enemis.ptr = mlx_xpm_file_to_image(game->vars.mlx,
			"sprites/enemis.xpm", &width, &height);
	game->coins.ptr = mlx_xpm_file_to_image(game->vars.mlx, "sprites/force.xpm",
			&width, &height);
	if (!check_sprites(game))
	{
		free_game(game);
		close_everything(game, game->str, game->fd);
		perror("Failed to load sprites");
		exit(0);
	}
	return (0);
}

int	animate_player(t_game *game)
{
	int		x;
	int		y;
	void	*sprite;

	x = game->player.x;
	y = game->player.y;
	if (game->current_sprite == 0)
		game->current_sprite = 1;
	else
		game->current_sprite = 0;
	if (game->current_sprite == 0)
		sprite = game->p1.ptr;
	else
		sprite = game->p2.ptr;
	mlx_put_image_to_window(game->vars.mlx, game->vars.mlx_window, sprite, x
		* 64, y * 64);
	usleep(100000);
	return (0);
}

int	open_window(t_game *game)
{
	game->frame = 0;
	game->current_sprite = 0;
	game->vars.mlx = mlx_init();
	if (!game->vars.mlx)
		return (1);
	game->vars.mlx_window = mlx_new_window(game->vars.mlx, 64 * game->map_width,
			64 * game->map_bottom, "So_Long_The_New_Legend_of_Zelda");
	load_sprites(game);
	render_map(game);
	mlx_loop_hook(game->vars.mlx, animate_player, game);
	mlx_key_hook(game->vars.mlx_window, handle_keypress, game);
	mlx_hook(game->vars.mlx_window, 17, 0, close_window, game);
	mlx_loop(game->vars.mlx);
	return (0);
}
