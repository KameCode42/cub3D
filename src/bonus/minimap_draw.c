/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap_draw.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: david <david@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/22 04:15:42 by aledos-s          #+#    #+#             */
/*   Updated: 2025/05/24 10:17:11 by david            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// =============================================================================
// minimap_draw
// =============================================================================
// Dessine un pixel sur l'image en vérifiant qu'il est dans les limites
// de la minimap
//
// Dessine un carré rempli sur la minimap
//
// Fonction d'initialisation des paramètres de la ligne
// pour l'algorithme de Bresenham
//
// Dessine une ligne entre deux points (pour la direction du joueur)
// Utilise l'algorithme de Bresenham avec vérifications de sécurité
//
// Dessine la bordure de la minimap
// Utilise l'algorithme de Bresenham pour dessiner les lignes
// entre les coins de la minimap
//
// =============================================================================

void	minimap_pixel_put(t_img *img, int x, int y, int color)
{
	char	*dst;

	if (x < 0 || y < 0 || x >= MINIMAP_SIZE || y >= MINIMAP_SIZE || !img->addr)
		return ;
	dst = img->addr + ((y) * img->line_length + (x)
			* (img->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

void	draw_square(t_img *img, t_mmap *mmap, int color)
{
	int	i;
	int	j;

	if (!img || !img->addr || !mmap)
		return ;
	i = 0;
	while (i < mmap->cell_size)
	{
		j = 0;
		while (j < mmap->cell_size)
		{
			minimap_pixel_put(img, mmap->cell_x + i, mmap->cell_y + j, color);
			j++;
		}
		i++;
	}
}

static void	init_line_params(t_mmap *mmap)
{
	mmap->dx = (int)mmap->dir_end_x - (int)mmap->center_x;
	mmap->sx = 1;
	if (mmap->dx < 0)
	{
		mmap->dx = -mmap->dx;
		mmap->sx = -1;
	}
	mmap->dy = (int)mmap->dir_end_y - (int)mmap->center_y;
	mmap->sy = 1;
	if (mmap->dy < 0)
	{
		mmap->dy = -mmap->dy;
		mmap->sy = -1;
	}
	mmap->err = mmap->dx - mmap->dy;
}

void	draw_line(t_img *img, t_mmap *mmap)
{
	int	count;

	if (!img || !img->addr || !mmap)
		return ;
	mmap->x = (int)mmap->center_x;
	mmap->y = (int)mmap->center_y;
	count = 0;
	init_line_params(mmap);
	while ((mmap->x != (int)mmap->dir_end_x
			|| mmap->y != (int)mmap->dir_end_y) && count < MINIMAP_SIZE * 2)
	{
		minimap_pixel_put(img, mmap->x, mmap->y, mmap->player_color);
		mmap->e2 = 2 * mmap->err;
		if (mmap->e2 > -mmap->dy)
		{
			mmap->err -= mmap->dy;
			mmap->x += mmap->sx;
		}
		if (mmap->e2 < mmap->dx)
		{
			mmap->err += mmap->dx;
			mmap->y += mmap->sy;
		}
		count++;
	}
}

void	draw_minimap_border(t_img *img, t_mmap *mmap)
{
	int	i;

	i = 0;
	while (i < mmap->border_size)
	{
		mmap->center_x = i;
		mmap->center_y = 0;
		mmap->dir_end_x = i;
		mmap->dir_end_y = mmap->size - 1;
		draw_line(img, mmap);
		mmap->center_x = mmap->size - i - 1;
		mmap->dir_end_x = mmap->size - i - 1;
		draw_line(img, mmap);
		mmap->center_x = 0;
		mmap->center_y = i;
		mmap->dir_end_x = mmap->size - 1;
		mmap->dir_end_y = i;
		draw_line(img, mmap);
		mmap->center_y = mmap->size - i - 1;
		mmap->dir_end_y = mmap->size - i - 1;
		draw_line(img, mmap);
		i++;
	}
}
