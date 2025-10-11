/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfaure <mfaure@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 14:47:44 by mfaure            #+#    #+#             */
/*   Updated: 2025/10/07 17:12:11 by mfaure           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	find_in_str(char *str)
{
	int	i;

	i = 0;
	while (str && str[i])
	{
		if (str[i] == '\n')
			return (-1);
		i++;
	}
	return (1);
}

int	find_limb(char *str)
{
	int	limb;

	limb = 0;
	while (str[limb] != '\n' && str[limb] != '\0')
		limb++;
	if (str[limb] == '\n')
		limb++;
	return (limb);
}

char	*amputate_str(char *str)
{
	int		strlen;
	int		limb;
	char	*keeper;
	int		i;

	strlen = ft_strlen(str);
	limb = find_limb(str);
	if (limb == strlen)
		return (NULL);
	keeper = malloc(sizeof(char) * (strlen - limb) + 1);
	i = 0;
	while (str[limb + i] != '\0')
	{
		keeper[i] = str[limb + i];
		i++;
	}
	keeper[i] = '\0';
	return (keeper);
}

char	*get_next_line(int fd)
{
	char		*str;
	char		*buffer;
	static char	*keeper;
	int			size;
	char		*temp;

	if (fd < 0 || BUFFER_SIZE < 0)
		return (NULL);
	size = 1;
	str = ft_strdup("");
	buffer = malloc((sizeof(char) * BUFFER_SIZE) + 1);
	if (keeper)
	{
		temp = ft_strjoin(str, keeper);
		free(str);
		str = temp;
		free(keeper);
	}
	size = read(fd, buffer, BUFFER_SIZE);
	if (size == -1)
		return (free(buffer), free(str), NULL);
	while (size > 0)
	{
		buffer[size] = '\0';
		char	*temp2 = ft_strjoin(str, buffer);
		free(str);
		str = temp2;
		if (find_in_str(str) == -1)
			break ;
		size = read(fd, buffer, BUFFER_SIZE);
		if (size == -1)
			return (free(buffer), free(str), NULL);
	}
	free(buffer);
	if (size == 0 && str[0] == '\0')
		return (free(str), NULL);
	keeper = amputate_str(str);
	str[find_limb(str)] = '\0';
	return (str);
}