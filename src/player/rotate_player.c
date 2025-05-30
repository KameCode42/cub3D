/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_player.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dle-fur <dle-fur@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/10 17:09:17 by david             #+#    #+#             */
/*   Updated: 2025/05/29 13:47:03 by dle-fur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	rotate_left(t_game *game)
{
	double	old_dx;
	double	old_dy;
	double	old_px;
	double	old_py;

	game->player.angle -= ROT_SPEED;
	old_dx = game->player.dir_x;
	old_dy = game->player.dir_y;
	old_px = game->player.plane_x;
	old_py = game->player.plane_y;
	game->player.dir_x = old_dx * cos(ROT_SPEED) + old_dy * sin(ROT_SPEED);
	game->player.dir_y = -old_dx * sin(ROT_SPEED) + old_dy * cos(ROT_SPEED);
	game->player.plane_x = old_px * cos(ROT_SPEED) + old_py * sin(ROT_SPEED);
	game->player.plane_y = -old_px * sin(ROT_SPEED) + old_py * cos(ROT_SPEED);
}

void	rotate_right(t_game *game)
{
	double	old_dx;
	double	old_dy;
	double	old_px;
	double	old_py;

	game->player.angle += ROT_SPEED;
	old_dx = game->player.dir_x;
	old_dy = game->player.dir_y;
	old_px = game->player.plane_x;
	old_py = game->player.plane_y;
	game->player.dir_x = old_dx * cos(ROT_SPEED) - old_dy * sin(ROT_SPEED);
	game->player.dir_y = old_dx * sin(ROT_SPEED) + old_dy * cos(ROT_SPEED);
	game->player.plane_x = old_px * cos(ROT_SPEED) - old_py * sin(ROT_SPEED);
	game->player.plane_y = old_px * sin(ROT_SPEED) + old_py * cos(ROT_SPEED);
}

void	rotate_player_mouse(t_game *game, double angle)
{
	double	old_dx;
	double	old_dy;
	double	old_px;
	double	old_py;


	old_dx = game->player.dir_x;
	old_dy = game->player.dir_y;
	old_px = game->player.plane_x;
	old_py = game->player.plane_y;
	game->player.dir_x = old_dx * cos(angle) - old_dy * sin(angle);
	game->player.dir_y = old_dx * sin(angle) + old_dy * cos(angle);
	game->player.plane_x = old_px * cos(angle) - old_py * sin(angle);
	game->player.plane_y = old_px * sin(angle) + old_py * cos(angle);
}
