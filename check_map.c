/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfaure <mfaure@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/11 15:19:34 by mfaure            #+#    #+#             */
/*   Updated: 2025/10/11 16:41:06 by mfaure           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int check_map(char **map, t_game *game))
{
	int size_fst_line;
	int	count;
	int size_of_column;

	size_fst_line = ft_strlen(map[0]);
	count = 0;
	while (map[count] != NULL)
	{
		if (size_fst_line != ft_strlen(map[count])) {
			perror("non-rectangular shaped map");
			return -1;
			}
		if (map[count][0] != '1' || map[count][size_fst_line - 1] != '1') {
			perror("error no vertical border");
			return -1;
		}
		count++;
	}
	size_of_column = count;
	count = 0;
	while (map[0][count] != '\0') {
		if (map[0][count] != '1' || map[size_of_column - 1][count] != '1') {
			perror("error missing horizontal wall");
			return -1;
		}
		count++;
	}
	map->map_wall = size_fst_line;
	map->map_bottom = size_of_column;
	return (0);
}

int	check_map_elements(const char *str, t_game	*game)
{
	int	e_count = 0;
	int	p_count = 0;
	int	i = 0;
	game->collectible_count = 0;

	while (str[i])
	{
		if (str[i] == 'E')
			e_count++;
		else if (str[i] == 'P')
			p_count++;
		else if (str[i] == 'C')
			game->collectible_count++;
		else if (str[i] != '1' && str[i] != '0' && str[i] != '\n')
		{
			perror("Error: invalid character in map\n");
			return (1);
		}
		i++;
	}

	if (e_count != 1)
	{
		perror("Error: map must contain exactly 1 'E'\n");
		return (1);
	}
	if (p_count != 1)
	{
		perror("Error: map must contain exactly 1 'P'\n");
		return (1);
	}
	if (game->collectible_count < 1)
	{
		perror("Error: map must contain at least 1 'C'\n");
		return (1);
	}
	return (0);
}
