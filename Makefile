# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: npatron <npatron@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/09 18:09:47 by npatron           #+#    #+#              #
#    Updated: 2024/05/10 16:14:15 by npatron          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3D

SOURCES = src/main.c \
		  src/utils/utils.c \
		  src/utils/get_next_line/get_next_line.c \
		  src/utils/get_next_line/get_next_line_utils.c \
		  src/utils/get_file.c \
		 
		  
			
OBJECTS  = ${SOURCES:.c=.o}

CFLAGS     = -Wall -Wextra -Werror -g -O3 ##-fsanitize=leak

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