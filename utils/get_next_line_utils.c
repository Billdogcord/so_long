/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsaeed <bsaeed@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/17 18:32:45 by bsaeed            #+#    #+#             */
/*   Updated: 2022/06/17 20:08:01 by bsaeed           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*mallocer(char *a, int i)
{
	a = malloc(sizeof(char) * i);
	if (!a)
		return (NULL);
	return (a);
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
		i++;
	return (i);
}

char	*ft_strdup(char *str)
{
	char	*heap;
	int		i;
	int		j;

	heap = NULL;
	if (!str)
		return (NULL);
	heap = mallocer(heap, ft_strlen(str) + 1);
	i = 0;
	j = 0;
	while (str[i])
		heap[j++] = str[i++];
	heap[j] = '\0';
	return (heap);
}

char	*ft_strjoin(char *one, char *two)
{
	char	*heap;
	int		i;
	int		j;

	i = 0;
	j = 0;
	heap = NULL;
	if (!one)
	{
		one = mallocer(one, 1);
		one[0] = '\0';
	}
	if (!two)
		return (NULL);
	heap = mallocer(heap, ft_strlen(one) + ft_strlen(two) + 1);
	while (one[i] != '\0')
		heap[i++] = one[j++];
	j = 0;
	while (two[j] != '\0')
		heap[i++] = two[j++];
	heap[i] = '\0';
	free(one);
	return (heap);
}

char	*ft_strchr(char *str, int c)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	if ((char)c == '\0')
		return (&str[ft_strlen(str)]);
	while (str[i])
	{
		if (str[i] == (char)c)
			return (&str[i]);
		i++;
	}
	return (0);
}
