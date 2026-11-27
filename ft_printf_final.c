/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_final.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboel-ma <aboel-ma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/26 15:21:24 by aboel-ma          #+#    #+#             */
/*   Updated: 2026/11/26 23:11:30 by aboel-ma         ###   ########.fr       */
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

int	ft_putnbr(int n)
{
	int	count;
	
	if (n == -2147483648)
	{
		count = write (1, "-2147483648", 11);
		return (count);
	}
	if (n < 0)
	{
		count = write (1, "-", 1);
		n = n * -1;
	}
	if (n > 9)
	{
		count = ft_putnbr(n / 10);
	}
	count = count +ft_putchar((n % 10) + '0');
	return (count);
}

int	ft_putstr(char *s)
{
	int	index;
	int	count;

	index = 0;
	count = 0;
	if (s == NULL)
		return (write(1, "(null)", 6));
	while (s[index])
	{
		count = count + write (1, &s[index], 1);
		index++;
	}
	return (count);
}
int	ft_putnbr_hexa(unsigned int n, char c)
{
	int		count;
	//int		index;
	char	*base;
	
	count = 0;
	if (c == 'x')
		base = "0123456789abcdef";
	else if (c == 'X')
		base = "0123456789ABCDEF";
		
	// if (n == -2147483648)
	// {
	// 	count = write (1, "-2147483648", 11);
	// 	return (count);
	// }
	// if (n < 0)
	// {
	// 	count = write (1, "-", 1);
	// 	n = n * -1;
	// }
	if (n > 15)
	{
		count = ft_putnbr_hexa(n / 16, c);
	}
	count = count + ft_putchar(base[(n % 16)]);
	return (count);
}
int	ft_putptr(void *ptr)
{
	int				count;
	int				result;
	unsigned int	addr;

	count = 0;
	result = 0;
	addr = (unsigned int)ptr;
	result = write(1, "0x", 2);
	count = result + ft_putnbr_hexa(addr, 'x');
	return (count);
}
int	ft_putptr(void *ptr)
{
	int				count;// ptr == null check
	int				result;
	unsigned long	addr;

	//count = 0;
	//result = 0;
	if (ptr == NULL)
		return (write(1, "(nil)", 5));
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
int ft_putnbr_unsigned(unsigned int n)
{
	int	count;

	count = 0;
	if (n > 9)
	{
		count = ft_putnbr_unsigned(n / 10);
	}
	count = count +ft_putchar((n % 10) + '0');
	return (count);
	
	return (count);
}

int	ft_check(char c/*, va_list *list*/)//ft_conversion(const char type, va_list vargs)
{
	if (c == 'c')
		return (ft_putchar(c));
	else if(c == 's')
		return (ft_putstr());
	else if(c == 'p')
		return (ft_putptr());
	else if(c == 'd' || c == 'i')
		return (ft_putnbr());
	// else if(c == 'i')
	// 	return ();
	else if(c == 'u')// unsigned int 
		return (ft_putnbr_unsigned());
	else if(c == 'x' || c == 'X')
		return (ft_putnbr_hexa());
	// else if(c == 'X')
	// 	return ();
	else if(c == '%')
		return (ft_putchar('%'));// write(1, "%", 1);

	return (-1);
}

if (type == CHAR)
	*count += ft_putchar(va_arg(*list, int))

.int	ft_putnbr(long nb);//v
.int	ft_putnbr_hexa(unsigned long nbr, char up);
.int	ft_putptr(void *ptr);
.int	ft_putstr(char *str1);//v
.int ft_putchar(char c);//V


int ft_printf(const char *str, ...)
{
	int	index;
	int	count;
	int	check;
	
	index = 0;
	count = 0;
	check = 0;
	if (str == NULL)/if (str == NULL || write(1, "", 0) == -1)
		return (-1);
	while (str[index] != '\0')
	{
		if (str[index] == '%')
		{
			check = ft_check(str[++index]);
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











// int	ft_putchar(char c)// 3lach katakhd int
// {
// 	int	count;

// 	count = write (1, &c, 1);
// 	if (count == -1)
// 		return (-1);
// 	return (count);
// }
// int	ft_putnbr(int n)
// {
// 	int	count;
// 	int	result;
	
// 	count = 0;
// 	if (n == -2147483648)
// 	{
// 		count = write (1, "-2147483648", 11);
// 		if (count == -1)
// 			return (-1);
// 		return (count);
// 	}
// 	if (n < 0)
// 	{
// 		count = write (1, "-", 1);//
// 		if (count == -1)
// 			return (-1);
// 		n = n * -1;
// 	}
// 	if (n > 9)
// 	{
// 		count = ft_putnbr(n / 10);//
// 		if (count == -1)
// 			return (-1);
// 	}
// 	result = ft_putchar((n % 10) + '0');
// 	if (result == -1)
// 		return (-1);
// 	count = count + result;
// 	return (count);
// }
// int	ft_putstr(char *s)
// {
// 	int	index;
// 	int	count;
// 	int	result;

// 	index = 0;
// 	count = 0;
// 	if (s == NULL)
// 	{	
// 		result = write(1, "(null)", 6);
// 		if (result == -1)
// 			return (-1);
// 		return (result);
// 	}
// 	while (s[index])
// 	{
// 		result = write (1, &s[index], 1);
// 		if (result == -1)
// 			return (-1);
// 		count = count + result;
// 		index++;
// 	}
// 	return (count);
// }
// int	ft_putnbr_hexa(unsigned int n, char c)//
// {
// 	int		count;
// 	int		result;
// 	char	*base;
	
// 	count = 0;
// 	if (c == 'x')
// 		base = "0123456789abcdef";
// 	else if (c == 'X')
// 		base = "0123456789ABCDEF";
// 	if (n > 15)
// 	{
// 		result = ft_putnbr_hexa(n / 16, c);
// 		if (result == -1)
// 			return (-1);
// 		count = result;
// 	}
// 	result = ft_putchar(base[(n % 16)]);
// 	if (result == -1)
// 		return (-1);
// 	count = count + result;
// 	return (count);
// }
// int	ft_putptr(void *ptr)//
// {
// 	int				count;// ptr == null check
// 	int				result;
// 	unsigned long	addr;

// 	if (ptr == NULL)
// 	{	
// 		result = write(1, "(nil)", 5);
// 		if (result == -1)
// 			return (-1);
// 		return (result);
// 	}
// 	addr = (unsigned long)ptr;
// 	result = write(1, "0x", 2);
// 	if (result == -1)
// 		return (-1);
// 	count = ft_putnbr_hexa(addr, 'x');
// 	if (count == -1)
// 		return (-1);
// 	count = count + result;
// 	return (count);
// }
// int ft_putnbr_unsigned(unsigned int n)
// {
// 	int	count;
// 	int	result;

// 	count = 0;
// 	if (n > 9)
// 	{
// 		count = ft_putnbr_unsigned(n / 10);
// 		if (count == -1)
// 			return (-1);
// 	}
// 	result = ft_putchar((n % 10) + '0');
// 	if (result == -1)
// 		return (-1);
// 	count = count + result;
// 	return (count);
// }

// int	ft_conversion(va_list *args, char c)
// {
// 	if (c == 'c')
// 		return (ft_putchar(va_arg(*args, int)));
// 	else if(c == 's')
// 		return (ft_putstr(va_arg(*args, char *)));
// 	else if(c == 'p')
// 		return (ft_putptr(va_arg(*args, void *)));
// 	else if(c == 'd' || c == 'i')
// 		return (ft_putnbr(va_arg(*args, int)));
// 	else if(c == 'u')
// 		return (ft_putnbr_unsigned(va_arg(*args, unsigned int)));
// 	else if(c == 'x' || c == 'X')
// 		return (ft_putnbr_hexa(va_arg(*args, unsigned int) ,c));
// 	else if(c == '%')
// 		return (ft_putchar('%'));
// 	return (-1);
// }

// int ft_printf(const char *str, ...)
// {
// 	int	index;
// 	int	count;
// 	int	check;
// 	va_list	args;
	
// 	index = 0;
// 	count = 0;
// 	check = 0;
// 	if (str == NULL || write(1, "", 0) == -1)
// 		return (-1);
// 	va_start(args, str);
// 	while (str[index] != '\0')
// 	{
// 		if (str[index] == '%')
// 		{
// 			check = ft_conversion(/*args*/, str[++index]);
// 			if (check == -1)
// 				return (-1);
// 			count = count + check;
// 		}
// 		else
// 		{
// 			count = count + ft_putchar(str[index]);
// 		}
// 		index++;
// 	}
// 	va_end(args);
// 	return (count);
// }

// int main()
// {
// 	printf("%d\n", ft_printf("abc"));
// 	return (0);
// }











// int	ft_putchar(char c)// 3lach katakhd int
// {
// 	int	count;

// 	count = write (1, &c, 1);
// 	if (count == -1)
// 		return (-1);
// 	return (count);
// }
// int	ft_putnbr(int n)
// {
// 	int	count;
// 	int	result;
	
// 	count = 0;
// 	if (n == -2147483648)
// 	{
// 		count = write (1, "-2147483648", 11);
// 		if (count == -1)
// 			return (-1);
// 		return (count);
// 	}
// 	if (n < 0)
// 	{
// 		count = write (1, "-", 1);//
// 		if (count == -1)
// 			return (-1);
// 		n = n * -1;
// 	}
// 	if (n > 9)
// 	{
// 		count = ft_putnbr(n / 10);//
// 		if (count == -1)
// 			return (-1);
// 	}
// 	result = ft_putchar((n % 10) + '0');
// 	if (result == -1)
// 		return (-1);
// 	count = count + result;
// 	return (count);
// }
// int	ft_putstr(char *s)
// {
// 	int	index;
// 	int	count;
// 	int	result;

// 	index = 0;
// 	count = 0;
// 	if (s == NULL)
// 	{	
// 		result = write(1, "(null)", 6);
// 		if (result == -1)
// 			return (-1);
// 		return (result);
// 	}
// 	while (s[index])
// 	{
// 		result = write (1, &s[index], 1);
// 		if (result == -1)
// 			return (-1);
// 		count = count + result;
// 		index++;
// 	}
// 	return (count);
// }
// int	ft_putnbr_hexa(unsigned int n, char c)//
// {
// 	int		count;
// 	int		result;
// 	char	*base;
	
// 	count = 0;
// 	if (c == 'x')
// 		base = "0123456789abcdef";
// 	else if (c == 'X')
// 		base = "0123456789ABCDEF";
// 	if (n > 15)
// 	{
// 		result = ft_putnbr_hexa(n / 16, c);
// 		if (result == -1)
// 			return (-1);
// 		count = result;
// 	}
// 	result = ft_putchar(base[(n % 16)]);
// 	if (result == -1)
// 		return (-1);
// 	count = count + result;
// 	return (count);
// }
// int	ft_putptr(void *ptr)//
// {
// 	int				count;// ptr == null check
// 	int				result;
// 	unsigned long	addr;

// 	if (ptr == NULL)
// 	{	
// 		result = write(1, "(nil)", 5);
// 		// if (result == -1)
// 		// 	return (-1);
// 		return (result);
// 	}
// 	addr = (unsigned long)ptr;
// 	result = write(1, "0x", 2);
// 	// if (result == -1)
// 	// 	return (-1);
// 	count = ft_putnbr_hexa(addr, 'x');
// 	// if (count == -1)
// 	// 	return (-1);
// 	count = count + result;
// 	return (count);
// }
// int ft_putnbr_unsigned(unsigned int n)
// {
// 	int	count;
// 	int	result;

// 	count = 0;
// 	if (n > 9)
// 	{
// 		count = ft_putnbr_unsigned(n / 10);
// 		// if (count == -1)
// 		// 	return (-1);
// 	}
// 	result = ft_putchar((n % 10) + '0');
// 	// if (result == -1)
// 	// 	return (-1);
// 	count = count + result;
// 	return (count);
// }

// int	ft_conversion(va_list *args, char c)
// {
// 	if (c == 'c')
// 		return (ft_putchar(va_arg(*args, int)));
// 	else if(c == 's')
// 		return (ft_putstr(va_arg(*args, char *)));
// 	else if(c == 'p')
// 		return (ft_putptr(va_arg(*args, void *)));
// 	else if(c == 'd' || c == 'i')
// 		return (ft_putnbr(va_arg(*args, int)));
// 	else if(c == 'u')
// 		return (ft_putnbr_unsigned(va_arg(*args, unsigned int)));
// 	else if(c == 'x' || c == 'X')
// 		return (ft_putnbr_hexa(va_arg(*args, unsigned int) ,c));
// 	else if(c == '%')
// 		return (ft_putchar('%'));
// 	return (-1);
// }

// int ft_printf(const char *str, ...)
// {
// 	int	index;
// 	int	count;
// 	int	check;
// 	va_list	args;
	
// 	index = 0;
// 	count = 0;
// 	check = 0;
// 	if (str == NULL || write(1, "", 0) == -1)
// 		return (-1);
// 	va_start(args, str);
// 	while (str[index] != '\0')
// 	{
// 		if (str[index] == '%' && str[index+1] != '\0')
// 		{
// 			check = ft_conversion(args, str[++index]);
// 			if (check == -1)
// 				return (-1);
// 			count = count + check;
// 		}
// 		else if (str[index] == '%' && str[index+1] == '\0')
// 			return (-1);
// 		else
// 		{
// 			count = count + ft_putchar(str[index]);
// 		}
// 		index++;
// 	}
// 	va_end(args);
// 	return (count);
// }