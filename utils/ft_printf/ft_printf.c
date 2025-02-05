/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almatsch <almatsch@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 17:42:23 by almatsch          #+#    #+#             */
/*   Updated: 2024/11/14 16:32:54 by almatsch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	spec_cases(char c, va_list args, int *count)
{
	if (c == 'c')
		ft_putchar_count((char)va_arg(args, int), count);
	if (c == 'i' || c == 'd')
		ft_putnbr_count(va_arg(args, int), count);
	if (c == 's')
		ft_putstr_count(va_arg(args, char *), count);
	if (c == 'u')
		ft_putunbr_count(va_arg(args, unsigned int), count);
	if (c == '%')
		ft_putchar_count('%', count);
	if (c == 'x')
		ft_puthex_count(va_arg(args, unsigned int), count, "0123456789abcdef");
	if (c == 'X')
		ft_puthex_count(va_arg(args, unsigned int), count, "0123456789ABCDEF");
	if (c == 'p')
	{
		ft_putchar_count('0', count);
		if ((*count) == -1)
			return ;
		ft_putchar_count('x', count);
		if ((*count) == -1)
			return ;
		ft_puthex_count(va_arg(args, size_t), count, "0123456789abcdef");
	}
}

int	ft_printf(const char *format, ...)
{
	int		count;
	int		i;
	va_list	args;

	i = -1;
	count = 0;
	va_start(args, format);
	while (format[++i] != '\0')
	{
		if (format[i] == '%')
			spec_cases(format[++i], args, &count);
		else
			ft_putchar_count(format[i], &count);
		if (count < 0)
			break ;
	}
	va_end(args);
	if (count < 0)
		return (-1);
	return (count);
}
