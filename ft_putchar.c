/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboel-ma <aboel-ma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/24 15:36:19 by aboel-ma          #+#    #+#             */
/*   Updated: 2026/11/24 15:59:42 by aboel-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(char c)
{
	int	count;
	int	index;
	
	count = 0;
	index = write (1, &c, 1);
	if (index == -1)
		return (-1);
	count = count + index;
	return (count);
}

int	ft_putchar(char c)
{
	return (write (1, &c, 1));
}
