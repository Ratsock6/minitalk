/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aallou-v <aallou-v@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/29 22:50:49 by aallou-v          #+#    #+#             */
/*   Updated: 2023/10/30 20:02:30 by aallou-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

char	*ft_strjoin2(char const *s1, int i)
{
	char	*r;
	char	c[1];

	if (!s1 || i)
		return (NULL);
	c[0] = i;
	r = (char *) ft_calloc(ft_strlen(s1) + 2, sizeof(char));
	if (!r)
		return (NULL);
	ft_strlcpy(r, s1, ft_strlen(s1) + 1);
	ft_strlcat(r, c, ft_strlen(s1) + 2);
	ft_putstr_fd(r, 1);
	return (r);
}

void	ft_btoa(int sig)
{
	static int	bit = 0;
	static int	i = 0;
	static char	*str = "";

	if (sig == SIGUSR1)
		i |= (0x01 << bit);
	bit++;
	if (bit == 8)
	{
		str = ft_strjoin2(str, i);
		//ft_putchar_fd(i, 1);
		if (i == 10)
		{
			ft_putendl_fd(str, 0);
			str = "";
		}
		bit = 0;
		i = 0;
	}
}

int	main(int argc, char **argv)
{
	ft_printf("\033[92m");
	ft_printf("███╗   ███╗██╗███╗   ██╗██╗████████╗ █████╗ ██╗     ██╗  ██╗\n");
	ft_printf("████╗ ████║██║████╗  ██║██║╚══██╔══╝██╔══██╗██║     ██║ ██╔╝\n");
	ft_printf("██╔████╔██║██║██╔██╗ ██║██║   ██║   ███████║██║     █████╔╝\n");
	ft_printf("██║╚██╔╝██║██║██║╚██╗██║██║   ██║   ██╔══██║██║     ██╔═██╗\n");
	ft_printf("██║ ╚═╝ ██║██║██║ ╚████║██║   ██║   ██║  ██║███████╗██║  ██╗\n");
	ft_printf("╚═╝     ╚═╝╚═╝╚═╝  ╚═══╝╚═╝   ╚═╝   ╚═╝  ╚═╝╚══════╝╚═╝  ╚═╝\n");
	ft_printf("\033[93m       PID : %d       /      By aallou-v\n", getpid());
	ft_printf("\033[92m____________________________________________________\n");
	(void)argv;
	if (argc != 1)
	{
		ft_printf("Error\n");
		return (1);
	}
	while (argc == 1)
	{
		signal(SIGUSR1, ft_btoa);
		signal(SIGUSR2, ft_btoa);
		pause ();
	}
	return (0);
}
