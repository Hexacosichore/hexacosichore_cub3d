/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbarbry <kbarbry@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 03:47:47 by kbarbry           #+#    #+#             */
/*   Updated: 2022/01/23 02:37:14 by kbarbry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

static char	*find_start_map(int fd)
{
	char	*line;
	int		i;
	int		find;

	i = 0;
	find = 0;
	line = get_next_line(fd);
	while (!find)
	{
		while (ft_isspace(line[i]) && line[i] != '\n')
			i++;
		if (ft_isdigit(line[i]))
			find = 1;
		else
		{
			ft_strdel(&line);
			line = get_next_line(fd);
		}
	}
	return (line);
}

static void	find_biggest_line(t_cub3d *cub3d)
{
	int		fd;
	int		biggest;
	char	*line;
	int		size;

	cub3d->height_map = 0;
	fd = open(cub3d->file, O_RDONLY);
	biggest = 0;
	line = find_start_map(fd);
	while (line && line[0] != '\n')
	{
		size = ft_strlen(line) - 1;
		if (size > biggest)
			biggest = size;
		ft_strdel(&line);
		line = get_next_line(fd);
		cub3d->height_map++;
	}
	ft_strdel(&line);
	cub3d->width_map = biggest;
}

static void	treat_line(char *line, t_cub3d *cub3d, int fd)
{
	static int	info = 0;
	int			i;

	i = 0;
	while (line && line[i] != '\n' && ft_isspace(line[i]))
		i++;
	if (line[0] == '\n' || info == 7)
		return ;
	if (ft_isdigit(line[i]) && info != 6)
		ft_error("file.cub doesn't have all the infos needed.", 1, cub3d);
	if (ft_isdigit(line[i]))
	{
		find_biggest_line(cub3d);
		init_map(line, cub3d, fd, 0);
		info++;
	}
	else
	{
		init_texture(line, cub3d);
		info++;
	}
	if (info == 7)
		cub3d->okay_we_have_everything = 1;
}

void	init_parsing(char *file, t_cub3d *cub3d)
{
	int		fd;
	char	*line;

	cub3d->file = file;
	cub3d->okay_we_have_everything = 0;
	init_malloc(cub3d);
	fd = open(file, O_RDONLY);
	if (fd < 0)
		ft_error("Can't open file.cub.", 1, cub3d);
	line = get_next_line(fd);
	while (line)
	{
		treat_line(line, cub3d, fd);
		if (!cub3d->okay_we_have_everything)
			ft_strdel(&line);
		line = get_next_line(fd);
	}
	if (!cub3d->okay_we_have_everything)
		ft_error("file.cub doesn't have all the infos needed.", 1, cub3d);
	if (close(fd) < 0)
		ft_error("Close error.", 1, cub3d);
}
