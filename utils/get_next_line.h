/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsaeed <bsaeed@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/13 23:05:24 by bsaeed            #+#    #+#             */
/*   Updated: 2022/08/27 18:41:40 by bsaeed           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>

char	*ft_strdup(char *str);
char	*ft_strjoin(char *one, char *two);
char	*ft_strchr(char *str, int c);
char	*mallocer(char *a, int i);
int		nl_checker(char *str);
int		ft_strlen(char *str);
char	*gnl_line(char *str);
char	*gnl_remains(char *str);
char	*readfile(int fd, char *str);
char	*get_next_line(int fd);

#endif
