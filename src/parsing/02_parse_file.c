/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   02_parse_file.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: david <david@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/11 13:04:13 by aledos-s          #+#    #+#             */
/*   Updated: 2025/05/23 18:57:22 by david            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	is_empty(char *line)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (line[i] != ' ' && line[i] != '\t'
			&& line[i] != '\n' && line[i] != '\v'
			&& line[i] != '\f' && line[i] != '\r')
			return (0);
		i++;
	}
	return (1);
}

static int	is_graphic_line(char *line)
{
	while (*line == ' ' || *line == '\t')
		line++;
	if (!ft_strncmp(line, "NO", 2) || !ft_strncmp(line, "SO", 2)
		|| !ft_strncmp(line, "WE", 2) || !ft_strncmp(line, "EA", 2)
		|| !ft_strncmp(line, "F", 1) || !ft_strncmp(line, "C", 1))
		return (1);
	return (0);
}

static void	add_graphic_line(t_game *game, char *line)
{
	line = remove_parasite_end(line);
	while (*line == ' ' || *line == '\t')
		line++;
	if (!ft_strncmp(line, "NO ", 3))
		game->texture_paths[0] = ft_strdup(line + 3);
	else if (!ft_strncmp(line, "SO ", 3))
		game->texture_paths[1] = ft_strdup(line + 3);
	else if (!ft_strncmp(line, "WE ", 3))
		game->texture_paths[2] = ft_strdup(line + 3);
	else if (!ft_strncmp(line, "EA ", 3))
		game->texture_paths[3] = ft_strdup(line + 3);
	else if (!ft_strncmp(line, "F ", 2))
		game->floor_color = parse_color(line + 2);
	else if (!ft_strncmp(line, "C ", 2))
		game->ceiling_color = parse_color(line + 2);
}

static void	add_map_line(t_game *game, char *line)
{
	char	**new_grid;
	size_t	i;
	char	*clean_line;

	i = 0;
	clean_line = remove_parasite_end(line);
	new_grid = malloc(sizeof(char *) * (game->map.height + 2));
	if (!new_grid)
		return (perror("Error: "));
	if (game->map.grid)
	{
		while (i < game->map.height)
		{
			new_grid[i] = game->map.grid[i];
			i++;
		}
		free(game->map.grid);
	}
	new_grid[i] = ft_strdup(clean_line);
	new_grid[i + 1] = NULL;
	game->map.grid = new_grid;
	game->map.height++;
}

int	parse_file(t_game *game, char *file)
{
	int		fd;
	char	*line;
	int		map_started;

	map_started = 0;
	game->map.map_path = file;
	fd = open(file, O_RDONLY);
	if (fd < 0)
		return (error_msg("Failed to open file"), 1);
	line = get_next_line(fd);
	while (line)
	{
		if (is_empty(line) && !map_started)
			;
		else if (is_graphic_line(line) && !map_started)
			add_graphic_line(game, line);
		else
		{
			map_started = 1;
			add_map_line(game, line);
		}
		free(line);
		line = get_next_line(fd);
	}
	return (0);
}
