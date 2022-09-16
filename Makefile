# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bsaeed <bsaeed@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/24 18:19:17 by bsaeed            #+#    #+#              #
#    Updated: 2022/09/11 00:56:24 by bsaeed           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC		=	so_long.c parser.c parser2.c keyhooks.c dfs.c \
			utils/get_next_line.c utils/get_next_line_utils.c \
			utils/utils.c utils/utils2.c utils/ft_help2.c utils/ft_printptr.c \
			utils/ft_help1.c utils/ft_printf.c utils/ft_printhexa.c utils/ft_printunsign.c


OBJ		= $(SRC:.c=.o)

CFLAGS	= -Wall -Wextra -Werror

NAME	= so_long

$(NAME): $(OBJ)
		$(MAKE) -C mlx
		gcc $(OBJ) -Lmlx -lmlx -framework OpenGL -framework AppKit -o $(NAME)

%.o: %.c
	$(CC) -Wall -Wextra -Werror -D BUFFER_SIZE=1 -Imlx  -c $< -o $@

all:	$(NAME)


clean:
		rm -f $(OBJ)
		$(MAKE) clean -C mlx
fclean: clean
		rm -f $(NAME)
re:		fclean all

.PHONY:	all clean fclean re


