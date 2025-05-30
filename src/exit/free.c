/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: david <david@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/09 09:22:48 by aledos-s          #+#    #+#             */
/*   Updated: 2025/05/25 10:29:13 by david            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	free_array(char **array)
{
	int	i;

	if (!array)
		return ;
	i = 0;
	while (array[i])
	{
		free(array[i]);
		i++;
	}
	free(array);
	array = NULL;
}

void	free_map(t_map *map)
{
	if (map->grid)
		free_array(map->grid);
	ft_memset(map, 0, sizeof(t_map));
}

void	free_game(t_game *game)
{
	int	i;

	if (!game)
		return ;
	free_map(&game->map);
	i = 0;
	while (i < 4)
	{
		if (game->texture_paths[i])
		{
			free(game->texture_paths[i]);
			game->texture_paths[i] = NULL;
		}
		i++;
	}
}
