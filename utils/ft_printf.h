/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsaeed <bsaeed@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/22 01:38:14 by bsaeed            #+#    #+#             */
/*   Updated: 2022/04/23 18:04:45 by bsaeed           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>

void	ft_putptr(unsigned long n);
int		ft_printptr(unsigned long ptr);
int		ft_printunbr(unsigned int i);
void	ft_putstr(char *str);
int		ft_printstr(char *str);
int		ft_printnbr(int i);
int		ft_printpercent(void);
void	ft_putchar(char c);
int		ft_printchar(int c);
void	ft_putnbr(int nb);
void	ft_uputnbr(unsigned int nb);
int		ft_parse(va_list ap, char parse);
int		ft_printf(const char *s, ...);
int		ft_puthex(unsigned int nb, char c);

#endif
