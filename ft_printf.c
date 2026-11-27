/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboel-ma <aboel-ma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/22 23:46:02 by aboel-ma          #+#    #+#             */
/*   Updated: 2026/11/27 15:24:14 by aboel-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(char c)// 3lach katakhd int
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

int	ft_putnbr(long n)//int n
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

int	ft_putnbr_hexa(unsigned long n, char c)// unsigned int n
{
	int		count;
	int		result;
	char	*base;

	count = 0;
	if (c == 'x')
		base = "0123456789abcdef";
	else if (c == 'X')
		base = "0123456789ABCDEF";
	if (n > 15)
	{
		result = ft_putnbr_hexa(n / 16, c);
		if (result == -1)
 			return (-1);
		count = result;
	}
	result = ft_putchar(base[(n % 16)]);
	if (result == -1)
 		return (-1);
	count = count + result;
	return (count);
}

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

int	ft_conversion(va_list *args, char c)
{
	if (c == 'c')
		return (ft_putchar(va_arg(*args, int)));
	else if (c == 's')
		return (ft_putstr(va_arg(*args, char *)));
	else if (c == 'p')
		return (ft_putptr(va_arg(*args, void *)));
	else if (c == 'd' || c == 'i')
		return (ft_putnbr(va_arg(*args, int)));//
	else if (c == 'u')
		return (ft_putnbr_unsigned(va_arg(*args, unsigned int)));
	else if (c == 'x' || c == 'X')
		return (ft_putnbr_hexa(va_arg(*args, unsigned int) ,c));
	else if (c == '%')
		return (ft_putchar('%'));
	return (-1);
}

int	ft_printf(const char *str, ...)
{
	int		index;
	int		count;
	int		check;
	va_list	args;

	index = 0;
	count = 0;
	//check = 0;
	if (str == NULL || write(1, "", 0) == -1)//
		return (-1);
	va_start(args, str);
	while (str[index] != '\0')
	{
		if (str[index] == '%' && str[index + 1] != '\0')
		{
			check = ft_conversion(&args, str[++index]);
			if (check == -1)// ziyada hiyd
			//{
			//	va_end(args);//
				return (va_end(args), -1);
			//}
			count = count + check;
		}
		else if (str[index] == '%' && str[index + 1] == '\0')
			return (va_end(args), -1);// va_end
		else
			count = count + ft_putchar(str[index]);
		index++;
	}
	//va_end(args);
	return (va_end(args), count);
}

int main(void)
{
	ft_printf("Hello World\n");
	ft_printf("Character: %c\n", 'A');
	ft_printf("String: %s\n", "1337");
	ft_printf("Integer: %d\n", -2147483648);
	ft_printf("Unsigned: %u\n", 4294967295u);
	ft_printf("Hex: %x\n", 255);
	ft_printf("HEX: %X\n", 255);
	ft_printf("Pointer: %p\n", NULL);
	ft_printf("Percent: %%\n");
    return (0);
}
