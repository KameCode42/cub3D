/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: david <david@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 14:23:16 by aledos-s          #+#    #+#             */
/*   Updated: 2025/06/09 13:51:15 by david            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	is_valid_char(char c)
{
	return (c == '0' || c == '1' || c == ' ' || c == 'N' || c == 'S'
		|| c == 'E' || c == 'W');
}

void	replace_spaces_with_walls(char **map, size_t height, size_t width)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (i < height)
	{
		j = 0;
		while (j < width)
		{
			if (map[i][j] == ' ')
				map[i][j] = '1';
			j++;
		}
		i++;
	}
}

char	*remove_parasite_end(char *str)
{
	int	len;

	len = ft_strlen(str);
	while (len > 0 && (str[len - 1] == '\n'
			|| str[len - 1] == ' ' || str[len - 1] == '\t'))
		str[--len] = '\0';
	return (str);
}

int	check_end_line(t_game *game)
{
	int	i;

	if (!game || !game->map.grid || !game->texture_paths)
		return (error_msg("Invalid game structure"), 1);
	i = 0;
	while (game->map.grid[i])
	{
		if (ft_strlen(game->map.grid[i]) > 0)
			game->map.grid[i] = remove_parasite_end(game->map.grid[i]);
		i++;
	}
	game->texture_paths[0] = remove_parasite_end(game->texture_paths[0]);
	game->texture_paths[1] = remove_parasite_end(game->texture_paths[1]);
	game->texture_paths[2] = remove_parasite_end(game->texture_paths[2]);
	game->texture_paths[3] = remove_parasite_end(game->texture_paths[3]);
	return (0);
}
