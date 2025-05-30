/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hooks.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dle-fur <dle-fur@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/23 18:27:56 by david             #+#    #+#             */
/*   Updated: 2025/05/29 13:05:11 by dle-fur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	key_press(int key, void *param)
{
	t_game	*game;

	game = (t_game *)param;
	if (key == KEY_ESC)
		quit_game(game);
	else if (key == KEY_W)
		game->player.w = true;
	else if (key == KEY_A)
		game->player.a = true;
	else if (key == KEY_S)
		game->player.s = true;
	else if (key == KEY_D)
		game->player.d = true;
	else if (key == KEY_LEFT)
		game->player.r_left = true;
	else if (key == KEY_RIGHT)
		game->player.r_right = true;
	return (0);
}

int	key_release(int key, void *param)
{
	t_game	*game;

	game = (t_game *)param;
	if (key == KEY_W)
		game->player.w = false;
	else if (key == KEY_A)
		game->player.a = false;
	else if (key == KEY_S)
		game->player.s = false;
	else if (key == KEY_D)
		game->player.d = false;
	else if (key == KEY_LEFT)
		game->player.r_left = false;
	else if (key == KEY_RIGHT)
		game->player.r_right = false;
	return (0);
}

void	setup_hook(t_game *game)
{
	mlx_hook(game->win, 2, (1L << 0), (void *)key_press, game);
	mlx_hook(game->win, 3, (1L << 1), (void *)key_release, game);
	mlx_hook(game->win, 17, (1L << 17), (void *)quit_game, game);
	mlx_hook(game->win, 6, (1L << 6), (void *)mouse_rotate, game);
	mlx_loop_hook(game->mlx, (void *)game_loop, game);
}
