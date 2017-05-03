/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_factorial.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpfeffer <jpfeffer@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/25 11:28:59 by jpfeffer          #+#    #+#             */
/*   Updated: 2017/04/25 11:28:59 by jpfeffer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

uintmax_t	factorial(uintmax_t n)
{
	if (n == 1)
		return (1);
	else
		return n * factorial(n - 1);
}

double		dfactorial(double n)
{
	if (n == 1.0)
		return (1.0);
	else
		return n * dfactorial(n - 1.0);
}

uintmax_t	summorial(uintmax_t n)
{
	if (n == 1)
		return (1);
	else
		return n + summorial(n - 1);
}

double		dsummorial(double n)
{
	if (n == 1.0)
		return (1.0);
	else
		return n + dsummorial(n - 1.0);
}
