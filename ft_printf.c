/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ziharuty <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 17:05:49 by ziharuty          #+#    #+#             */
/*   Updated: 2023/02/20 16:43:54 by ziharuty         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printchar(char c)
{
	write (1, &c, 1);
	return (1);
}
//////
int	ft_putde(int arg)
{
	char	*str;
	int		len;

	str = ft_itoa(arg);
	len = ft_printstr(str);
	free(str);
	return (len);
}

int	ft_printfconv(va_list str, char const c)
{
	int	count;

	count = 0;
	if (c == 'c')
		count += ft_printchar(va_arg(str, int));
	else if (c == 's')
		count += ft_printstr(va_arg(str, char *));
	else if (c == 'd' || c == 'i')
		count += ft_putde(va_arg(str, int));
	else if (c == 'p')
	{
		count += write(1, "0x", 2);
		count += ft_hexademical(va_arg(str, unsigned long long), c);
	}
	else if (c == 'x' || c == 'X')
		count += ft_hexademical(va_arg(str, unsigned int), c);
	else if (c == 'u')
		count += ft_printu(va_arg(str, unsigned int));
	else if (c == '%')
		count += ft_printchar('%');
	else
		count += ft_printchar(c);
	return (count);
}

int	ft_printf(const char *str, ...)
{
	int		count;
	va_list	args;
	int		i;

	count = 0;
	i = 0;
	va_start(args, str);
	while (str[i])
	{
		if (str[i] == '%' && str[i + 1])
		{
			count += ft_printfconv(args, str[i + 1]);
			i++;
		}
		else
			count += ft_printchar(str[i]);
		i++;
	}
	va_end(args);
	return (count);
}
