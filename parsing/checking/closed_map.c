/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   closed_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbarbry <kbarbry@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/22 04:58:25 by kbarbry           #+#    #+#             */
/*   Updated: 2022/01/26 22:43:46 by kbarbry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

void	verify_north(t_cub3d *cub3d, int i)
{
	while (cub3d->map[i] == 0)
	{
		if (i - cub3d->width_map < 0)
			ft_error("Map not surrounded by walls.1", 1, cub3d);
		i = i - cub3d->width_map;
	}
	if (cub3d->map[i] != 1)
		ft_error("Map not surrounded by walls.2", 1, cub3d);
}

void	verify_south(t_cub3d *cub3d, int i)
{
	while (cub3d->map[i] == 0)
	{
		if (i + cub3d->width_map > cub3d->width_map * cub3d->height_map)
			ft_error("Map not surrounded by walls.3", 1, cub3d);
		i = i + cub3d->width_map;
	}
	if (cub3d->map[i] != 1)
		ft_error("Map not surrounded by walls.4", 1, cub3d);
}

void	verify_west(t_cub3d *cub3d, int i)
{
	while (cub3d->map[i] == 0)
	{
		if ((i - 1) % cub3d->width_map == 0 && cub3d->map[i - 1] != 1)
			ft_error("Map not surrounded by walls.5", 1, cub3d);
		i = i - 1;
	}
	if (cub3d->map[i] != 1)
		ft_error("Map not surrounded by walls.6", 1, cub3d);
}

void	verify_east(t_cub3d *cub3d, int i)
{
	while (cub3d->map[i] == 0)
	{
		if ((i + 1) % cub3d->width_map == 0 && cub3d->map[i - 1] != 1)
			ft_error("Map not surrounded by walls.7", 1, cub3d);
		i = i + 1;
	}
	if (cub3d->map[i] != 1)
		ft_error("Map not surrounded by walls.8", 1, cub3d);
}
