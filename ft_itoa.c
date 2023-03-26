/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ziharuty <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 18:50:29 by ziharuty          #+#    #+#             */
/*   Updated: 2023/02/17 20:21:19 by ziharuty         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static	size_t	get_my_digits(int nn)
{
	int		digit;
	long	n;

	digit = 0;
	n = nn;
	if (n < 0)
	{
		n = -n;
		digit++;
	}
	while (n > 9)
	{
		digit++;
		n = n / 10;
	}
	digit++;
	return (digit);
}

char	*ft_itoa(int n)
{
	char		*str_num;
	long		num;
	int			digits;

	num = n;
	digits = get_my_digits(n);
	str_num = malloc(digits + 1);
	if (!str_num)
		return (NULL);
	str_num[digits] = '\0';
	digits--;
	if (num == 0)
		str_num[0] = '0';
	if (num < 0)
	{
		str_num[0] = '-';
		num = -num;
	}
	while (num > 0)
	{
		str_num[digits] = (num % 10) + '0';
		num = num / 10;
		digits--;
	}
	return (str_num);
}
