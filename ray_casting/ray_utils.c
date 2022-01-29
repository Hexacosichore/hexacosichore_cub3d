/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbarbry <kbarbry@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 23:14:15 by kbarbry           #+#    #+#             */
/*   Updated: 2022/01/29 18:11:52 by kbarbry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	draw_vline(t_cub3d *c, t_rays *rays, int x)
{
	int	i;
	int	color;

	i = -1;
	if (!rays->side)
		color = 0x00FFFFFF;
	else
		color = 0x00999999;
	while (++i < rays->start)
		my_mlx_pixel_put(c, x, i, c->ctexture[0]);
	while (++i < rays->stop)
		my_mlx_pixel_put(c, x, i, color);
	while (++i < WIN_H)
		my_mlx_pixel_put(c, x, i, c->ftexture[0]);
}

void	step_by_step(t_cub3d *c, t_rays *rays)
{
	if (rays->raydir.x < 0)
	{
		rays->step.x = -1;
		rays->sidedist.x = (c->player.x - rays->mappos.x) * rays->delt.x;
	}
	else
	{
		rays->step.x = 1;
		rays->sidedist.x = (rays->mappos.x + 1 - c->player.x) * rays->delt.x;
	}
	if (rays->raydir.y < 0)
	{
		rays->step.y = -1;
		rays->sidedist.y = (c->player.y - rays->mappos.y) * rays->delt.y;
	}
	else
	{
		rays->step.y = 1;
		rays->sidedist.y = (rays->mappos.y + 1 - c->player.y) * rays->delt.y;
	}
}

void	find_end_ray(t_cub3d *c, t_rays *rays)
{
	while (!rays->done)
	{
		if (rays->sidedist.x < rays->sidedist.y)
		{
			rays->sidedist.x += rays->delt.x;
			rays->mappos.x += rays->step.x;
			rays->side = 0;
		}
		else
		{
			rays->sidedist.y += rays->delt.y;
			rays->mappos.y += rays->step.y;
			rays->side = 1;
		}
		if (c->map[rays->mappos.y * c->width_map + rays->mappos.x] == 1)
			rays->done++;
	}
	if (!rays->side)
		rays->raydist = (rays->sidedist.x - rays->delt.x);
	else
		rays->raydist = (rays->sidedist.y - rays->delt.y);
}

void	size_rays(t_rays *rays)
{
	rays->lineh = (int)(rays->size_cube / rays->raydist);
	rays->start = -rays->lineh / 2 + rays->size_cube / 2;
	if (rays->start < 0)
		rays->start = 0;
	rays->stop = rays->lineh / 2 + rays->size_cube / 2;
	if (rays->stop >= rays->size_cube)
		rays->stop = rays->size_cube - 1;
}

void	draw_rays(t_cub3d *c, int nbr_rays, int i)
{
	t_rays	rays;

	while (++i < nbr_rays)
	{
		rays.screenx = 2 * i / (float)nbr_rays - 1;
		rays.raydir = newvect2f(c->dir.x + c->cam.x * rays.screenx, c->dir.y
				+ c->cam.y * rays.screenx);
		if (rays.raydir.x == 0)
			rays.raydir.x = 1e-30;
		if (rays.raydir.y == 0)
			rays.raydir.y = 1e-30;
		rays.delt = newvect2f(fabs(1 / rays.raydir.x), fabs(1 / rays.raydir.y));
		rays.mappos = newvect2i((int)c->player.x, (int)c->player.y);
		step_by_step(c, &rays);
		rays.done = 0;
		find_end_ray(c, &rays);
		rays.size_cube = WIN_H;
		size_rays(&rays);
		draw_vline(c, &rays, i);
	}
}
