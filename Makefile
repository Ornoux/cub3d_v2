# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: npatron <npatron@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/09 18:09:47 by npatron           #+#    #+#              #
#    Updated: 2024/05/12 20:49:05 by npatron          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3D

SOURCES = src/main.c \
		  src/parsing/get_file.c \
		  src/parsing/get_map.c \
		  src/parsing/run_parsing.c \
		  src/parsing/get_textures.c \
		  src/utils/utils.c \
		  src/utils/ft_atoi.c \
		  src/utils/ft_split.c \
		  src/utils/get_next_line/get_next_line.c \
		  src/utils/get_next_line/get_next_line_utils.c \
		  src/parsing/get_colors.c \
		  src/parsing/colors_to_int.c \
		 
		  
			
OBJECTS  = ${SOURCES:.c=.o}

CFLAGS     = -Wall -Wextra -Werror -g -O3 #-fsanitize=address

.c.o:#
	clang $(CFLAGS) -c $< -o ${<:.c=.o}

$(NAME): ${MLX} ${OBJECTS}
	clang $(CFLAGS) ${OBJECTS} $(LDFLAGS) -o $(NAME)

all: $(NAME)

clean:
	rm -f ${OBJECTS}

fclean: clean
	rm -f $(NAME)

re: fclean all