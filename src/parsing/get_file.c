/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_file.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npatron <npatron@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 18:53:45 by npatron           #+#    #+#             */
/*   Updated: 2024/05/14 17:46:15 by npatron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3D.h"

static bool	is_good_extension(char *s)
{
	int	i;

	i = 0;
	while (s[i] != '.')
		i++;
	if (s[i + 1] == 'c' && s[i + 2] == 'u' && s[i + 3] == 'b' && s[i + 4] == '\0')
		return (true);
	return (false);
}

int	lines_into_files(char *argv)
{
	int		fd;
	int		lines;
	char	*s;

	fd = open(argv, O_RDONLY);
	lines = 0;
	s = get_next_line(fd);
	while (s)
	{
		free(s);
		lines++;
		s = get_next_line(fd);
	}
	close(fd);
	return (lines);
}

void	get_file_2(t_data *data, int fd)
{
	char	*s;
	int		i;

	i = 0;
	while (i < data->lines_into_file)
	{
		s = get_next_line(fd);
		data->file[i] = ft_strdup(s);
		free(s);
		i++;
	}

	data->file[i] = NULL;
	return ;
}

void	get_file(t_data *data, char **argv)
{
	int fd;
	int	i;

	i = 0;
	fd = open(argv[1], O_RDONLY);
	if (is_good_extension(argv[1]) == false)
		ft_exit(data, BAD_EXTENSION);
	if (fd == -1)
		ft_exit(data, FD);
	data->lines_into_file = lines_into_files(argv[1]);
	if (data->lines_into_file == 0)
		ft_exit(data, EMPTY_FILE);
	data->file = malloc(sizeof(char *) * (data->lines_into_file + 1));
	get_file_2(data, fd);
	close(fd);
	return ;
}