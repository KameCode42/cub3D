/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_vertical.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: david <david@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/17 13:36:18 by david             #+#    #+#             */
/*   Updated: 2025/05/25 11:26:08 by david            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// =============================================================================
// draw
// =============================================================================
// texture a afficher selon l'orientation du player
// coordonnee pour les bandes verticale a l'ecran
// defini la hauteur du mur
// draw_start et end permet de definir la texture du mur
// plus la dist est petite (proche), plus la hauteur du mur est grand
// tous part du centre (oeil du player), remonte la moitie de l'ecran
// ou descend pour dessiner le mur
// dessine plafond, mur, sol
//
// =============================================================================

int	get_tex_index(t_ray *ray)
{
	if (ray->side == 0)
	{
		if (ray->ray_dir_x > 0)
			return (TEX_E);
		else
			return (TEX_W);
	}
	else
	{
		if (ray->ray_dir_y > 0)
			return (TEX_S);
		else
			return (TEX_N);
	}
}

unsigned int	get_tex_color(t_img *tex, t_ray *ray, int y, int line_h)
{
	int		tex_x;
	int		tex_y;
	double	step;
	double	pos;
	char	*pixel;

	tex_x = (int)(ray->wall_x * (double)tex->width);
	step = (double)tex->height / (double)line_h;
	pos = (y - WIN_HEIGHT / 2 + line_h / 2) * step;
	tex_y = (int)floor(pos);
	if (tex_y < 0)
		tex_y = 0;
	else if (tex_y >= tex->height)
		tex_y = tex->height - 1;
	pixel = tex->addr
		+ tex_y * tex->line_length
		+ tex_x * (tex->bits_per_pixel / 8);
	return (*(unsigned int *)pixel);
}

void	draw(t_ray *ray, int *draw_start, int *draw_end, int *line_h)
{
	*line_h = (int)(WIN_HEIGHT / ray->dist);
	*draw_start = -(*line_h) / 2 + WIN_HEIGHT / 2;
	*draw_end = (*line_h) / 2 + WIN_HEIGHT / 2;
	if (*draw_start < 0)
		*draw_start = 0;
	if (*draw_end >= WIN_HEIGHT)
		*draw_end = WIN_HEIGHT - 1;
}

void	draw_vertical_line(t_game *game, int x, t_ray *ray)
{
	int	draw_start;
	int	draw_end;
	int	line_h;
	int	y;

	draw(ray, &draw_start, &draw_end, &line_h);
	y = 0;
	while (y < draw_start)
		pixel_put(game, x, y++, game->ceiling_color);
	y = draw_start;
	while (y <= draw_end)
	{
		pixel_put(game, x, y, get_tex_color(&game->textures[get_tex_index(ray)],
				ray,
				y,
				line_h));
		y++;
	}
	while (y < WIN_HEIGHT)
		pixel_put(game, x, y++, game->floor_color);
}
