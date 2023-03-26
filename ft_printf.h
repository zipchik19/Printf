/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   head.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ziharuty <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 17:08:20 by ziharuty          #+#    #+#             */
/*   Updated: 2023/02/17 20:21:31 by ziharuty         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <string.h>
# include <stdarg.h>
# include <unistd.h>
# include <stdio.h>

void	ft_putstr(char *s);
int		ft_printstr(char *s);
int		ft_hexademical(unsigned long long num, const char conv);
int		ft_printf(const char *str, ...);
int		ft_printu(long nb);
char	*ft_itoa(int n);
void	ft_putchar(char c);

#endif
