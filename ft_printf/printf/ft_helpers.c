/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_helpers.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uuygun <uuygun@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/21 12:46:48 by uuygun            #+#    #+#             */
/*   Updated: 2023/07/21 19:01:59 by uuygun           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	ft_putchar(char c)
{
	write(1, &c, 1);
    return(1);
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
	while (s[i])
	{
		ft_putchar(s[i]);
		i++;
	}
	return (i - 1);
}