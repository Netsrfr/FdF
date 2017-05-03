/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpfeffer <jpfeffer@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/03 14:25:19 by jpfeffer          #+#    #+#             */
/*   Updated: 2017/05/03 14:25:19 by jpfeffer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	ft_key_press(int key, void *param)
{
	if (key == 53)
		exit(0);
	param = 0;
	return (0);
}

int	ft_expose(t_nfo info)
{
	ft_drive_y(info.input, info.map, info.mlx, info.window);
	return (0);
}

int	main(int argc, char **argv)
{
	char	*map;
	t_mp	dimensions;
	int		error;
	t_crd	**input;

	if ((error = ft_print_error(ft_read_file(argc, argv, &map), argv)) != 0)
		return (error);
	if ((error = ft_print_error(ft_validate_map(map, &dimensions), NULL)) != 0)
		return (error);
	input = ft_parse_map(map, &dimensions);
	free(map);
	ft_draw(input, dimensions);
	exit(0);
}
