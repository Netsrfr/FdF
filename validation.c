/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpfeffer <jpfeffer@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/20 11:51:52 by jpfeffer          #+#    #+#             */
/*   Updated: 2017/04/20 11:51:52 by jpfeffer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	ft_count_width(char *map)
{
	int	i;
	int	width;

	i = 0;
	width = 1;
	if (map[0] == ' ')
		i++;
	while (map[i] && map[i] != '\n')
	{
		while (map[i] && map[i] != ' ')
		{
			i++;
			if (map[i] == '\n')
				return (width);
		}
		while (map[i] && map[i] == ' ')
		{
			i++;
			if ((map[i] >= '0' && map[i] <= '9') || map[i] == '-')
				width++;
			if (map[i] == '\n')
				return (width);
		}
	}
	return (width);
}

int	ft_count_height(char *map)
{
	int	i;
	int	height;

	i = 0;
	height = 0;
	while (map[i])
	{
		if (map[i] == '\n')
			height++;
		i++;
	}
	if (map[i - 1] != '\n')
		height++;
	return (height);
}

int	ft_validate_contents(char *map)
{
	int i;

	i = 0;
	while (*map)
	{
		if (ME('0', '9') && *map != ' ' && *map != '\n' && ME(',', '-'))
			return (-1);
		if (*map == ',')
		{
			if (*(map + 1) != '0' && *(map + 2) != 'x')
				return (-1);
			map = map + 3;
			while (MI('0', '9') || MI('a', 'f') || MI('A', 'F'))
			{
				map++;
				i++;
				if (i > 6)
					return (0);
			}
			i = 0;
			map--;
		}
		map++;
	}
	return (0);
}

int	ft_validate_size(char *map, t_mp dimensions)
{
	int	i;
	int	width;

	i = 0;
	width = 0;
	while (map[i])
	{
		while (map[i] && map[i] != '\n')
		{
			while (map[i] == ' ')
				i++;
			while (map[i] && map[i] != ' ' && map[i] != '\n')
				i++;
			width++;
		}
		if (map[i - 1] == ' ')
			width--;
		if (width != dimensions.width)
			return (-1);
		width = 0;
		i++;
	}
	return (0);
}

int	ft_validate_map(char *map, t_mp *dimensions)
{
	if (ft_validate_contents(map) != 0)
	{
		free(map);
		return (-5);
	}
	dimensions->w = 0;
	dimensions->h = 0;
	dimensions->width = ft_count_width(map);
	dimensions->height = ft_count_height(map);
	if (ft_validate_size(map, *dimensions) != 0)
		return (-5);
	return (0);
}
