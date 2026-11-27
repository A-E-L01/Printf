/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboel-ma <aboel-ma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/25 12:12:06 by aboel-ma          #+#    #+#             */
/*   Updated: 2026/11/27 15:26:38 by aboel-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putstr(char *s)
{
	int	index;
	int	count;
	int	result;

	index = 0;
	count = 0;
	if (s == NULL)
	{
		result = write(1, "(null)", 6);
		if (result == -1)
 			return (-1);
		return (result);
	}
	while (s[index])
	{
		result = write (1, &s[index], 1);
		if (result == -1)
 			return (-1);
		count = count + result;
		index++;
	}
	return (count);
}
