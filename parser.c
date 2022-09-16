/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsaeed <bsaeed@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/27 15:33:53 by bsaeed            #+#    #+#             */
/*   Updated: 2022/09/11 04:41:56 by bsaeed           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	*mapread(t_game *game, char *file)
{
	game->fd = open(file, O_RDONLY);
	game->temp = get_next_line(game->fd);
	if_null_exit(game->temp);
	game->linelen = ft_strlen(game->temp);
	game->totaline = 0;
	game->i = 0;
	game->y = 0;
	while (game->temp)
	{
		game->temp = get_next_line(game->fd);
		game->totaline++;
	}
	close(game->fd);
	game->fd = open(file, O_RDONLY);
	game->map = mallocer(game->map, game->totaline * game->linelen);
	while (game->y < game->totaline)
	{
		game->temp = get_next_line(game->fd);
		game->j = 0;
		while (game->j < game->linelen)
			game->map[game->i++] = game->temp[game->j++];
		game->y++;
	}
	game->map[game->i] = '\0';
	return (game->map);
}

void	mapsize(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	while (game->mapcheck[y] && y < game->totaline - 1)
	{
		x = 0;
		while (game->mapcheck[y][x])
			x++;
		if (x != game->linelen - 1)
		{
			ft_printf("\n\nMap size error, Not rectangular?\n\n");
			free_and_exit(game);
		}
		y++;
	}
	x--;
	if (!game->mapcheck[y])
	{
		ft_printf("\n\nEmpty line\n\n");
		free_and_exit(game);
	}
}

void	wallchecker_x(t_game *game)
{
	int	x;

	x = 0;
	while (game->mapcheck[0][x])
	{
		if (game->mapcheck[0][x] != '1' && game->mapcheck[0][x] != '\n'
		&& game->mapcheck[0][x] != 13)
		{
			ft_printf("\n\n\nIncorrect map border! Empty line?\n\n\n");
			free_and_exit(game);
		}
		x++;
	}
	x = 0;
	while (game->mapcheck[game->totaline - 1][x])
	{
		if (game->mapcheck[game->totaline - 1][x] != '1')
		{
			ft_printf("\n\n\nIncorrect map border! Empty line?\n\n\n");
			free_and_exit(game);
		}
		x++;
	}
}

void	wallchecker_y(t_game *game)
{
	int	y;
	int	x;

	y = 0;
	x = ft_strlen(game->mapcheck[y]) - 1;
	while (game->mapcheck[y])
	{
		if (game->mapcheck[y][0] != '1' || game->mapcheck[y][x] != '1')
		{
			ft_printf("\n\n\nIncorrect map border! Empty line?\n\n\n");
			free_and_exit(game);
		}
		y++;
	}
	y--;
	if (game->mapcheck[y][x + 1])
	{
		ft_printf("\nError in last line of map! Not rectangular?\n");
		free_and_exit(game);
	}
}

void	coincount(t_game *game)
{
	int	i;

	i = 0;
	while (game->map[i])
	{
		if (game->map[i] == 'C')
			game->coins++;
		i++;
	}
}
