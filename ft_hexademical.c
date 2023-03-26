/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexademical.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ziharuty <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 18:53:24 by ziharuty          #+#    #+#             */
/*   Updated: 2023/02/17 20:21:12 by ziharuty         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	readhex(unsigned long n)
{
	int	len;

	len = 0;
	while (n >= 16)
	{
		len++;
		n = n / 16;
	}
	len++;
	return (len);
}

int	ft_hexput(unsigned long long num, const char conv)
{
	if (num >= 16)
	{
		ft_hexademical(num / 16, conv);
		ft_hexademical(num % 16, conv);
	}
	else
	{
		if (num <= 9)
			ft_putchar(num + '0');
		else
		{
			if (conv == 'x')
				ft_putchar((num - 10 + 'a'));
			if (conv == 'X')
				ft_putchar(num - 10 + 'A');
			if (conv == 'p')
				ft_putchar((num - 10 + 'a'));
		}
	}
	return (num);
}

int	ft_hexademical(unsigned long long num, const char conv)
{
	if (num == 0)
		return (write(1, "0", 1));
	else
		ft_hexput(num, conv);
	return (readhex(num));
}
