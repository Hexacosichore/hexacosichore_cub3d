/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbarbry <kbarbry@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/23 01:13:02 by kbarbry           #+#    #+#             */
/*   Updated: 2022/01/29 17:39:06 by kbarbry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	draw_rectangle(t_cub3d *cub3d, t_vect2f cd, int size, int color)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < size)
	{
		while (j < size)
		{
			my_mlx_pixel_put(cub3d, (int)(cd.x + i), (int)(cd.y + j), color);
			j++;
		}
		j = 0;
		i++;
	}
}

void	draw_map(t_cub3d *cub3d, int i)
{
	t_vect2f	coord;

	while (i < cub3d->height_map * cub3d->width_map)
	{
		coord.x = (float)(i % cub3d->width_map * 5);
		coord.y = (float)(i / cub3d->width_map * 5);
		if (cub3d->map[i] == 0)
			draw_rectangle(cub3d, coord, 5, 0xF059007C);
		if (cub3d->map[i] == 1)
			draw_rectangle(cub3d, coord, 5, 0xF0FFFFFF - cub3d->ctexture[0]);
		i++;
	}
}

void	draw_player(t_cub3d *cub3d)
{
	t_vect2f	coord;

	coord.x = cub3d->player.x * 5.0f - 3;
	coord.y = cub3d->player.y * 5.0f - 3;
	draw_rectangle(cub3d, coord, 3, 0x00FF0000);
	coord.x += cub3d->dir.x * 4;
	coord.y += cub3d->dir.y * 4;
	draw_rectangle(cub3d, coord, 2, 0x00FF0000);
}

void	ft_draw(t_cub3d *cub3d)
{
	draw_rays(cub3d, WIN_L, -1);
	draw_map(cub3d, 0);
	draw_player(cub3d);
}

int	ft_draw_modif(t_cub3d *cub3d)
{
	actualize_player(cub3d);
	mlx_destroy_image(cub3d->mlx, cub3d->mlx_img);
	cub3d->mlx_img = mlx_new_image(cub3d->mlx, WIN_L, WIN_H);
	cub3d->addr = mlx_get_data_addr(cub3d->mlx_img, &cub3d->bits_per_pixel,
			&cub3d->line_length, &cub3d->endian);
	ft_draw(cub3d);
	mlx_put_image_to_window(cub3d->mlx, cub3d->mlx_win, cub3d->mlx_img, 0, 0);
	return (0);
}
