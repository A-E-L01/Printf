/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboel-ma <aboel-ma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/22 23:46:02 by aboel-ma          #+#    #+#             */
/*   Updated: 2026/11/25 14:15:10 by aboel-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(char c)
{
	//int	count;
	int	index;
	
	//count = 0;
	index = write (1, &c, 1);
	if (index == -1)
		return (-1);
	//count = count + index;
	return (/*count*/index);
}


int	ft_check(char c, va_list *list)//ft_conversion(const char type, va_list vargs)
{
	if (c == 'c')
		return (CHAR);
	else if(c == 's')
		return ();
	else if(c == 'p')
		return ();
	else if(c == 'd')
		return ();
	else if(c == 'i')
		return ();
	else if(c == 'u')
		return ();
	else if(c == 'x')
		return ();
	else if(c == 'X')
		return ();
	else if(c == '%')
		return (ft_putchar('%'));// write(1, "%", 1);

	return (-1);
}

if (type == CHAR)
	*count += ft_putchar(va_arg(*list, int))

int	ft_putnbr(long nb);
int	ft_putnbr_hexa(unsigned long nbr, char up);
int	ft_putptr(void *ptr);
int	ft_putstr(char *str1);
int ft_putchar(char c);//V


int ft_printf(const char *str, ...)
{
	int	index;
	int	count;
	int	check;
	
	index = 0;
	count = 0;
	check = 0;
	if (str == NULL)
		return (-1);
	while (str[index] != '\0')
	{
		if (str[index] == '%')
		{
			check = ft_check(str[++index], );
			if (check == -1)
				return (-1);
			count = count + check;
		}
		else
		{
			count = count + ft_putchar(str[index]);
		}
		index++;
	}
	
	return (count);
}

int main()
{
	printf("%d\n", ft_printf("abc"));
	return (0);
}