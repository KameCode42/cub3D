/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   04_parse_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: david <david@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/09 05:56:29 by aledos-s          #+#    #+#             */
/*   Updated: 2025/06/09 13:44:31 by david            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	find_map_width(t_game *game)
{
	size_t	max_width;
	size_t	i;

	max_width = 0;
	i = 0;
	while (i < game->map.height)
	{
		if (ft_strlen(game->map.grid[i]) > max_width)
			max_width = ft_strlen(game->map.grid[i]);
		i++;
	}
	if (max_width < 2)
		return (error_msg("Invalid width map"), 1);
	game->map.width = max_width;
	return (0);
}

static int	check_valid_chars(t_game *game)
{
	size_t	i;
	size_t	j;
	int		player_count;

	i = 0;
	player_count = 0;
	while (i < game->map.height)
	{
		j = 0;
		while (game->map.grid[i][j])
		{
			if (!is_valid_char(game->map.grid[i][j]))
				return (error_msg("Invalid character in map"), 1);
			if (is_start(game->map.grid[i][j]))
			{
				set_player(game, i, j);
				player_count++;
			}
			j++;
		}
		i++;
	}
	if (player_count != 1)
		return (error_msg("Map must have exactly ONE player"), 1);
	return (0);
}

static int	check_empty_lines(t_game *game)
{
	size_t	i;

	i = 0;
	while (i < game->map.height)
	{
		if (ft_strlen(game->map.grid[i]) == 0)
			return (error_msg("Empty line in map"), 1);
		i++;
	}
	return (0);
}

static int	make_map_rectangular(t_game *game)
{
	char	**new_map;

	new_map = dup_map(game->map.grid, game->map.height, game->map.width);
	if (!new_map)
		return (perror("Failed to allocate memory for rectangular map"), 1);
	free_array(game->map.grid);
	game->map.grid = new_map;
	return (check_valid_map(game, new_map));
}

int	parse_map(t_game *game)
{
	if (find_map_width(game))
		return (1);
	if (check_empty_lines(game))
		return (1);
	if (make_map_rectangular(game))
		return (1);
	if (check_valid_chars(game))
		return (1);
	if (flood_fill_map(game))
		return (1);
	replace_spaces_with_walls(game->map.grid, game->map.height, game->map.width);
	return (0);
}
