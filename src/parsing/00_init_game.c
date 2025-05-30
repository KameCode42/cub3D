/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   00_init_game.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: david <david@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/09 05:46:11 by aledos-s          #+#    #+#             */
/*   Updated: 2025/05/30 11:31:06 by david            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	init_data(t_game *game)
{
	ft_memset(game, 0, sizeof(t_game));
	ft_memset(&game->img, 0, sizeof(t_img));
	ft_memset(&game->player, 0, sizeof(t_player));
	ft_memset(&game->map, 0, sizeof(t_map));
	ft_memset(&game->ray, 0, sizeof(t_ray));
}

int	init_mlx(t_game *game)
{
	game->mlx = mlx_init();
	if (!game->mlx)
	{
		error_msg("Failed to initialize mlx");
		quit_game(game);
		return (1);
	}
	game->win = mlx_new_window(game->mlx,
			WIN_WIDTH,
			WIN_HEIGHT,
			WIN_TITLE);
	mlx_mouse_hide(game->mlx, game->win);
	return (0);
}

int	init_game(t_game *game, char *file)
{
	init_data(game);
	if (parse_game(game, file))
		return (1);
	if (init_mlx(game))
	{
		free_game(game);
		return (1);
	}
	return (0);
}
