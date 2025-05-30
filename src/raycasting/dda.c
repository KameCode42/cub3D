/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dda.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: david <david@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/17 15:11:15 by david             #+#    #+#             */
/*   Updated: 2025/05/24 10:25:36 by david            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// =============================================================================
// dda
// =============================================================================
// DDA (Digital Differential Analyzer) est l’algorithme de ray‐casting
// utilisé dans Cub3D pour détecter à partir de la position du joueur
// où un rayon frappe un mur sur une carte en grille 2D
// Dès qu’on entre dans une case « mur », on sait où s’est produit l’impact
//
// =============================================================================

static void	dda_loop(t_game *game, t_ray *ray)
{
	while (game->map.grid[ray->map_y][ray->map_x] != CELL_WALL)
	{
		if (ray->side_dist_x < ray->side_dist_y)
		{
			ray->side_dist_x += ray->delta_dist_x;
			ray->map_x += ray->step_x;
			ray->side = 0;
		}
		else
		{
			ray->side_dist_y += ray->delta_dist_y;
			ray->map_y += ray->step_y;
			ray->side = 1;
		}
	}
}

void	perform_dda(t_game *game, t_ray *ray)
{
	dda_loop(game, ray);
	if (ray->side == 0)
	{
		ray->dist = (ray->map_x - game->player.pos_x + (1 - ray->step_x) / 2)
			/ ray->ray_dir_x;
		ray->wall_x = game->player.pos_y + (ray->dist * ray->ray_dir_y);
	}
	else
	{
		ray->dist = (ray->map_y - game->player.pos_y + (1 - ray->step_y) / 2)
			/ ray->ray_dir_y;
		ray->wall_x = game->player.pos_x + (ray->dist * ray->ray_dir_x);
	}
	ray->wall_x -= floor(ray->wall_x);
}
