/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almatsch <almatsch@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 10:52:37 by almatsch          #+#    #+#             */
/*   Updated: 2025/02/04 21:14:54 by almatsch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minitalk.h"

int	ft_atoi(const	char *str)
{
	int	i;
	int	count;
	int	nbr;

	i = 0;
	nbr = 0;
	count = 1;
	while (str[i] == ' ' || str[i] == '\t' || str[i] == '\v' || \
			str[i] == '\n' || str[i] == '\r' || str[i] == '\f')
	{
		i++;
	}
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			count = count * -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		nbr = nbr * 10;
		nbr += str[i] - '0';
		i++;
	}
	return (nbr * count);
}
