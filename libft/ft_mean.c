/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mean.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpfeffer <jpfeffer@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/25 11:29:59 by jpfeffer          #+#    #+#             */
/*   Updated: 2017/04/25 11:29:59 by jpfeffer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

uintmax_t	mean(uintmax_t *n, size_t count)
{
	size_t		i;
	uintmax_t	result;

	i = 0;
	result = 0;
	while (i < count)
	{
		result += n[i];
		i++;
	}
	return (result / count);
}

double		dmean(double *n, size_t count)
{
	size_t	i;
	double	result;

	i = 0;
	result = 0;
	while (i < count)
	{
		result += n[i];
		i++;
	}
	return (result / count);
}
