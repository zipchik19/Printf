/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printu.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ziharuty <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 18:52:10 by ziharuty          #+#    #+#             */
/*   Updated: 2023/02/17 20:21:52 by ziharuty         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printu(long nb)
{
	char	value;
	int		counter;

	counter = 0;
	if (nb == 0)
		return (write(1, "0", 1));
	if (nb > 9)
	{
		counter += ft_printu(nb / 10);
		counter += ft_printu(nb % 10);
	}
	else
	{
		value = (nb + '0');
		counter += write(1, &value, 1);
	}
	return (counter);
}
