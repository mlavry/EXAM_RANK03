#include <unistd.h>
#include <stdarg.h>
#include <stdlib.h>
#include <limits.h>

int	ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_putstr(char *str)
{
	if (!str)
	{
		ft_putstr("(null)");
		return (6);
	}
	int i = 0;
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
	return (i);
}

void	ft_putnbr(int nbr, int *len)
{
	if (nbr == INT_MIN)
	{
		*len += write (1, "-2147483648", 11);
		return ;
	}
	if (nbr < 0)
	{
		*len += write (1, "-", 1);
		nbr = -nbr;
	}
	if (nbr >= 10)
		ft_putnbr(nbr / 10, len);
	*len += ft_putchar(nbr % 10 + '0');
}

void	ft_putnbr_hex(unsigned int nbr, int *len)
{
	char *str = "0123456789abcdef";

	if (nbr >= 16)
		ft_putnbr_hex(nbr / 16, len);
	*len += ft_putchar(str[nbr % 16]);
}

int	ft_format(va_list args, char c)
{
	int printlen = 0;

	if (c == 's')
		printlen += ft_putstr(va_arg(args, char *));
	if (c == 'd')
		ft_putnbr(va_arg(args, int), &printlen);
	if (c == 'x')
		ft_putnbr_hex(va_arg(args, unsigned int), &printlen);
	return (printlen);
}

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int i;
	int printlen;

	va_start(args, str);
	i = 0;
	printlen = 0;
	while (str[i])
	{
		if (str[i] == '%')
		{
			printlen += ft_format(args, str[i + 1]);
			i++;
		}
		else
			printlen += ft_putchar(str[i]);
		i++;
	}
	va_end(args);
	return(printlen);
}

/* int main(void)
{
	int len;
	len = ft_printf("%s\n", "toto");
	ft_printf("%d\n", len);
	len = ft_printf("Magic %s is %d\n", "number", 42);
	ft_printf("%d\n", len);
	len = ft_printf("Hexadecimal for %d is %x\n", 42, 42);
	ft_printf("%d\n", len);
} */
