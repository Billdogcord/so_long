/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsaeed <bsaeed@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/31 01:44:16 by bsaeed            #+#    #+#             */
/*   Updated: 2022/09/11 07:01:02 by bsaeed           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	validchecker(t_game *game)
{
	check_map_size(game);
	find_player(game);
	find_exit(game);
	dfs(game, game->p_x, game->p_y);
	if (game->coins == 0)
	{
		write(2, "\n\nNo Collectibles found\n\n", 26);
		free_and_exit(game);
	}
	else if (game->is_coin != game->coins || game->is_exit != 1)
	{
		write(2, "\n\nInvalid Map Path, Exit or Coins not met\n\n", 44);
		free_and_exit(game);
	}
}

void	windowmaker(t_game *game)
{
	game->mlx_window = mlx_new_window(game->mlx, game->size_x * 64,
			game->size_y * 64, "so_long");
}

int	mouse_event(t_game *game)
{
	close_window(game);
	return (0);
}

void	mainchecker(t_game *game)
{
	game->moves = 0;
	game->is_exit = 0;
	game->is_coin = 0;
	game->coins = 0;
	game->is_player = 0;
	game->markexit = 0;
	mapsize(game);
	wallchecker_x(game);
	wallchecker_y(game);
	coincount(game);
	charactercheck(game);
	hashmarker(game);
	validchecker(game);
}

int	main(int ac, char *av[])
{
	t_game	game;

	if (ac != 2)
	{
		ft_printf("[USAGE] [NEED 2 ARGUMENTS]\n");
		exit (EXIT_FAILURE);
	}
	bercheck(av[1]);
	game.map = mapread(&game, av[1]);
	game.mapcheck = ft_split(game.map, '\n');
	mainchecker(&game);
	game.mlx = mlx_init();
	if (!game.mlx)
		return (0);
	windowmaker(&game);
	draw_map(&game);
	mlx_key_hook(game.mlx_window, key_hook, &game);
	mlx_hook(game.mlx_window, 17, 0, mouse_event, &game);
	mlx_loop(game.mlx);
	free(game.map);
	free(game.mapcheck);
	return (0);
}
