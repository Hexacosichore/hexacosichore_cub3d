/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_cub3d.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbarbry <kbarbry@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 05:16:37 by kbarbry           #+#    #+#             */
/*   Updated: 2022/01/30 12:43:04 by kbarbry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

static void	fill_texture(char *line, int nb, t_cub3d *cub3d, int j)
{
	if (!ft_strncmp(line, "NO", 2))
		cub3d->ntexture[j] = nb;
	else if (!ft_strncmp(line, "SO", 2))
		cub3d->stexture[j] = nb;
	else if (!ft_strncmp(line, "WE", 2))
		cub3d->wtexture[j] = nb;
	else if (!ft_strncmp(line, "EA", 2))
		cub3d->etexture[j] = nb;
}

static void	init_wall(char *line, t_cub3d *cub3d, int fd, int i)
{
	char	*line2;
	int		j;
	int		nb;

	j = 0;
	line2 = get_next_line(fd);
	while (line2)
	{
		nb = ft_atoi(line2);
		if (nb < 0 || nb > 255)
			ft_error("Color format is RGB (255,255,255).", 1, cub3d);
		fill_texture(line, nb, cub3d, j);
		j++;
		while (ft_isdigit(line2[i]))
			i++;
		if (line2[i] != '\n' && line2[i] != '\0')
			ft_error(".cubtxt are like .ppm files.", 1, cub3d);
		ft_strdel(&line2);
		line2 = get_next_line(fd);
		i = 0;
	}
	if (j != 32 * 32 * 3)
		ft_error("Texture must be 32x32 RGB value.", 1, cub3d);
	if (close(fd) < 0)
		ft_error("Close error.", 1, cub3d);
}

void	convert_to_color(t_cub3d *c)
{
	int	f;
	int	u;

	f = (0 << 24 | c->ftexture[0] << 16 | c->ftexture[1] << 8 | c->ftexture[2]);
	c->ftexture[0] = f;
	u = (0 << 24 | c->ctexture[0] << 16 | c->ctexture[1] << 8 | c->ctexture[2]);
	c->ctexture[0] = u;
}

static void	init_floor_ceiling(char *line, t_cub3d *cub3d, int i)
{
	int	j;
	int	nb;

	j = 0;
	while (ft_isspace(line[i]) && line[i] != '\n')
		i++;
	if (ft_isalpha(line[i]))
		ft_error("Color format is RGB (255,255,255).", 1, cub3d);
	while (line[i] != '\n' && j < 3)
	{
		nb = ft_atoi(&line[i]);
		if (nb < 0 || nb > 255)
			ft_error("Color format is RGB (255,255,255).", 1, cub3d);
		if (!ft_strncmp(line, "F", 1))
			cub3d->ftexture[j] = nb;
		else
			cub3d->ctexture[j] = nb;
		j++;
		while (ft_isdigit(line[i]) && line[i] != '\n')
			i++;
		if (line[i] == ',')
			i++;
	}
	if (line[i] != '\n' || j != 3)
		ft_error("Color format is RGB (255,255,255).", 1, cub3d);
}

void	init_texture(char *line, t_cub3d *cub3d)
{
	int		i;
	char	*doc;

	i = 0;
	check_identifier(line, cub3d);
	if (ft_isalpha(line[i]) && ft_isalpha(line[i + 1]))
	{
		while (ft_isalpha(line[i]))
			i++;
		while (ft_isspace(line[i]))
			i++;
		doc = ft_strndup(&line[i], ft_strlen(line) - i - 1);
		if (!doc)
			ft_error("Malloc error.", 1, cub3d);
		check_extention(doc, ".cubtxt");
		i = open(doc, O_RDONLY);
		if (i < 0)
			ft_error("Can't open file.cubtxt.", 1, cub3d);
		ft_strdel(&doc);
		init_wall(line, cub3d, i, 0);
	}
	else
		init_floor_ceiling(line, cub3d, 1);
}
