/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vafavard <vafavard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 14:02:42 by vafavard          #+#    #+#             */
/*   Updated: 2025/05/05 14:16:26 by vafavard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include <stdarg.h>

int	check_percent(const char *str)
{
	if (*str == '%')
		return (1);
	return (0);
}



int ft_printf(const char *str, ...)
{
	int	i;

	i = 0;
	while (*str && !check_percent(str))
	{
		write (1, str++, 1);
		i++;
	}
	if (check_percent(str))
		find_letter(str);
	return (i);
}

int main(void)
{
	ft_printf("Sal%ut");
	return (0);
}