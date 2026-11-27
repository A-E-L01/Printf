/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_unsigned.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboel-ma <aboel-ma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/27 00:50:54 by aboel-ma          #+#    #+#             */
/*   Updated: 2026/11/27 15:22:54 by aboel-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr_unsigned(unsigned int n)
{
	int	count;
	int	result;

	count = 0;
	if (n > 9)
	{
		count = ft_putnbr_unsigned(n / 10);
		if (count == -1)
 		return (-1);
	}
	result = ft_putchar((n % 10) + '0');
	if (result == -1)
 		return (-1);
	count = count + result;
	return (count);
}
