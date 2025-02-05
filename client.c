/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almatsch <almatsch@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 14:59:51 by almatsch          #+#    #+#             */
/*   Updated: 2025/02/04 21:56:54 by almatsch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	send_signals(pid_t server_id, char *str)
{
	int	bit;
	int	i;

	i = 0;
	while (str[i])
	{
		bit = 0;
		while (bit < 8)
		{
			if ((str[i] >> bit) & 1)
				kill(server_id, SIGUSR2);
			else
				kill(server_id, SIGUSR1);
			usleep(100);
			bit++;
		}
		i++;
	}
	bit = 0;
	while (bit < 8)
	{
		kill(server_id, SIGUSR1);
		usleep(100);
		bit++;
	}
}

int main(int argc, char **argv)
{
	pid_t	server_id;
	char	*str;

	if (argc != 3)
		exit(1);
	server_id = (pid_t)ft_atoi(argv[1]);
	str = argv[2];
	send_signals(server_id, str);
	return (0);
}
