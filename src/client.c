/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aallou-v <aallou-v@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/29 22:53:36 by aallou-v          #+#    #+#             */
/*   Updated: 2023/10/30 04:25:39 by aallou-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	ft_atob(pid_t pid, char c)
{
	int	bit;

	bit = 0;
	while (bit < 8)
	{
		if (c & (1 << bit))
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		usleep(100);
		bit++;
	}
}

int	main(int argc, char **argv)
{
	int		i;
	pid_t	pid;

	if (argc != 3)
	{
		ft_putendl_fd("Input Error !", 1);
		return (1);
	}
	i = -1;
	while (argv[1][++i])
	{
		if (!ft_isdigit(argv[1][i]))
		{
			ft_putendl_fd("Error Invalid Signal", 1);
			return (1);
		}
	}
	pid = ft_atoi(argv[1]);
	i = -1;
	while (argv[2][++i])
		ft_atob(pid, argv[2][i]);
	ft_atob(pid, '\n');
	return (0);
}
