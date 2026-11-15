#include <stdio.h>
#include <stdarg.h>


int sum(int count, ...)
{
    va_list args;
    int i;
    int total;
    int number;

    i = 0;
    total = 0;
    va_start(args, count);
    while (i < count)
    {
        number = va_arg(args, int);
        total = total + number;
        i++;
    }
    va_end(args);
    return (total);
}


int main()
{
	printf("%d\n", sum(3, 10, 20, 30));

	// int	a = printf("hhvg%d\n", NULL);
	// printf("%d", a);

	//printf("%d 7asfyasn %s", 34234234234, "asdasdsdasdasd");
}

