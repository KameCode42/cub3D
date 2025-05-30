/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   05_flood_fill_map.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aledos-s <alex>                            #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-05-21 14:19:49 by aledos-s          #+#    #+#             */
/*   Updated: 2025-05-21 14:19:49 by aledos-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	flood_fill_borders(t_game *game, char **map)
{
	size_t	i;

	i = 0;
	while (i < game->map.height)
	{
		flood_fill(map, 0, i, game->map.height);
		flood_fill(map, game->map.width - 1, i, game->map.height);
		i++;
	}
	i = 0;
	while (i < game->map.width)
	{
		flood_fill(map, i, 0, game->map.height);
		flood_fill(map, i, game->map.height - 1, game->map.height);
		i++;
	}
	return (0);
}

int	flood_fill_map(t_game *game)
{
	char	**flood_map;
	int		result;

	flood_map = dup_map(game->map.grid, game->map.height, game->map.width);
	if (!flood_map)
		return (perror("Failed to allocate memory for flood fill"), 1);
	flood_fill_borders(game, flood_map);
	result = check_valid_map(game, flood_map);
	free_array(flood_map);
	return (result);
}
