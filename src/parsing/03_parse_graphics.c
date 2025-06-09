/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   02_parse_colors.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aledos-s <alex>                            #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-05-11 12:21:15 by aledos-s          #+#    #+#             */
/*   Updated: 2025-05-11 12:21:15 by aledos-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	check_file_valid(const char *filepath)
{
	int	fd;

	fd = open(filepath, O_RDONLY);
	if (fd < 0)
	{
		perror(filepath);
		return (1);
	}
	close(fd);
	return (0);
}

static int	convert_rgb_values(char *str, int *i)
{
	char	**split;
	int		value;
	int		r;
	int		g;
	int		b;

	split = ft_split(str, ',');
	if (!split || !split[0] || !split[1] || !split[2] || split[3])
		return (-1);
	*i = 0;
	while (split[*i])
	{
		value = ft_atoi(split[*i]);
		if (value < 0 || value > 255)
			return (-1);
		(*i)++;
	}
	r = ft_atoi(split[0]);
	g = ft_atoi(split[1]);
	b = ft_atoi(split[2]);
	free_array(split);
	return ((r << 16) | (g << 8) | b);
}

int	parse_color(char *color)
{
	int		rgb_color;
	int		i;

	i = 0;
	if (!color)
		return (error_msg("Missing color configuration"), -1);
	color = remove_parasite_end(color);
	if (ft_strlen(color) < 5)
		return (error_msg("Invalid color format"), -1);
	while (*color == ' ' || *color == '\t')
		color++;
	rgb_color = convert_rgb_values(color, &i);
	if (rgb_color == -1)
		return (error_msg("Invalid color format"), -1);
	return (rgb_color);
}

int	parse_texture(t_game *game)
{
	if (check_extension(game->texture_paths[0], ".xpm")
		|| check_file_valid(game->texture_paths[0]))
		return (error_msg("Invalid or missing texture file (NO)"), 1);
	if (check_extension(game->texture_paths[1], ".xpm")
		|| check_file_valid(game->texture_paths[1]))
		return (error_msg("Invalid or missing texture file (SO)"), 1);
	if (check_extension(game->texture_paths[2], ".xpm")
		|| check_file_valid(game->texture_paths[2]))
		return (error_msg("Invalid or missing texture file (WE)"), 1);
	if (check_extension(game->texture_paths[3], ".xpm")
		|| check_file_valid(game->texture_paths[3]))
		return (error_msg("Invalid or missing texture file (EA)"), 1);
	if (game->floor_color < 0 || game->floor_color > 16777215)
		return (error_msg("Invalid floor color"), 1);
	if (game->ceiling_color < 0 || game->ceiling_color > 16777215)
		return (error_msg("Invalid ceiling color"), 1);
	return (0);
}
