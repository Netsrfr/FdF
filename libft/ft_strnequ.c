/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnequ.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpfeffer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/26 14:58:55 by jpfeffer          #+#    #+#             */
/*   Updated: 2016/09/26 14:58:55 by jpfeffer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strnequ(char const *s1, char const *s2, size_t n)
{
	int	i;

	i = 0;
	if (n == 0)
		return (1);
	while (s1[i] == s2[i] && s1[i] && s2[i] && n != 0)
	{
		i++;
		n--;
	}
	if (n == 0 && s1[i - 1] == s2[i - 1])
		return (1);
	if (s1[i] == '\0' && s2[i] == '\0')
		return (1);
	else
		return (0);
}