/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_rotate.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: david <david@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/29 09:11:57 by dle-fur           #+#    #+#             */
/*   Updated: 2025/05/30 11:47:11 by david            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	draw_crosshair(t_game *game)
{
	int	cross_x;
	int	cross_y;
	int	delta_x;

	cross_x = WIN_WIDTH / 2;
	cross_y = WIN_HEIGHT / 2;
	delta_x = -10;
	while (delta_x <= 10)
	{
		pixel_put(game, cross_x + delta_x, cross_y, 0x00FF00);
		pixel_put(game, cross_x, cross_y + delta_x, 0x00FF00);
		delta_x++;
	}
}

int	mouse_rotate(int x, int y, void *param)
{
	int		mid_x;
	double	angle;
	t_game	*game;

	game = (t_game *)param;
	mid_x = WIN_WIDTH / 2;
	angle = (x - mid_x) * MOUSE_SENSI;
	(void)y;
	if (angle != 0)
	{
		rotate_player_mouse(game, angle);
		mlx_mouse_move(game->mlx, game->win, mid_x, WIN_HEIGHT / 2);
	}
	return (0);
}
