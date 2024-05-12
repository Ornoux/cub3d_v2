/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npatron <npatron@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/11 18:26:02 by npatron           #+#    #+#             */
/*   Updated: 2024/05/12 23:33:07 by npatron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3D.h"

bool	is_numeric(char c)
{
	if (c >= '0' && c <= '9')
		return (true);
	return (false);
}

int	big_atoi(const char *str)
{
	int res;
	int	i;

	i = 0;
	res = 0;
	while (is_numeric(str[i]) == false)
	{
		if (str[i] != ' ' && str[i] != '\t' && str[i])
		{
			printf("OUI");
			return (-5);
		}
		i++;
	}
	while (is_numeric(str[i]) == true)
	{
		res = (res * 10) + str[i] - '0';
		i++;
	}
	while (str[i])
	{
		if (is_numeric(str[i]) == true)
			return (-5);
		i++;
	}
	if (res > 255)
		return (-5);
	return (res);
}
