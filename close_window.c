/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close_window.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfaure <mfaure@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/22 14:48:15 by mfaure            #+#    #+#             */
/*   Updated: 2025/10/22 14:49:04 by mfaure           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	destroy_sprites(t_game *game)
{
	if (!game || !game->vars.mlx)
		return ;
	if (game->wall.ptr)
		mlx_destroy_image(game->vars.mlx, game->wall.ptr);
	if (game->grass.ptr)
		mlx_destroy_image(game->vars.mlx, game->grass.ptr);
	if (game->p1.ptr)
		mlx_destroy_image(game->vars.mlx, game->p1.ptr);
	if (game->p2.ptr)
		mlx_destroy_image(game->vars.mlx, game->p2.ptr);
	if (game->door.ptr)
		mlx_destroy_image(game->vars.mlx, game->door.ptr);
	if (game->enemis.ptr)
		mlx_destroy_image(game->vars.mlx, game->enemis.ptr);
	if (game->coins.ptr)
		mlx_destroy_image(game->vars.mlx, game->coins.ptr);
}

void	free_game(t_game *game)
{
	if (!game)
		return ;
	if (game->vars.mlx)
	{
		destroy_sprites(game);
		if (game->vars.mlx_window)
			mlx_destroy_window(game->vars.mlx, game->vars.mlx_window);
		mlx_destroy_display(game->vars.mlx);
		free(game->vars.mlx);
		game->vars.mlx = NULL;
	}
}

int	close_window(t_game *game)
{
	free_game(game);
	exit(0);
	return (0);
}
