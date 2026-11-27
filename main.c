#include <stdio.h>
#include <stdarg.h>


int	ft_printf(const char *str, ...)
{
	int		index;
	int		count;
	va_list	args;

	index = 0;
	count = 0;
	if (str == NULL || write(1, "", 0) == -1)
		return (-1);
	va_start(args, str);
	while (str[index] != '\0')
	{
		if (str[index] == '%' && str[index + 1] != '\0')
		{
			count = ft_conversion(&args, str[++index]);
			if (count == -1)
				return (va_end(args), -1);
			count = count + ft_conversion(&args, str[++index]);
		}
		else if (str[index] == '%' && str[index + 1] == '\0')
			return (va_end(args), -1);
		else
			count = count + ft_putchar(str[index]);
		index++;
	}
	return (va_end(args), count);
}

// int sum(int count, ...)
// {
//     va_list args;
//     int i;
//     int total;
//     int number;

//     i = 0;
//     total = 0;
//     va_start(args, count);
//     while (i < count)
//     {
//         number = va_arg(args, int);
//         total = total + number;
//         i++;
//     }
//     va_end(args);
//     return (total);
// }


// int main()
// {
// 	printf("%d\n", sum(3, 10, 20, 30));

// 	// int	a = printf("hhvg%d\n", NULL);
// 	// printf("%d", a);

// 	//printf("%d 7asfyasn %s", 34234234234, "asdasdsdasdasd");
// }

// int main()
// {
// 	printf("a");
// 	write(1, "b", 1);
// 	printf("c");
// 	write(1, "d", 1);
// 	printf("e");
// }
