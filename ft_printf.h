/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vafavard <vafavard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 10:28:27 by vafavard          #+#    #+#             */
/*   Updated: 2025/05/06 12:12:02 by vafavard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H

#define FT_PRINTF_H

#include "../libft/libft.h"
#include <stdarg.h>
#include <stdlib.h>
#include <unistd.h>

//display specials
int print_c(unsigned int args);
int print_s(char *args);
// int print_d_and_i(int args);
// int print_u(int args);
// int print_hex_top(long args);
// int print_hex_low(long args);
// int print_percent(char args);

int	display_specials(const char *str, va_list args);
void ft_putchar(char c);

int ft_printf(const char *str, ...);

#endif