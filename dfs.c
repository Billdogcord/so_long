/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dfs.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsaeed <bsaeed@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/05 04:30:15 by bsaeed            #+#    #+#             */
/*   Updated: 2022/09/10 22:40:59 by bsaeed           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_map_size(t_game *game)
{
	int	i;

	i = 0;
	while (game->mapcheck[0][i] != '\0')
		i++;
	game->size_x = i;
	i = 0;
	while (game->mapcheck[i] != NULL)
		i++;
	game->size_y = i;
}

void	find_player(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (i < game->size_y)
	{
		j = 0;
		while (j < game->size_x)
		{
			if (game->mapcheck[i][j] == 'P')
			{
				game->p_x = j;
				game->p_y = i;
				game->is_player++;
			}
			j++;
		}
		i++;
	}
	if (game->is_player != 1)
	{
		write(2, "\n\nNo or more than 1 Players found\n\n", 36);
		free_and_exit(game);
	}
}

void	find_exit(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (i < game->size_y)
	{
		j = 0;
		while (j < game->size_x)
		{
			if (game->mapcheck[i][j] == 'E')
			{
				game->is_exit++;
				game->e_x = j;
				game->e_y = i;
			}
			j++;
		}
		i++;
	}
	if (game->is_exit != 1)
	{
		write(2, "No or more than 1 Exits found!\n", 32);
		free_and_exit(game);
	}
	game->is_exit = 0;
}

int	validcheck(t_game *game, int x, int y)
{
	if (game->valid[y][x] == 1)
		return (1);
	if (game->mapcheck[y][x] == '1')
		return (1);
	return (0);
}

void	dfs(t_game *game, int x, int y)
{
	game->valid[y][x] = 1;
	if (game->mapcheck[y][x] == 'C')
		game->is_coin++;
	if (game->mapcheck[y][x] == 'E')
		game->is_exit++;
	if (validcheck(game, x, y - 1) == 0)
		dfs(game, x, y - 1);
	if (validcheck(game, x + 1, y) == 0)
		dfs(game, x + 1, y);
	if (validcheck(game, x, y + 1) == 0)
		dfs(game, x, y + 1);
	if (validcheck(game, x - 1, y) == 0)
		dfs(game, x - 1, y);
}
