/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: david <david@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/10 17:05:29 by david             #+#    #+#             */
/*   Updated: 2025/05/30 13:28:10 by david            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	is_wall(t_game *game, double x, double y)
{
	int	map_x;
	int	map_y;

	map_x = (int)x;
	map_y = (int)y;
	if (map_y < 0 || map_y >= (int)game->map.height)
		return (1);
	if (map_x < 0 || map_x >= (int)ft_strlen(game->map.grid[map_y]))
		return (1);
	if (game->map.grid[map_y][map_x] == CELL_WALL
		|| game->map.grid[map_y][map_x] == ' ')
		return (1);
	return (0);
}

void	move_forward(t_game *game)
{
	double	new_x;
	double	new_y;
	double	check_x;
	double	check_y;

	new_x = game->player.pos_x + game->player.dir_x * MOVE_SPEED;
	new_y = game->player.pos_y + game->player.dir_y * MOVE_SPEED;
	check_x = new_x + game->player.dir_x * PLAYER_RADIUS;
	if (is_wall(game, check_x, game->player.pos_y) == 0)
		game->player.pos_x = new_x;
	check_y = new_y + game->player.dir_y * PLAYER_RADIUS;
	if (is_wall(game, game->player.pos_x, check_y) == 0)
		game->player.pos_y = new_y;
}

void	move_backward(t_game *game)
{
	double	new_x;
	double	new_y;
	double	check_x;
	double	check_y;

	new_x = game->player.pos_x - game->player.dir_x * MOVE_SPEED;
	new_y = game->player.pos_y - game->player.dir_y * MOVE_SPEED;
	check_x = new_x - game->player.dir_x * PLAYER_RADIUS;
	if (is_wall(game, check_x, game->player.pos_y) == 0)
		game->player.pos_x = new_x;
	check_y = new_y - game->player.dir_y * PLAYER_RADIUS;
	if (is_wall(game, game->player.pos_x, check_y) == 0)
		game->player.pos_y = new_y;
}

void	move_left(t_game *game)
{
	double	new_x;
	double	new_y;
	double	check_x;
	double	check_y;

	new_x = game->player.pos_x - game->player.plane_x * MOVE_SPEED;
	new_y = game->player.pos_y - game->player.plane_y * MOVE_SPEED;
	check_x = new_x - game->player.plane_x * PLAYER_RADIUS;
	if (is_wall(game, check_x, game->player.pos_y) == 0)
		game->player.pos_x = new_x;
	check_y = new_y - game->player.plane_y * PLAYER_RADIUS;
	if (is_wall(game, game->player.pos_x, check_y) == 0)
		game->player.pos_y = new_y;
}

void	move_right(t_game *game)
{
	double	new_x;
	double	new_y;
	double	check_x;
	double	check_y;

	new_x = game->player.pos_x + game->player.plane_x * MOVE_SPEED;
	new_y = game->player.pos_y + game->player.plane_y * MOVE_SPEED;
	check_x = new_x + game->player.plane_x * PLAYER_RADIUS;
	if (is_wall(game, check_x, game->player.pos_y) == 0)
		game->player.pos_x = new_x;
	check_y = new_y + game->player.plane_y * PLAYER_RADIUS;
	if (is_wall(game, game->player.pos_x, check_y) == 0)
		game->player.pos_y = new_y;
}
