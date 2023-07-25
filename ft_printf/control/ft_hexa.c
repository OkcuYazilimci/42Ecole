/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uuygun <uuygun@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 13:19:58 by uuygun            #+#    #+#             */
/*   Updated: 2023/07/25 13:33:14 by uuygun           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_puthex(unsigned int n, char c)
{
	int	len;

	len = 0;
	if (n >= 16)
		len += ft_puthex(n / 16, c);
	if (c == 'X')
		len += ft_putchar("0123456789ABCDEF"[n % 16]);
	if (c == 'x')
		len += ft_putchar("0123456789abcdef"[n % 16]);
	return (len);
}

int	ft_putpoint(unsigned long n, int p)
{
	int	len;

	len = 0;
	if (p == 1)
	{
		len = len + write(1, "0x", 2);
		if (n == 0)
		{
			len += write(1, "0", 1);
			return (len);
		}
		p = 0;
	}
	if (n >= 16)
		len = len + ft_putpoint(n / 16, 0);
	len += ft_putchar("0123456789abcdef"[n % 16]);
	return (len);
}
