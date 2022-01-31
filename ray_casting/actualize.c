/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actualize.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbarbry <kbarbry@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/23 04:13:08 by kbarbry           #+#    #+#             */
/*   Updated: 2022/01/31 19:14:35 by kbarbry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

static void	actualize_player_offset(t_cub3d *c)
{
	if (c->is_press.down)
	{
		if (c->offset < 100)
			c->offset++;
	}
	else
	{
		if (c->offset > 0)
			c->offset--;
	}
	if (c->is_press.up)
	{
		if (c->offset > -100)
			c->offset--;
	}
	else
	{
		if (c->offset < 0)
			c->offset++;
	}
}

static void	actualize_player_3(t_cub3d *c)
{
	float	olddir;
	float	oldcam;

	turn_with_mouse(c);
	if (c->is_press.left)
	{
		olddir = c->dir.x;
		oldcam = c->cam.x;
		c->dir.x = c->dir.x * cosf(-c->sensi) - c->dir.y * sinf(-c->sensi);
		c->dir.y = olddir * sinf(-c->sensi) + c->dir.y * cosf(-c->sensi);
		c->cam.x = c->cam.x * cosf(-c->sensi) - c->cam.y * sinf(-c->sensi);
		c->cam.y = oldcam * sinf(-c->sensi) + c->cam.y * cosf(-c->sensi);
		c->is_press.left = 0;
	}
	if (c->is_press.right)
	{
		olddir = c->dir.x;
		oldcam = c->cam.x;
		c->dir.x = c->dir.x * cosf(c->sensi) - c->dir.y * sinf(c->sensi);
		c->dir.y = olddir * sinf(c->sensi) + c->dir.y * cosf(c->sensi);
		c->cam.x = c->cam.x * cosf(c->sensi) - c->cam.y * sinf(c->sensi);
		c->cam.y = oldcam * sinf(c->sensi) + c->cam.y * cosf(c->sensi);
		c->is_press.right = 0;
	}
	mlx_mouse_move(c->mlx_win, WIN_L / 2, WIN_H / 2);
}

static void	actualize_player_2(t_cub3d *c)
{
	if (c->is_press.a)
	{
		if (c->map[(int)c->player.y * c->width_map + (int)(c->player.x
				- c->cam.x * c->speed * 3)] != 1)
			c->player.x -= c->cam.x * c->speed;
		if (c->map[(int)c->player.x + (int)(c->player.y - c->cam.y
				* c->speed * 3) * c->width_map] != 1)
			c->player.y -= c->cam.y * c->speed;
	}
	if (c->is_press.d)
	{
		if (c->map[(int)c->player.y * c->width_map + (int)(c->player.x
				+ c->cam.x * c->speed * 3)] != 1)
		c->player.x += c->cam.x * c->speed;
		if (c->map[(int)c->player.x + (int)(c->player.y + c->cam.y
				* c->speed * 3) * c->width_map] != 1)
		c->player.y += c->cam.y * c->speed;
	}
	if (c->is_press.shift)
		c->speed = 0.04f;
	else
		c->speed = 0.02f;
	actualize_player_3(c);
	actualize_player_offset(c);
}

void	actualize_player(t_cub3d *c)
{
	if (c->is_press.w)
	{
		if (c->map[(int)c->player.y * c->width_map + (int)(c->player.x
				+ c->dir.x * c->speed * 3)] != 1)
			c->player.x += c->dir.x * c->speed;
		if (c->map[(int)c->player.x + (int)(c->player.y + c->dir.y
				* c->speed * 3) * c->width_map] != 1)
			c->player.y += c->dir.y * c->speed;
	}
	if (c->is_press.s)
	{
		if (c->map[(int)c->player.y * c->width_map + (int)(c->player.x
				- c->dir.x * c->speed * 3)] != 1)
			c->player.x -= c->dir.x * c->speed;
		if (c->map[(int)c->player.x + (int)(c->player.y - c->dir.y
				* c->speed * 3) * c->width_map] != 1)
			c->player.y -= c->dir.y * c->speed;
	}
	actualize_player_2(c);
}
