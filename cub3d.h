/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbarbry <kbarbry@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 00:46:46 by kbarbry           #+#    #+#             */
/*   Updated: 2022/01/22 06:27:23 by kbarbry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# define PI 3.14159265
# define WIN_L 1280
# define WIN_H 720

# include "minilibx/mlx.h"
# include "libft/libft.h"
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

//struct
typedef struct s_cub3d
{
	char	*file;
	int		*map;
	int		width_map;
	int		height_map;
	int		*ntexture;
	int		*stexture;
	int		*wtexture;
	int		*etexture;
	int		*ftexture;
	int		*ctexture;
	int		okay_we_have_everything;
	void	*mlx;
	void	*mlx_win;
	void	*mlx_img;
}				t_cub3d;

//checking
void	ft_isvalidid(char *line, t_cub3d *cub3d);
void	check_extention(char *file, char *extention);
void	check_identifier(char *line, t_cub3d *cub3d);
void	map_checker(t_cub3d *cub3d);
void	verify_north(t_cub3d *cub3d, int i);
void	verify_south(t_cub3d *cub3d, int i);
void	verify_west(t_cub3d *cub3d, int i);
void	verify_east(t_cub3d *cub3d, int i);

//parsing
void	init_parsing(char *file, t_cub3d *cub3d);
void	init_map(char *line, t_cub3d *cub3d, int fd, int i);
void	init_texture(char *line, t_cub3d *cub3d);
void	init_malloc(t_cub3d *d);

//ray_casting
void	init_ray_casting(t_cub3d *cub3d);

//leaving
void	ft_leave(t_cub3d *cub3d);
void	ft_error(char *msg, int mode, t_cub3d *cub3d);

#endif