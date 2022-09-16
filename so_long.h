/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsaeed <bsaeed@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/26 17:19:01 by bsaeed            #+#    #+#             */
/*   Updated: 2022/09/11 06:11:50 by bsaeed           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# include "mlx/mlx.h"
# include "utils/get_next_line.h"
# include "utils/ft_printf.h"

# define WALL "./img/wall.xpm"
# define ME "./img/me.xpm"
# define SPACE "./img/spaces.xpm"
# define COLLECTIBLE "./img/collectible.xpm"
# define EXIT "./img/exit.xpm"
# define EXITCAR "./img/exit_car.xpm"

typedef struct t_game
{
	int		fd;
	int		linelen;
	int		totaline;
	char	*temp;
	int		y;
	int		j;
	int		i;
	int		*mlx_window;
	int		moves;
	int		size_x;
	int		size_y;
	int		p_x;
	int		p_y;
	int		e_x;
	int		e_y;
	int		valid[256][256];
	int		is_exit;
	int		is_coin;
	int		is_player;
	int		coins;
	int		markexit;

	char	*map;
	char	**mapcheck;
	char	*mlx;
	void	*img;
}	t_game;

char	**ft_split(char *s, char c);
char	*mapread(t_game *game, char *file);
void	mapsize(t_game *game);
void	wallchecker_x(t_game *game);
void	wallchecker_y(t_game *game);
void	coincount(t_game *game);
void	free_split(char **s);
void	draw_map(t_game *game);
void	pick_img(t_game *game, char c, int x, int y);
void	draw_img(t_game *game, char *path, int x, int y);
void	close_window(t_game *game);
int		key_code_x_right(t_game *game);
int		key_code_x_left(t_game *game);
int		key_code_y_up(t_game *game);
int		key_code_y_down(t_game *game);
int		key_hook(int keycode, t_game *game);
void	hashmarker(t_game *game);
void	windowmaker(t_game *game);
int		validcheck(t_game *game, int x, int y);
void	check_map_size(t_game *game);
void	find_player(t_game *game);
void	find_exit(t_game *game);
void	dfs(t_game *game, int x, int y);
void	charactercheck(t_game *game);
int		mouse_event(t_game *game);
void	if_null_exit(char *file);
void	free_and_exit(t_game *game);
void	right_wall_check(t_game *game);
int		bercheck(char *av);

#endif