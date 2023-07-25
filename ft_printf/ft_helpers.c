/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_helpers.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uuygun <uuygun@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/21 12:46:48 by uuygun            #+#    #+#             */
/*   Updated: 2023/07/25 13:37:42 by uuygun           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(char c)
{
	write (1, &c, 1);
	return (1);
}

int	ft_putnbr(int a)
{
	int	ret;

	ret = 0;
	if (a == 0)
		return (write(1, "0", 1));
	if (a == -2147483648)
		return (write(1, "-2147483648", 11));
	if (a < 0)
	{
		ret += write(1, "-", 1);
		a *= -1;
	}
	if (a >= 10)
		ret += ft_putnbr(a / 10);
	write(1, &"0123456789"[a % 10], 1);
	return (ret + 1);
}

int	ft_putstr(char *s)
{
	int	i;

	i = 0;
	if (!s)
		return (ft_putstr("(null)"));
	while (s[i])
	{
		write(1, &s[i++], 1);
	}
	return (i);
}

int	ft_putuint(unsigned int n)
{
	int	len;

	len = 0;
	if (n >= 10)
		len = len + ft_putuint(n / 10);
	write(1, &"0123456789"[n % 10], 1);
	return (len + 1);
}
