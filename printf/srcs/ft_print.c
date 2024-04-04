/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tigpetro <tigpetro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 16:11:07 by tigpetro          #+#    #+#             */
/*   Updated: 2024/02/27 18:17:34 by tigpetro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

int	ft_print(va_list args, const char *prm)
{
	if (*prm == 'i' || *prm == 'd')
		return (ft_signed_putnbr(va_arg(args, int)));
	else if (*prm == 'u')
		return (ft_putnbr_base(va_arg(args, int), "0123456789", 10));
	else if (*prm == 's')
		return (ft_putstr(va_arg(args, char *)));
	else if (*prm == 'c')
		return (ft_putchar(va_arg(args, int)));
	else if (*prm == '%')
		return (ft_putchar('%'));
	else if (*prm == 'X')
		return (ft_putnbr_base(va_arg(args, int), "0123456789ABCDEF", 16));
	else if (*prm == 'x')
		return (ft_putnbr_base(va_arg(args, int), "0123456789abcdef", 16));
	else if (*prm == 'p')
		return (ft_putstr("0x") + ft_putnbr_base_ptr(va_arg(args, long long),
				"0123456789abcdef", 16));
	return (0);
}
