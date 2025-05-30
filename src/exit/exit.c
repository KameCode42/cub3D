/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: david <david@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/08 13:16:05 by aledos-s          #+#    #+#             */
/*   Updated: 2025/05/25 10:29:51 by david            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	exit_mlx(t_game *game)
{
	if (game->mlx)
	{
		if (game->texture_paths[0])
			mlx_destroy_image(game->mlx, game->textures[0].img_ptr);
		if (game->texture_paths[1])
			mlx_destroy_image(game->mlx, game->textures[1].img_ptr);
		if (game->texture_paths[2])
			mlx_destroy_image(game->mlx, game->textures[2].img_ptr);
		if (game->texture_paths[3])
			mlx_destroy_image(game->mlx, game->textures[3].img_ptr);
		if (game->img.img_ptr)
			mlx_destroy_image(game->mlx, game->img.img_ptr);
		if (game->win)
			mlx_destroy_window(game->mlx, game->win);
		mlx_destroy_display(game->mlx);
		free(game->mlx);
	}
}

void	quit_game(t_game *game)
{
	exit_mlx(game);
	free_game(game);
	exit(0);
}
