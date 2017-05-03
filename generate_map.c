/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   generate_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpfeffer <jpfeffer@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/20 09:59:24 by jpfeffer          #+#    #+#             */
/*   Updated: 2017/04/20 09:59:24 by jpfeffer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_crd	**ft_parse_row(char **map, t_crd **i, t_mp *d)
{
	while (d->w < d->width)
	{
		if ((**map >= '0' && **map <= '9') || **map == '-')
		{
			i[d->h][d->w].alt = (int)ft_atoi(map);
			i[d->h][d->w].axis = d->w;
			i[d->h][d->w].ord = d->h;
			if (i[d->h][d->w].alt > 0)
				if (d->ul < (int)(i[d->h][d->w].alt - i[d->h][d->w].ord))
					d->ul = (int)(i[d->h][d->w].alt - i[d->h][d->w].ord);
			if (i[d->h][d->w].alt < 0)
				if (d->ul < (int)fabs(i[d->h][d->w].ord + i[d->h][d->w].alt))
					d->ll = (int)fabs(i[d->h][d->w].ord + i[d->h][d->w].alt);
		}
		if (**map == ',')
		{
			(*map)++;
			i[d->h][d->w].color = (unsigned int)ft_atoi_hex(map);
		}
		while (**map == ' ')
			(*map)++;
		d->w++;
	}
	d->v_range = d->ll + d->ul + d->height;
	return (i);
}

t_crd	**ft_parse_map(char *map, t_mp *d)
{
	t_crd	**input;

	input = ft_init_coords(*d);
	while (d->h < d->height)
	{
		input = ft_parse_row(&map, input, d);
		map++;
		d->w = 0;
		d->h++;
	}
	return (input);
}

int		ft_read_file(int argc, char **argv, char **map)
{
	int		fd;
	char	*buffer;

	if (argc != 2)
	{
		if (argc == 1)
			return (-1);
		else
			return (-2);
	}
	if ((fd = open(argv[1], O_RDONLY)) == -1)
		return (-3);
	if (!(buffer = ft_memalloc(sizeof(char) * BUFF_SIZE)))
		return (-4);
	if (!(*map = ft_memalloc(sizeof(char) * BUFF_SIZE)))
		return (ft_error_handler(-3, buffer, NULL, NULL));
	while (read(fd, buffer, BUFF_SIZE))
	{
		*map = ft_strjoin(*map, buffer);
		ft_bzero(buffer, BUFF_SIZE);
	}
	close(fd);
	free(buffer);
	return (0);
}

t_crd	**ft_init_coords(t_mp d)
{
	t_crd	**input;
	int		height;
	int		width;

	height = 0;
	width = 0;
	input = (t_crd**)ft_memalloc(sizeof(t_crd*) * (d.width * d.height));
	while (height < d.height)
	{
		input[height] = (t_crd*)ft_memalloc(sizeof(t_crd) * d.width);
		while (width < d.width)
		{
			input[height][width].alt = 0;
			input[height][width].color = 0xFFFFFF;
			width++;
		}
		height++;
		width = 0;
	}
	return (input);
}

int		ft_print_error(int error, char **argv)
{
	if (error == -1)
		write(2, "fdf:\x1b[31m error:\x1b[39m no input files\nusage: \
./fdf <filename>\n", 61);
	if (error == -2)
		write(2, "fdf:\x1b[31m error:\x1b[39m too many input files\nusage: \
./fdf <filename>\n", 67);
	if (error == -3)
		ft_printf("fdf: "RED"error: "DEF"'%s' not found or you do not have \
permission to access it\n", argv[1]);
	if (error == -4)
		ft_printf("fdf: "RED"error: "DEF"unable to allocate sufficient \
memory\n");
	if (error == -5 || error == -6)
		ft_printf("fdf: "RED"error: "DEF"invalid map file provided\nman "WHITE \
"./fdf.1"DEF" for usage\n");
	return (error);
}
