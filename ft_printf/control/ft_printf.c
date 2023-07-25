/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uuygun <uuygun@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/21 11:49:11 by uuygun            #+#    #+#             */
/*   Updated: 2023/07/25 13:32:56 by uuygun           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	arg_check(va_list ag, char index)
{
	size_t	len;

	len = 0;
	if (index == 'c')
		len = len + ft_putchar(va_arg(ag, unsigned int));
	else if (index == 'd' || index == 'i')
		len = len + ft_putnbr(va_arg(ag, int));
	else if (index == 's')
		len = len + ft_putstr(va_arg(ag, char *));
	else if (index == 'u')
		len = len + ft_putuint(va_arg(ag, unsigned int));
	else if (index == 'x' || index == 'X')
		len = len + ft_puthex(va_arg(ag, unsigned int), index);
	else if (index == 'p')
		len = len + ft_putpoint(va_arg(ag, unsigned long), 1);
	else
		return (ft_putchar('%'));
	return (len);
}

int	ft_printf(const char *format, ...)
{
	va_list	ag;
	int		i;
	int		retu;

	i = 0;
	retu = 0;
	va_start(ag, format);
	while (format[i])
	{
		if (format[i] != '%')
			retu = retu + ft_putchar(format[i]);
		if (format[i] == '%') 
		{
			retu = retu + arg_check(ag, format[i + 1]);
			i++;
		}
		i++;
	}
	va_end(ag);
	return (retu);
}

// int main() {
//     char s[] = "1128";
//     char b[] = "1128";
//     ft_printf("ft s :%p\n", s);
//     printf("s: %p\n", s);
//     ft_printf("   \n");
//     ft_printf("ft b: %p\n", b);
//     printf("b : %p\n", b);
// }