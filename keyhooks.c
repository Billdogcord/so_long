/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyhooks.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsaeed <bsaeed@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/02 23:13:55 by bsaeed            #+#    #+#             */
/*   Updated: 2022/09/11 00:57:03 by bsaeed           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	set_pos_coins(t_game *game, int x, int y, int flag)
{
	if (flag == 1)
		ft_printf("Moves: %d\n", ++game->moves);
	if (flag == 2)
		ft_printf("Moves: %d\nMoves: %d\n", ++game->moves, ++game->moves);
	if (game->mapcheck[y][x] == 'C')
	{
		game->mapcheck[y][x] = '0';
		game->coins--;
	}
	game->p_x = x;
	game->p_y = y;
}

void	check_coins_exit(t_game *game)
{
	if (game->coins <= 0 && game->mapcheck[game->p_y][game->p_x] == 'E')
	{
		write(1, "WOHOOOO YOU WIN!\n", 18);
		close_window(game);
	}
}

void	mark_exit(t_game *game, int x, int y)
{
	if (game->markexit == 1 && game->mapcheck[y][x] != 'E')
	{
		draw_img(game, EXIT, game->e_x, game->e_y);
		game->markexit = 0;
	}
}

int	ft_move(t_game *game, int x, int y)
{
	if (game->mapcheck[game->p_y + y][game->p_x + x] == '1')
		return (0);
	else if (game->mapcheck[game->p_y + y][game->p_x + x] == 'E'
	&& game->coins > 0)
	{
		draw_img(game, SPACE, game->p_x, game->p_y);
		draw_img(game, EXITCAR, game->p_x + (x), game->p_y + (y));
		set_pos_coins(game, game->p_x + (x), game->p_y + (y), 1);
		game->markexit = 1;
	}
	else
	{
		draw_img(game, SPACE, game->p_x, game->p_y);
		draw_img(game, ME, game->p_x + x, game->p_y + y);
		set_pos_coins(game, game->p_x + x, game->p_y + y, 1);
		mark_exit(game, game->p_x + x, game->p_y + y);
		check_coins_exit(game);
	}
	return (0);
}

int	key_hook(int keycode, t_game *game)
{
	if (keycode == 13)
		ft_move(game, 0, -1);
	else if (keycode == 0)
		ft_move(game, -1, 0);
	else if (keycode == 1)
		ft_move(game, 0, 1);
	else if (keycode == 2)
		ft_move(game, 1, 0);
	else if (keycode == 53)
		close_window(game);
	return (0);
}
