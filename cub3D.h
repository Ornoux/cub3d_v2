/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npatron <npatron@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 18:09:49 by npatron           #+#    #+#             */
/*   Updated: 2024/05/09 19:09:46 by npatron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <math.h>
# include <fcntl.h>

# define ARG "Error\ncub3D needs to be launched with a '*.cub'"
# define FD "Error\nFile cannot be open"
# define EMPTY_FILE "Error\nFile is empty"

typedef struct s_data
{
	int		*dir;
	char	**textures;
	char	**colors;
	char	**map;
	char	player_direction;
}			t_data;

// GET_NEXT_LINE PART

char	*get_next_line(int fd);
char	*ft_strjoin(const char *s1, const char *s2);
char	*ft_strdup(char *src);
char	*ft_strchr(const char *s, int c);
void	*ft_calloc(size_t nmemb, size_t size);
int		ft_strlen(const char *s);

// UTILS PART

int	print_error(char *s);
int	get_file(char **argv);
int	lines_into_files(char *argv);



#endif