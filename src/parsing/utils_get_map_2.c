/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_get_map_2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npatron <npatron@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 13:39:18 by npatron           #+#    #+#             */
/*   Updated: 2024/05/14 18:22:05 by npatron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3D.h"

int	is_player(char c)
{
	if (c == 'N' || c == 'S' || c == 'W'
		|| c == 'E')
		return (1);
	return (0);
}

int	char_valid(char c)
{
	if (c != '1' && c != '0' && c != 'S'
		&& c != 'E' && c != 'W' && c != 'N')
		return (1);
	return (0);
}
void	is_good_char(t_data *data, char c, int x, int y)
{
	if (c == 'N' || c == 'S' || c == 'W' || c == 'E')
	{
		data->player++;
		data->posi_x = x;
		data->posi_y = y;
		data->char_player = c;
	}
	if (c == ' ' || c == 'N' || c == 'S'
		|| c == 'W' || c == 'E' || c == '1'
		|| c == '0' || c == '\t')
		return ;
	ft_exit(data, INVALID_CHAR_MAP);
}

int	check_player(char **map, int i, int j)
{
	if ((is_player(map[i][j]) && map[i + 1][j] == ' ')
			|| (is_player(map[i][j]) && char_valid(map[i - 1][j]))
			|| (is_player(map[i][j]) && char_valid(map[i][j + 1]))
			|| (is_player(map[i][j]) && char_valid(map[i][j - 1])))
		return (1);
	return (0);
}

void	good_letters(t_data *data, char **tab)
{
	int	i;
	int	j;

	i = 0;
	while (tab[i])
	{
		j = 0;
		while (tab[i][j])
		{
			is_good_char(data, tab[i][j], i, j);
			j++;
		}
		i++;
	}
	if (data->player == 0 || data->player > 1)
		ft_exit(data, NO_PLAYER);
	return ;
}

void	is_valid_map(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	good_letters(data, data->map);
	while (data->map[i])
	{
		j = 0;
		while (data->map[i][j])
		{
			if ((data->map[i][j] == '0' && data->map[i + 1][j] == ' ')
			|| (data->map[i][j] == '0' && data->map[i - 1][j] == ' ')
			|| (data->map[i][j] == '0' && data->map[i][j + 1] == ' ')
			|| (data->map[i][j] == '0' && data->map[i][j - 1] == ' '))
				ft_exit(data, MAP_NO_CLOSE);
			else if (check_player(data->map, i, j))
				ft_exit(data, PLAYER_NO_CLOSE);
			j++;
		}
		i++;
	}
	return ;
}
