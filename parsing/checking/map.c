/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbarbry <kbarbry@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/22 01:39:57 by kbarbry           #+#    #+#             */
/*   Updated: 2022/01/25 08:14:27 by kbarbry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

static void	check_close_map(t_cub3d *cub3d, int i)
{
	while (i < cub3d->height_map * cub3d->width_map)
	{
		if (cub3d->map[i] == 0)
		{
			verify_north(cub3d, i);
			verify_south(cub3d, i);
			verify_west(cub3d, i);
			verify_east(cub3d, i);
		}
		i++;
	}
}

static void	init_pos_player(int i, t_cub3d *cub3d)
{
	cub3d->player.y = (float)(i / cub3d->width_map + 0.5);
	cub3d->player.x = (float)(i % cub3d->width_map + 0.5);
	if (cub3d->map[i] == 11)
		cub3d->p_angle = PI / 2;
	if (cub3d->map[i] == 12)
		cub3d->p_angle = 3 * PI / 2;
	if (cub3d->map[i] == 13)
		cub3d->p_angle = PI;
	if (cub3d->map[i] == 14)
		cub3d->p_angle = 0;
	cub3d->map[i] = 0;
}

void	map_checker(t_cub3d *cub3d)
{
	int	i;
	int	perso;

	i = 0;
	perso = 0;
	if (cub3d->height_map < 3 || cub3d->width_map < 3)
		ft_error("Map must be 3x3 at least.", 1, cub3d);
	while (i < cub3d->height_map * cub3d->width_map)
	{
		if (cub3d->map[i] < 15 && cub3d->map[i] > 10)
		{
			init_pos_player(i, cub3d);
			perso++;
		}
		i++;
	}
	if (perso != 1)
		ft_error("Map must have a start position and only one.", 1, cub3d);
	check_close_map(cub3d, 0);
}
