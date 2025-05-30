/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   01_parse_game.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aledos-s <alex>                            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-05-09 05:46:11 by aledos-s          #+#    #+#             */
/*   Updated: 2025-05-09 05:46:11 by aledos-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	check_extension(char *file, char *ext)
{
	int	file_len;
	int	ext_len;

	if (!file)
		return (error_msg("Missing file path"), 1);
	if (!ext)
		return (error_msg("Missing extension parameter"), 1);
	file_len = strlen(file);
	ext_len = strlen(ext);
	if (file_len < ext_len)
		return (error_msg("Invalid file path length"), 1);
	if (strncmp(file + file_len - ext_len, ext, ext_len) != 0)
	{
		error_msg("Invalid extension [*.cub/*.xpm]");
		return (1);
	}
	return (0);
}

int	parse_game(t_game *game, char *file)
{
	if (check_extension(file, ".cub"))
		return (1);
	if (parse_file(game, file))
		return (1);
	if (check_end_line(game))
		return (1);
	if (parse_map(game))
		return (1);
	if (parse_texture(game))
		return (1);
	return (0);
}
