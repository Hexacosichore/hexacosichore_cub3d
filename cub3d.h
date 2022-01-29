/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbarbry <kbarbry@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 00:46:46 by kbarbry           #+#    #+#             */
/*   Updated: 2022/01/29 17:48:48 by kbarbry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# define WIN_L 1920
# define WIN_H 1080
# define ESC 53
# define W 13
# define A 0
# define S 1
# define D 2
# define LEFT_ARROW 123
# define RIGHT_ARROW 124
# define SHIFT 257
# define TAB 48

# include "minilibx/mlx.h"
# include "libft/libft.h"
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <math.h>

//struct
typedef struct s_vect2f
{
	float	x;
	float	y;
}				t_vect2f;

typedef struct s_vect2i
{
	int	x;
	int	y;
}				t_vect2i;

typedef struct s_press
{
	int	w;
	int	a;
	int	s;
	int	d;
	int	left;
	int	right;
	int	shift;
}				t_press;

typedef struct s_rays
{
	float		screenx;
	float		raydist;
	t_vect2f	raydir;
	t_vect2f	delt;
	t_vect2i	mappos;
	t_vect2f	sidedist;
	t_vect2f	step;
	int			done;
	int			side;
	int			lineh;
	int			draw_start;
	int			draw_end;
	int			size_cube;
	int			start;
	int			stop;
}				t_rays;

typedef struct s_cub3d
{
	char		*file;
	int			*map;
	int			width_map;
	int			height_map;
	int			*ntexture;
	int			*stexture;
	int			*wtexture;
	int			*etexture;
	int			*ftexture;
	int			*ctexture;
	int			okay_we_have_everything;
	void		*mlx;
	void		*mlx_win;
	void		*mlx_img;
	char		*addr;
	int			bits_per_pixel;
	int			line_length;
	int			endian;
	float		speed;
	float		sensi;
	t_vect2f	player;
	t_vect2f	dir;
	t_vect2f	cam;
	float		fov;
	t_press		is_press;
	int			started;
}				t_cub3d;

//checking
void		ft_isvalidid(char *line, t_cub3d *cub3d);
void		check_extention(char *file, char *extention);
void		check_identifier(char *line, t_cub3d *cub3d);
void		map_checker(t_cub3d *cub3d);
void		verify_north(t_cub3d *cub3d, int i);
void		verify_south(t_cub3d *cub3d, int i);
void		verify_west(t_cub3d *cub3d, int i);
void		verify_east(t_cub3d *cub3d, int i);

//parsing
void		init_parsing(char *file, t_cub3d *cub3d);
void		init_map(char *line, t_cub3d *cub3d, int fd, int i);
void		init_texture(char *line, t_cub3d *cub3d);
void		init_malloc(t_cub3d *d);

//ray_casting
void		init_ray_casting(t_cub3d *cub3d);
void		my_mlx_pixel_put(t_cub3d *d, int x, int y, int color);
int			create_trgb(int t, int r, int g, int b);
void		draw_rectangle(t_cub3d *cub3d, t_vect2f cd, int size, int color);
void		ft_draw(t_cub3d *cub3d);
int			ft_draw_modif(t_cub3d *cub3d);
int			ft_key_press(int keycode, t_cub3d *cub3d);
int			ft_key_release(int keycode, t_cub3d *cub3d);
void		actualize_player(t_cub3d *cub3d);
int			ft_exit(t_cub3d *cub3d);
void		draw_rays(t_cub3d *cub3d, int nbr_rays, int i);

//maths
void		convert_to_color(t_cub3d *c);
float		dist(t_vect2f pt0, t_vect2f pt1);
t_vect2f	newvect2f(float x, float y);
t_vect2i	newvect2i(int x, int y);
float		radToDeg(float rad);
float		degToRad(float deg);

//leaving
void		ft_leave(t_cub3d *cub3d);
void		ft_error(char *msg, int mode, t_cub3d *cub3d);

#endif