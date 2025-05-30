/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: david <david@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/10 15:20:19 by david             #+#    #+#             */
/*   Updated: 2025/05/24 17:10:13 by david            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

double	angle_direction(char dir)
{
	if (dir == START_N)
		return (ANGLE_N);
	if (dir == START_S)
		return (ANGLE_S);
	if (dir == START_E)
		return (ANGLE_E);
	if (dir == START_W)
		return (ANGLE_W);
	return (0.0);
}

int	is_start(char c)
{
	return (c == START_N || c == START_S || c == START_E || c == START_W);
}

void	set_player(t_game *game, size_t i, size_t j)
{
	game->player.pos_x = (double)j + 0.5;
	game->player.pos_y = (double)i + 0.5;
	game->player.angle = angle_direction(game->map.grid[i][j]);
	game->player.dir_x = cos(game->player.angle);
	game->player.dir_y = sin(game->player.angle);
	game->player.plane_x = -game->player.dir_y * PLAN_LEN;
	game->player.plane_y = game->player.dir_x * PLAN_LEN;
	game->player.w = false;
	game->player.a = false;
	game->player.s = false;
	game->player.d = false;
	game->player.r_left = false;
	game->player.r_right = false;
	game->map.grid[i][j] = '0';
}

void	init_player(t_game *game)
{
	size_t	i;
	size_t	j;
	size_t	len;

	i = 0;
	while (i < game->map.height)
	{
		len = ft_strlen(game->map.grid[i]);
		j = 0;
		while (j < len)
		{
			if (is_start(game->map.grid[i][j]))
			{
				set_player(game, i, j);
				return ;
			}
			j++;
		}
		i++;
	}
}
