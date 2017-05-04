/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpfeffer <jpfeffer@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/19 14:14:56 by jpfeffer          #+#    #+#             */
/*   Updated: 2017/04/19 14:14:56 by jpfeffer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# include <unistd.h>
# include <printf.h>
# include <fcntl.h>
# include "libraries/get_next_line/get_next_line.h"
# include "libft/libft.h"
# include "libraries/ft_printf/ft_printf.h"
# include "minilibx_macos/mlx.h"
# include <math.h>
# define WIN_H	1240
# define WIN_W	2360
# define ME(x,y) (*map < x || *map > y)
# define MI(x,y) (*map >= x && *map <= y)

typedef struct			s_oord
{
	double			axis;
	double			ord;
	double			alt;
	unsigned int	color;

}						t_crd;

typedef struct			s_ap
{
	int		h;
	int		w;
	int		width;
	int		height;
	int		ul;
	int		ll;
	int		v_range;
}						t_mp;

typedef struct			s_ean
{
	double		axis;
	double		ordinate;
	double		altitude;
}						t_ean;

typedef struct			s_nfo
{
	t_crd	**input;
	t_mp	map;
	void	*mlx;
	void	*window;
}						t_nfo;

int						ft_key_press(int key, void *param);
int						ft_expose(t_nfo info);

int						ft_count_width(char *map);
int						ft_count_height(char *map);
int						ft_validate_contents(char *map);
int						ft_validate_size(char *map, t_mp dimensions);
int						ft_validate_map(char *map, t_mp *dimensions);

t_crd					**ft_parse_row(char **map, t_crd **i, t_mp *d);
t_crd					**ft_parse_map(char *map, t_mp *d);
int						ft_read_file(int argc, char **argv, char **map);
t_crd					**ft_init_coords(t_mp d);
int						ft_print_error(int error, char **argv);

int						ft_draw(t_crd **input, t_mp d);
void					ft_drive_y(t_crd **input, t_mp d, void *mlx, void *win);
void					ft_isometric(t_crd **input, t_mp d, double angle);
void					ft_axis(t_crd i0, t_crd i1, void *mlx, void *win);
void					ft_ordinate(t_crd i0, t_crd i1, void *mlx, void *win);

void					ft_scale(t_crd **input, t_mp d);
void					ft_margins(t_crd **input, t_mp d, int scale);
t_ean					ft_mean(t_crd **input, t_mp d);
#endif
