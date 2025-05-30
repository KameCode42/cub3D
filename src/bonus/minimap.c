/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: david <david@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/22 04:15:42 by aledos-s          #+#    #+#             */
/*   Updated: 2025/05/24 10:19:35 by david            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// =============================================================================
// minimap
// =============================================================================
// Initialise la structure de la minimap avec les valeurs par défaut
// 
// Dessine la ligne de direction du joueur
//
// Dessine le point représentant le joueur
//
// Fonction principale pour dessiner la minimap
// Cette fonction est appelée à chaque frame pour mettre à jour la minimap
//
// Dessine la bordure de la minimap
// Utilise l'algorithme de Bresenham pour dessiner les lignes
// entre les coins de la minimap
//
// =============================================================================

void	init_minimap(t_mmap *mmap)
{
	mmap->size = MINIMAP_SIZE;
	mmap->cell_size = CELL_SIZE;
	mmap->wall_color = WALL_COLOR;
	mmap->floor_color = FLOOR_COLOR;
	mmap->player_color = PLAYER_COLOR;
	mmap->border_size = MINIMAP_BORDER;
	mmap->border_color = BORDER_COLOR;
	mmap->player_size = PLAYER_SIZE;
	mmap->dir_length = DIR_LINE_LENGTH;
	mmap->center_x = mmap->size / 2;
	mmap->center_y = mmap->size / 2;
	mmap->visible_cells = mmap->size / mmap->cell_size;
}

static void	draw_player_direction(t_game *game, t_mmap *mmap)
{
	double	dir_x;
	double	dir_y;

	dir_x = game->player.dir_x * mmap->dir_length;
	dir_y = game->player.dir_y * mmap->dir_length;
	mmap->center_x = mmap->size / 2;
	mmap->center_y = mmap->size / 2;
	mmap->dir_end_x = mmap->center_x + dir_x;
	mmap->dir_end_y = mmap->center_y + dir_y;
	draw_line(&game->img, mmap);
}

static void	draw_player_dot(t_game *game, t_mmap *mmap)
{
	t_mmap	player_mmap;

	player_mmap = *mmap;
	player_mmap.cell_x = mmap->size / 2 - player_mmap.player_size / 2;
	player_mmap.cell_y = mmap->size / 2 - player_mmap.player_size / 2;
	player_mmap.cell_size = player_mmap.player_size;
	draw_square(&game->img, &player_mmap, player_mmap.player_color);
}

void	draw_minimap(t_game *game)
{
	t_mmap	mmap;

	if (!game || !game->img.addr)
		return ;
	init_minimap(&mmap);
	draw_minimap_border(&game->img, &mmap);
	draw_minimap_cells(game, &mmap);
	draw_player_dot(game, &mmap);
	draw_player_direction(game, &mmap);
}
