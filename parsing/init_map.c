/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbarbry <kbarbry@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 07:25:59 by kbarbry           #+#    #+#             */
/*   Updated: 2022/01/27 03:31:45 by kbarbry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

/*
0 = floor,
1 = wall,
10 = ' ',
11 = N,
12 = S,
13 = W,
14 = E,
42 = \n
*/

static void	allocation_map(t_cub3d *cub3d)
{
	cub3d->map = (int *)ft_calloc(cub3d->width_map * cub3d->height_map, 4);
	if (!cub3d->map)
		ft_error("Malloc error.", 1, cub3d);
}

static void	map_content(char pos, t_cub3d *cub3d, int i)
{
	if (pos == 'N')
		cub3d->map[i] = 11;
	else if (pos == 'S')
		cub3d->map[i] = 12;
	else if (pos == 'W')
		cub3d->map[i] = 13;
	else if (pos == 'E')
		cub3d->map[i] = 14;
	else if (pos == ' ')
		cub3d->map[i] = 10;
	else
		cub3d->map[i] = pos - 48;
}

void	init_malloc(t_cub3d *d)
{
	d->ntexture = (int *)ft_calloc(32 * 32 * 3, sizeof(int));
	d->stexture = (int *)ft_calloc(32 * 32 * 3, sizeof(int));
	d->wtexture = (int *)ft_calloc(32 * 32 * 3, sizeof(int));
	d->etexture = (int *)ft_calloc(32 * 32 * 3, sizeof(int));
	d->ftexture = (int *)ft_calloc(3, sizeof(int));
	d->ctexture = (int *)ft_calloc(3, sizeof(int));
	d->map = NULL;
	if (!d->ntexture || !d->stexture || !d->wtexture || !d->etexture
		|| !d->ftexture || !d->ctexture)
		ft_error("Malloc error.", 1, d);
}

void	init_map(char *line, t_cub3d *cub3d, int fd, int i)
{
	int	j;

	j = 0;
	allocation_map(cub3d);
	while (line)
	{
		while (line[i] != '\n' && line[i])
		{
			if (line[i] == 'N' || line[i] == 'S' || line[i] == 'W'
				|| line[i] == 'E' || line[i] == '1' || line[i] == '0'
				|| line[i] == ' ')
				map_content(line[i], cub3d, j);
			else
				ft_error("Map char allowed: 01 NSWE.", 1, cub3d);
			i++;
			j++;
		}
		while (i++ < cub3d->width_map)
			cub3d->map[j++] = 10;
		ft_strdel(&line);
		line = get_next_line(fd);
		i = 0;
	}
	map_checker(cub3d);
}
