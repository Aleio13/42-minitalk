/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almatsch <almatsch@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 14:59:49 by almatsch          #+#    #+#             */
/*   Updated: 2025/02/04 21:08:08 by almatsch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

unsigned int	g_bit;

void	translator(int signum)
{
	static unsigned char	s_byte;
	static unsigned int		b_count;

	if (signum == SIGUSR1)
		g_bit = 1;
	else if (signum == SIGUSR2)
		g_bit = 0;
	byte = (byte >> 1) | bit;
	b_count++;
	if (b_count == 8)
	{
		ft_printf("%c", char);
		b_count = 0;
		s_byte = 0;
	}
}

int main(void)
{
	pid_t	process_id;

	process_id = getpid();
	ft_printf("%d\n", process_id);
	signal(SIGUSR1, translator);
	signal(SIGUSR2, translator);
	while (1)
		pause();
	return (0);
}
