/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controls_player.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: david <david@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/10 17:05:53 by david             #+#    #+#             */
/*   Updated: 2025/05/18 09:46:16 by david            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	controls_player(t_game *game)
{
	if (game->player.w == true)
		move_forward(game);
	if (game->player.s == true)
		move_backward(game);
	if (game->player.a == true)
		move_left(game);
	if (game->player.d == true)
		move_right(game);
	if (game->player.r_left == true)
		rotate_left(game);
	if (game->player.r_right == true)
		rotate_right(game);
}
