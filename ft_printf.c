/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vafavard <vafavard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 14:02:42 by vafavard          #+#    #+#             */
/*   Updated: 2025/05/07 20:41:14 by vafavard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putchar(char c)
{
	write (1, &c, 1);
}

int	print_p(uintptr_t addr)
{
	int		count;

	count = 0;
	if (addr >= 16)
		count += print_p(addr / 16);
	write(1, &"0123456789abcdef"[addr % 16], 1);
	count++;
	return (count);
}

int	ft_percent(void)
{
	ft_putchar('%');
	return (1);
}

int	display_specials(const char *str, va_list *args)
{
	int	count;

	count = 0;
	if (*str == 'c')
		count = print_c(va_arg(*args, unsigned int));
	else if (*str == 's')
		count = print_s(va_arg(*args, char *));
	else if (*str == 'd' || *str == 'i')
		count = print_d_and_i(va_arg(*args, int));
	else if (*str == 'u')
		count = print_u(va_arg(*args, unsigned int));
	else if (*str == 'x')
		count = print_hex_low(va_arg(*args, int));
	else if (*str == 'X')
		count = print_hex_top(va_arg(*args, int));
	else if (*str == 'p')
	{
		write (1, "0x", 2);
		count += 2;
		count += print_p(va_arg(*args, uintptr_t));
	}
	else if (*str == '%')
		count += ft_percent();
	return (count);
}

int	ft_printf(const char *str, ...)
{
	int		letter_count;
	va_list	args;
	int		ret;

	va_start(args, str);
	letter_count = 0;
	while (*str)
	{
		if (*str == '%' && *(str + 1))
		{
			str++;
			ret = display_specials(str, &args);
			str++;
			if (ret == -1)
				return (-1);
			letter_count += ret;
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
