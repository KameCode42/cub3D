/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   05_parse_textures.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aledos-s <alex>                            #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-05-11 17:37:06 by aledos-s          #+#    #+#             */
/*   Updated: 2025-05-11 17:37:06 by aledos-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	load_textures(t_game *game)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		if (!game->texture_paths[i])
			return (error_msg("Missing texture path"), 1);
		game->textures[i].img_ptr = mlx_xpm_file_to_image(game->mlx,
				game->texture_paths[i], &game->textures[i].width,
				&game->textures[i].height);
		if (!game->textures[i].img_ptr)
			return (error_msg("Failed to load texture"), 1);
		game->textures[i].addr = mlx_get_data_addr(game->textures[i].img_ptr,
				&game->textures[i].bits_per_pixel,
				&game->textures[i].line_length,
				&game->textures[i].endian);
		i++;
	}
	return (0);
}
