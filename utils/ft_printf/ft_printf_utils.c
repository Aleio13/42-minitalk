/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almatsch <almatsch@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 23:08:13 by almatsch          #+#    #+#             */
/*   Updated: 2024/10/25 02:40:49 by almatsch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putchar_count(char c, int *count)
{
	int	i;

	i = 0;
	i = write (1, &c, 1);
	if (i < 0)
	{
		(*count) = -1;
		return ;
	}
	(*count)++;
}

void	ft_putnbr_count(int n, int *count)
{
	if ((*count) == -1)
		return ;
	if (n == -2147483648)
	{
		if (write(1, "-2147483648", 11) < 0)
			(*count) = -1;
		else
			(*count) += 11;
		return ;
	}
	if (n < 0)
	{
		ft_putchar_count ('-', count);
		n = -n;
	}
	if (n <= 9)
	{
		ft_putchar_count(n + '0', count);
	}
	else
	{
		ft_putnbr_count(n / 10, count);
		ft_putnbr_count(n % 10, count);
	}
}

void	ft_putstr_count(char *str, int *count)
{
	int	i;

	i = 0;
	if (str == NULL)
	{
		i = write(1, "(null)", 6);
		if (i < 0)
		{
			(*count) = i;
			return ;
		}
		(*count) += 6;
		return ;
	}
	while (str[i] != '\0')
	{
		ft_putchar_count(str[i], count);
		if ((*count) < 0)
			return ;
		i++;
	}
}

void	ft_putunbr_count(unsigned int n, int *count)
{
	if ((*count) == -1)
		return ;
	if (n <= 9)
	{
		ft_putchar_count(n + '0', count);
	}
	else
	{
		ft_putunbr_count(n / 10, count);
		ft_putunbr_count(n % 10, count);
	}
}

void	ft_puthex_count(size_t n, int *count, char *base)
{
	if ((*count) == -1)
		return ;
	if (n <= 15)
	{
		ft_putchar_count(base[n], count);
	}
	else
	{
		ft_puthex_count(n / 16, count, base);
		ft_puthex_count(n % 16, count, base);
	}
}
