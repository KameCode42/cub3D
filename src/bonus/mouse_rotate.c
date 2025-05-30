/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_rotate.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dle-fur <dle-fur@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/29 09:11:57 by dle-fur           #+#    #+#             */
/*   Updated: 2025/05/29 13:40:59 by dle-fur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

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
