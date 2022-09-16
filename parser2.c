/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsaeed <bsaeed@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/03 00:02:30 by bsaeed            #+#    #+#             */
/*   Updated: 2022/09/11 06:47:19 by bsaeed           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	charactercheck(t_game *game)
{
	int	i;

	i = 0;
	while (game->map[i])
	{
		if (game->map[i] != '1' && game->map[i] != 'C'
			&& game->map[i] != 'E' && game->map[i] != '0'
			&& game->map[i] != 'P' && game->map[i] != '\n')
		{
			write(2, "Invalid Character found in the map!\n", 36);
			free_and_exit(game);
		}
		i++;
	}
}

void	pick_img(t_game *game, char c, int x, int y)
{
	if (c == '1')
		draw_img(game, WALL, x, y);
	else if (c == 'P')
	{
		draw_img(game, ME, x, y);
		game->p_x = x;
		game->p_y = y;
	}
	else if (c == '0')
		draw_img(game, SPACE, x, y);
	else if (c == 'C')
		draw_img(game, COLLECTIBLE, x, y);
	else if (c == 'E')
		draw_img(game, EXIT, x, y);
}

void	draw_img(t_game *game, char *path, int x, int y)
{
	int	size;

	size = 64;
	x = x * size;
	y = y * size;
	game->img = mlx_xpm_file_to_image(game->mlx, path, &size, &size);
	mlx_put_image_to_window(game->mlx, game->mlx_window, game->img, x, y);
	mlx_destroy_image(game->mlx, game->img);
}

void	draw_map(t_game *game)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (game->mapcheck[y])
	{
		x = 0;
		while (game->mapcheck[y][x])
		{
			pick_img(game, game->mapcheck[y][x], x, y);
			x++;
		}
		y++;
	}
}

void	close_window(t_game *game)
{
	mlx_clear_window(game->mlx, game->mlx_window);
	mlx_destroy_window(game->mlx, game->mlx_window);
	exit(0);
}
