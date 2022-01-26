/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbarbry <kbarbry@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 23:14:15 by kbarbry           #+#    #+#             */
/*   Updated: 2022/01/27 00:10:31 by kbarbry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	plot_line (int x0, int y0, int x1, int y1, t_cub3d *cub3d, int color)
{
  int dx =  abs (x1 - x0), sx = x0 < x1 ? 1 : -1;
  int dy = -abs (y1 - y0), sy = y0 < y1 ? 1 : -1; 
  int err = dx + dy, e2; /* error value e_xy */
 
  for (;;){  /* loop */
    my_mlx_pixel_put(cub3d, x0, y0, color);
    if (x0 == x1 && y0 == y1) break;
    e2 = 2 * err;
    if (e2 >= dy) { err += dy; x0 += sx; } /* e_xy+e_x > 0 */
    if (e2 <= dx) { err += dx; y0 += sy; } /* e_xy+e_y < 0 */
  }
}

void	draw_rays(t_cub3d *c, int nbr_rays, int i)
{
	int r,mx,my,mp,dof,side;
	float vx,vy,rx,ry,ra,xo,yo,disV,disH, Tan;

	if (c->p_angle > 2 * PI)
		c->p_angle -= 2 * PI;
	if (c->p_angle < 0)
		c->p_angle += 2 * PI;
	ra = c->p_angle - degToRad(30);
	while (++i < nbr_rays)
	{
		dof = 0;
		side = 0;
		disV = 2000000;
		Tan = tan(ra);
		// vertical
		if (cos(ra) > 0.001)
		{
			rx = (((int)c->player.x >> 1) << 1) + 1;
			ry = (c->player.x - rx) * Tan + c->player.y;
			xo = 1;
			yo = -xo * Tan;
		}
		else if (cos(ra) < -0.001)
		{
			rx = (((int)c->player.x >> 1) << 1) - 0.0001;
			ry = (c->player.x - rx) * Tan + c->player.y;
			xo = -1;
			yo = -xo * Tan;
		}
		else
		{
			rx = c->player.x;
			ry = c->player.y;
			dof = c->width_map + c->height_map;
		}
		while (dof < c->width_map + c->height_map)
		{
			mx = (int)rx;
			my = (int)ry;
			mp = my * c->width_map + mx;
			if (mp > 0 && mp < c->width_map * c->height_map && c->map[mp] == 1)
			{
				dof = c->width_map + c->height_map;
				disV = cos(ra) * (rx - c->player.x) - sin(ra) * (ry - c->player.y);
			}
			else
			{
				rx += xo;
				ry += yo;
				dof++;
			}
		}
		vx = rx;
		vy = ry;
		// horizontal
		dof = 0;
		disH = 2000000;
		Tan = 1.0 / Tan;
		if (sin(ra) > 0.001)
		{
			ry = (((int)c->player.y >> 1) << 1) - 0.0001;
			rx = (c->player.y - ry) * Tan + c->player.x;
			yo = -1;
			xo = -yo * Tan;
		}
		else if (sin(ra) < -0.001)
		{
			ry = (((int)c->player.y >> 1) << 1) + 1;
			rx = (c->player.y - ry) * Tan + c->player.x;
			xo = 1;
			yo = -xo * Tan;
		}
		else
		{
			rx = c->player.x;
			ry = c->player.y;
			dof = c->width_map + c->height_map;
		}
		while (dof < c->width_map + c->height_map)
		{
			mx = ((int)rx);
			my = (int)ry;
			mp = my * c->width_map + mx;
			if (mp > 0 && mp < c->width_map * c->height_map && c->map[mp] == 1)
			{
				dof = c->width_map + c->height_map;
				disH = cos(ra) * (rx - c->player.x) - sin(ra) * (ry - c->player.y);
			}
			else
			{
				rx += xo;
				ry += yo;
				dof++;
			}
		}
		if (disV < disH)
		{
			rx = vx;
			ry = vy;
			disH = disV;
		}
		float	lineH = 
		plot_line(rx * 20, ry * 20, c->player.x * 20, c->player.y * 20, c, 0x00FFFFFF);
		if (ra + ANGLE > 2 * PI)
			ra -= 2 * PI;
		ra += ANGLE;
	}
}
