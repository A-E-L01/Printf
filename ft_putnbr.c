/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboel-ma <aboel-ma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/27 00:46:52 by aboel-ma          #+#    #+#             */
/*   Updated: 2026/11/27 15:24:22 by aboel-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr(long n)
{
	int	count;
	int	result;

	count = 0;
	if (n < 0)
	{
		count = count + write (1, "-", 1);
		if (count == -1)
 			return (-1);
		n = n * -1;
	}
	if (n > 9)
	{
		count = count + ft_putnbr(n / 10);
		if (count == -1)
 			return (-1);
	}
	result = ft_putchar((n % 10) + '0');
	if (result == -1)
 			return (-1);
	count = count + result;
	return (count);
}
