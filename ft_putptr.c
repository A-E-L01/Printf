/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboel-ma <aboel-ma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/27 00:50:05 by aboel-ma          #+#    #+#             */
/*   Updated: 2026/11/27 15:25:49 by aboel-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putptr(void *ptr)
{
	int				count;
	int				result;
	unsigned long	addr;

	if (ptr == NULL)
	{
		result = write(1, "(nil)", 5);
		if (result == -1)
 			return (-1);
		return (result);
	}
	addr = (unsigned long)ptr;
	result = write(1, "0x", 2);
	if (result == -1)
 			return (-1);
	count = ft_putnbr_hexa(addr, 'x');
	if (count == -1)
 		return (-1);
	count = count + result;
	return (count);
}
