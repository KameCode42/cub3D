/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pixel_put.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: david <david@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/17 10:54:01 by david             #+#    #+#             */
/*   Updated: 2025/05/25 10:28:59 by david            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// =============================================================================
// pixel_put :
// =============================================================================
// Donne le pouvoir de tracer la moindre particule de ton monde
// c'est la fondation ensuite ->
// ray-casting, textures, sprites, mini-map — se fait par-dessus ce mécanisme
//
//==============================================================================

void	pixel_put(t_game *game, int x, int y, int color)
{
	char	*dst;

	dst = game->img.addr
		+ (y * game->img.line_length)
		+ (x * (game->img.bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}
