/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpfeffer <jpfeffer@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/03 13:52:45 by jpfeffer          #+#    #+#             */
/*   Updated: 2017/05/03 13:52:45 by jpfeffer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_ean		ft_mean(t_crd **input, t_mp d)
{
	t_ean	mean;

	mean.altitude = 0;
	mean.axis = dsummorial((double)d.width) / (double)d.width;
	mean.ordinate = dsummorial((double)d.height) / (double)d.height;
	d.h = 0;
	while (d.h < d.height)
	{
		d.w = 0;
		while (d.w < d.width)
		{
			mean.altitude += input[d.h][d.w].alt;
			d.w++;
		}
		d.h++;
	}
	mean.altitude = (mean.altitude / (double)(d.width * d.height));
	return (mean);
}

void		ft_margins(t_crd **input, t_mp d, int scale)
{
	d.w = 0;
	d.h = 0;
	d.v_range = d.v_range + d.ul * scale;
	while (d.h < d.height)
	{
		while (d.w < d.width)
		{
			input[d.h][d.w].axis += ((WIN_W - ((d.width - 1) * scale)) / 2);
			input[d.h][d.w].ord += ((WIN_H - d.v_range) / 2) + d.ul * scale;
			d.w++;
		}
		d.w = 0;
		d.h++;
	}
}

void		ft_scale(t_crd **input, t_mp d)
{
	int	scale;

	d.w = 0;
	d.h = 0;
	if (WIN_W / d.width < WIN_H / d.v_range)
		scale = WIN_W / d.width;
	else
		scale = WIN_H / d.v_range;
	scale = scale == 0 ? 1 : scale;
	d.v_range *= scale;
	while (d.h < d.height)
	{
		while (d.w < d.width)
		{
			input[d.h][d.w].axis *= scale;
			input[d.h][d.w].ord *= scale;
			input[d.h][d.w].alt *= scale;
			d.w++;
		}
		d.w = 0;
		d.h++;
	}
	ft_margins(input, d, scale);
}
