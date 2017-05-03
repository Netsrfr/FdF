/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpfeffer <jpfeffer@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/03 13:48:55 by jpfeffer          #+#    #+#             */
/*   Updated: 2017/05/03 13:48:55 by jpfeffer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_ordinate(t_crd i0, t_crd i1, void *mlx, void *win)
{
	double delta_x;
	double delta_y;
	double error;
	double rise;

	delta_x = i1.axis - i0.axis;
	delta_y = i1.ord - i0.ord;
	rise = fabs(delta_x / delta_y);
	error = -1.0;
	while ((int)i0.ord != (int)i1.ord)
	{
		mlx_pixel_put(mlx, win, (int)i0.axis, (int)i0.ord, i0.color);
		error += rise;
		if (error >= 0.0)
		{
			i0.axis += (i0.axis > i1.axis) ? -1.0 : 1.0;
			error -= 1.0;
		}
		i0.ord += (i0.ord > i1.ord) ? -1.0 : 1.0;
	}
}

void	ft_axis(t_crd i0, t_crd i1, void *mlx, void *win)
{
	double delta_x;
	double delta_y;
	double error;
	double rise;

	delta_x = i1.axis - i0.axis;
	delta_y = i1.ord - i0.ord;
	rise = fabs(delta_y / delta_x);
	error = -1.0;
	while ((int)i0.axis != (int)i1.axis)
	{
		mlx_pixel_put(mlx, win, (int)i0.axis, (int)i0.ord, i0.color);
		error += rise;
		if (error >= 0.0)
		{
			i0.ord += (i0.ord > i1.ord) ? -1.0 : 1.0;
			error -= 1.0;
		}
		i0.axis += (i0.axis > i1.axis) ? -1.0 : 1.0;
	}
}

void	ft_isometric(t_crd **input, t_mp d, double angle)
{
	t_ean	mean;
	double	hypotenuse;
	double	arctan;

	mean = ft_mean(input, d);
	d.h = 0;
	while (d.h < d.height)
	{
		d.w = 0;
		while (d.w < d.width)
		{
			hypotenuse = hypot(input[d.h][d.w].ord - mean.ordinate, \
			input[d.h][d.w].alt - mean.altitude);
			arctan = atan2(input[d.h][d.w].ord - mean.ordinate, \
			input[d.h][d.w].alt - mean.altitude) - angle;
			input[d.h][d.w].ord = hypotenuse * sin(arctan) + mean.ordinate;
			input[d.h][d.w].alt = hypotenuse * cos(arctan) + mean.altitude;
			d.w++;
		}
		d.h++;
	}
}

void	ft_drive_y(t_crd **input, t_mp d, void *mlx, void *win)
{
	double	delta;

	d.w = 0;
	d.h = 0;
	while (d.h < d.height)
	{
		delta = fabs(input[d.h][d.w + 1].axis - input[d.h][d.w].axis) /
				fabs(input[d.h][d.w + 1].ord - input[d.h][d.w].ord);
		if (d.w < d.width - 1 && delta > 1.0)
			ft_axis(input[d.h][d.w], input[d.h][d.w + 1], mlx, win);
		if (d.w < d.width - 1 && delta < 1.0)
			ft_ordinate(input[d.h][d.w], input[d.h][d.w + 1], mlx, win);
		if (d.h < d.height - 1)
			ft_ordinate(input[d.h][d.w], input[d.h + 1][d.w], mlx, win);
		if (d.w == d.width - 1)
		{
			d.h++;
			d.w = 0;
		}
		else
			d.w++;
	}
}

int		ft_draw(t_crd **input, t_mp d)
{
	void	*mlx;
	void	*window;
	t_nfo	info;

	mlx = mlx_init();
	window = mlx_new_window(mlx, WIN_W, WIN_H, "FdF");
	ft_scale(input, d);
	ft_isometric(input, d, (M_PI / 180) * 25);
	ft_drive_y(input, d, mlx, window);
	info.input = input;
	info.map = d;
	info.mlx = mlx;
	info.window = window;
	mlx_key_hook(window, ft_key_press, 0);
	mlx_expose_hook(window, ft_expose, &info);
	mlx_loop(mlx);
	return (0);
}
