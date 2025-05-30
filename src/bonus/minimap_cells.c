/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap_cells.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: david <david@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/22 04:15:42 by aledos-s          #+#    #+#             */
/*   Updated: 2025/05/24 10:04:34 by david            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// =============================================================================
// minimap_cells
// =============================================================================
// Dessine des carrés sur la minimap (murs ou sol, 1 ou 0)
//
// Calcule les coordonnées de la carte en fonction de la position du joueur
// et de la taille de la cellule
//
// Dessine les cellules de la carte sur la minimap
//
// =============================================================================

static void	draw_squares(t_game *game, t_mmap *mmap)
{
	if (!game || !mmap)
		return ;
	if (mmap->map_x >= 0 && mmap->map_y >= 0
		&& mmap->map_y < (int)game->map.height
		&& mmap->map_x < (int)game->map.width
		&& game->map.grid && game->map.grid[mmap->map_y])
	{
		if (game->map.grid[mmap->map_y][mmap->map_x] == CELL_WALL)
			draw_square(&game->img, mmap, mmap->wall_color);
		else
			draw_square(&game->img, mmap, mmap->floor_color);
	}
	else
		draw_square(&game->img, mmap, 0x000000);
}

static void	calculate_map_coordinates(t_game *game, t_mmap *mmap, int x, int y)
{
	mmap->map_x = (int)game->player.pos_x + (x - mmap->visible_cells / 2);
	mmap->map_y = (int)game->player.pos_y + (y - mmap->visible_cells / 2);
	mmap->cell_x = x * mmap->cell_size;
	mmap->cell_y = y * mmap->cell_size;
}

void	draw_minimap_cells(t_game *game, t_mmap *mmap)
{
	int	x;
	int	y;

	y = 0;
	while (y < mmap->visible_cells)
	{
		x = 0;
		while (x < mmap->visible_cells)
		{
			calculate_map_coordinates(game, mmap, x, y);
			draw_squares(game, mmap);
			x++;
		}
		y++;
	}
}
