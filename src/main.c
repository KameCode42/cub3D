/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: david <david@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/08 12:51:08 by aledos-s          #+#    #+#             */
/*   Updated: 2025/05/30 11:38:57 by david            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	game_loop(void *param)
{
	t_game	*game;

	game = (t_game *)param;
	controls_player(game);
	raycast(game);
	draw_minimap(game);
	draw_crosshair(game);
	mlx_put_image_to_window(game->mlx, game->win, game->img.img_ptr, 0, 0);
	return (0);
}

int	main(int argc, char **argv)
{
	t_game	game;

	if (argc != 2)
		return (error_msg("Usage: ./cub3D <map_file.cub>\n"), 1);
	printf("Starting parsing for file: %s\n", argv[1]);
	if (init_game(&game, argv[1]))
	{
		error_msg("Error: Failed to initialize game\n");
		return (1);
	}
	if (parse_texture(&game) || load_textures(&game))
		return (error_msg("Error loading textures\n"), 1);
	init_player(&game);
	game.img.img_ptr = mlx_new_image(game.mlx, WIN_WIDTH, WIN_HEIGHT);
	game.img.addr = mlx_get_data_addr(game.img.img_ptr,
			&game.img.bits_per_pixel,
			&game.img.line_length,
			&game.img.endian);
	setup_hook(&game);
	mlx_loop(game.mlx);
	quit_game(&game);
	return (0);
}
