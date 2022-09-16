/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsaeed <bsaeed@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 23:57:37 by bsaeed            #+#    #+#             */
/*   Updated: 2022/09/10 22:49:50 by bsaeed           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	free_split(char **s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		free (s[i]);
		i++;
	}
	free (s);
}

void	hashmarker(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (i < 256)
	{
		j = 0;
		while (j < 256)
		{
			game->valid[i][j] = 0;
			j++;
		}
		i++;
	}
}

void	if_null_exit(char *file)
{
	if (!file)
	{
		write(2, "\n\nInvalid file folder! Classic directory trick?!\n\n", 51);
		exit(EXIT_FAILURE);
	}
}

void	free_and_exit(t_game *game)
{
	free_split(game->mapcheck);
	free(game->map);
	exit(EXIT_FAILURE);
}

int	bercheck(char *av)
{
	int	i;

	i = ft_strlen(av);
	if (av[i - 1] == 'r' && av[i - 2] == 'e'
		&& av[i - 3] == 'b' && av[i - 4] == '.')
		return (0);
	write(2, "[USAGE][NOT A VALID .ber FILE]\n", 32);
	exit (1);
}
