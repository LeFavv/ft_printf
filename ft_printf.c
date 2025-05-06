/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vafavard <vafavard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 14:02:42 by vafavard          #+#    #+#             */
/*   Updated: 2025/05/06 14:20:16 by vafavard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int print_d_and_i(int args);
int print_u(int args);
// int print_hex_top(long args);
// int print_hex_low(long args);
// int print_percent(char args)

void ft_putchar(char c)
{
	write (1, &c, 1);
}

int print_c(unsigned int args)
{
	int count;

	count = 1;
	ft_putchar(args);
	return (count);
}
int print_s(char *args)
{
	int count;

	count = 0;
	while (*args)
	{
		ft_putchar(*args);
		args++;
		count++;
	}
	return (count);
}
int print_d_and_i(int args)
{
	long	nb;
	int		count;


	nb = args;
	if (nb < 0)
	{
		ft_putchar('-');
		nb *= -1;
	}
	if (nb >= 10)
	{
		print_d_and_i(nb / 10);
		ft_putchar(nb % 10 + '0');
		count++;
	}
	else
	{
		ft_putchar(nb + '0');
		count++;
	}
	return (count);
}
int	display_specials(const char *str, va_list args)
{
	int	count;

	count = 0;
	if (*str == 'c')
		count += print_c(va_arg(args, unsigned int));
	else if (*str == 's')
		count += print_s(va_arg(args, char *));
	else if (*str == 'd')
		count += print_d_and_i(va_arg(args, int));
	else if (*str == 'i')
		count += print_d_and_i(va_arg(args, int));
	// else if (str == 'u')
	// 	count += print_u((str, unsigned int), letter_count);
	// else if (str == 'x')
	// 	count += print_hex_low((str, long), letter_count);
	// else if (str == 'X')
	// 	count += print_hex_top((str, long), letter_count);
	// else if (str == '%')
	// 	count += print_percent((str, char), letter_count);
	return (count);	
}

int ft_printf(const char *str, ...)
{
	int	letter_count;
	va_list	args;
	va_start(args, str);
	letter_count = 0;
	while (*str)
	{
		if (*str == (unsigned char)'%')
		{
			str++;
			letter_count += display_specials(str, args);
			str++;
		}
		else
		{ 
			write (1, str++, 1);
			letter_count++;
		}
	}
	va_end(args);
	return (letter_count);
}

#include <stdio.h>

int main(void)
{
	ft_printf("ssssalut salut %d\n%i\n%s\n", 42244, 42, "Kevin le boss");
	return (0);
}