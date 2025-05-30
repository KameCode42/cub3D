/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_file_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aledos-s <alex>                            #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-05-11 11:17:34 by aledos-s          #+#    #+#             */
/*   Updated: 2025-05-11 11:17:34 by aledos-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	error_msg(char *msg)
{
	printf("\n⛔ Error: ");
	printf("\033[1;31m%s\033[0m\n\n", msg);
}

void	flood_fill(char **map, int x, int y, int height)
{
	if (y < 0 || map[y] == NULL || x < 0 || x >= (int)ft_strlen(map[y]))
		return ;
	if (map[y][x] == '1' || map[y][x] == 'F')
		return ;
	map[y][x] = 'F';
	flood_fill(map, x + 1, y, height);
	flood_fill(map, x - 1, y, height);
	flood_fill(map, x, y + 1, height);
	flood_fill(map, x, y - 1, height);
}

char	**dup_map(char **src, size_t height, size_t width)
{
	char	**copy;
	size_t	i;
	size_t	len;

	copy = malloc(sizeof(char *) * (height + 1));
	if (!copy)
		return (NULL);
	i = 0;
	while (i < height)
	{
		copy[i] = malloc(width + 1);
		if (!copy[i])
			return (free_array(copy), NULL);
		len = ft_strlen(src[i]);
		if (len > width)
			len = width;
		ft_memset(copy[i], ' ', width);
		ft_memcpy(copy[i], src[i], len);
		copy[i][width] = '\0';
		i++;
	}
	copy[i] = NULL;
	return (copy);
}

int	check_valid_map(t_game *game, char **map_copy)
{
	size_t	x;
	size_t	y;

	if (map_copy[(int)game->player.pos_y][(int)game->player.pos_x] == 'F')
		return (free_array(map_copy), error_msg("Map not closed"), 1);
	y = 0;
	while (y < game->map.height)
	{
		x = 0;
		while (map_copy[y] && x < ft_strlen(map_copy[y]))
		{
			if (map_copy[y][x] == 'F' && (game->map.grid[y][x] == '0'
				|| game->map.grid[y][x] == 'N' || game->map.grid[y][x] == 'S'
				|| game->map.grid[y][x] == 'E' || game->map.grid[y][x] == 'W'))
				return (free_array(map_copy), error_msg("Map not closed"), 1);
			x++;
		}
		y++;
	}
	return (0);
}
