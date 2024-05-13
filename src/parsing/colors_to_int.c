/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors_to_int.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npatron <npatron@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/11 17:18:44 by npatron           #+#    #+#             */
/*   Updated: 2024/05/13 11:46:20 by npatron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3D.h"

bool	is_digit(char c)
{
	if ((c >= '0' && c <= '9') || c == ' ' || c == ',' || c == '\t')
		return (true);
	return (false);
}

bool	onlyDigitComma(char *s)
{
	int	i;
	int	comma;

	comma = 0;
	i = 0;
	while (s[i] != '\n')
	{
		if (is_digit(s[i]) == false)
			return (false);
		else if (s[i] == ',')
			comma++;
		i++;
	}
	if (comma != 2)
		return (false);
	return (true);
}
bool	check_range(int *tab)
{
	int	i;

	i = 0;
	while (i < 3)
	{
		if (tab[i] < 0 || tab[i] > 255)
			return (false);
		i++;
	}
	return (true);
}

void	split_colors(t_data *data)
{
	char	**tab_sky;
	char	**tab_floor;
	int		i;

	i = 0;
	tab_sky = ft_split(data->sky_path, ',');
	tab_floor = ft_split(data->floor_path, ',');
	if (char_tab_len(tab_sky) != 3 || char_tab_len(tab_floor) != 3)
		ft_exit(NUMBER_MISSING);
	free(data->sky_path);
	free(data->floor_path);
	data->floor_color = malloc(sizeof(int) * 3);
	data->sky_color = malloc(sizeof(int) * 3);
	while (i < 3)
	{
		data->floor_color[i] = big_atoi(tab_floor[i]);
		data->sky_color[i] = big_atoi(tab_sky[i]);
		i++;
	}
	free_char_tab(tab_floor);
	free_char_tab(tab_sky);
	return ;
}

void	color_to_int(t_data *data)
{
	int	i;
	i = 0;
	if (onlyDigitComma(data->floor_path) == false ||
		onlyDigitComma(data->sky_path) == false)
		return ft_exit(BAD_COLORS);
	split_colors(data);
	if (check_range(data->sky_color) == false || check_range(data->floor_color) == false)
		ft_exit(BAD_RANGE);
	return ;
}