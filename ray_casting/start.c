/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbarbry <kbarbry@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/22 06:04:40 by kbarbry           #+#    #+#             */
/*   Updated: 2022/01/26 23:40:25 by kbarbry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	init_ray_casting(t_cub3d *cub3d)
{
	cub3d->sensi = 0.04f;
	cub3d->mlx = mlx_init();
	cub3d->mlx_win = mlx_new_window(cub3d->mlx, WIN_L, WIN_H, "Cub3D");
	cub3d->mlx_img = mlx_new_image(cub3d->mlx, WIN_L, WIN_H);
	cub3d->addr = mlx_get_data_addr(cub3d->mlx_img, &cub3d->bits_per_pixel,
			&cub3d->line_length, &cub3d->endian);
	mlx_mouse_hide();
	mlx_hook(cub3d->mlx_win, 17, 1L << 17, ft_exit, cub3d);
	mlx_hook(cub3d->mlx_win, 2, 1L << 0, ft_key_press, cub3d);
	mlx_loop_hook(cub3d->mlx, ft_draw_modif, cub3d);
	mlx_hook(cub3d->mlx_win, 3, 1L << 1, ft_key_release, cub3d);
	mlx_loop(cub3d->mlx);
}
