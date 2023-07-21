/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uuygun <uuygun@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/21 11:49:11 by uuygun            #+#    #+#             */
/*   Updated: 2023/07/21 19:04:59 by uuygun           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static int arg_check(va_list ag, char index)
{
    size_t len;
    len = 0;
    if (index == 'c')
        len = len + ft_putchar(va_arg(ag, unsigned int));
    else if (index == 'd' || index == 'i')
        len = len + ft_putnbr(va_arg(ag, int));
    else if (index == 's')
        len = len + ft_putstr(va_arg(ag,char *));
    // else if (index == 'p')
    //     len = len + ft_hexa(va_arg(*ag, unsigned long));
    return len;
}
int ft_printf(const char *format, ...) 
{
    va_list         ag;
    int             i;
    unsigned int    retu;
    
    i = 0;
    retu = 0;
    va_start(ag, format);
    while (format[i])
    {
        if (format[i] == '%')
        {
            retu = retu + arg_check(ag, format[i + 1]);
            i++;
        }
        else
            write(1,&format[i],1);
            retu++;
        i++;
    }
    retu--;
    return (retu);
}

int main() {
    char s[] = "hello";
    ft_printf("\n%d",ft_printf("%s  123",s)); //çalışıo
}