/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkarim <mkarim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 16:02:27 by mkarim            #+#    #+#             */
/*   Updated: 2022/02/08 17:42:28 by mkarim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"
#include <stdio.h>

int		g_pid = 0;

void	reset(int *i, int *res)
{
	(*i) = 0;
	(*res) = 0;
}

void	handler(int sig, siginfo_t *info, void *p)
{
	static int		i;
	static int		res;

	(void)p;
	if (g_pid != info->si_pid)
	{
		reset(&i, &res);
		g_pid = info->si_pid;
	}
	res *= 2;
	if (sig == SIGUSR1)
		res += 1;
	else if (sig == SIGUSR2)
		res += 0;
	if (++i == 8)
	{
		if (res == 0)
			kill(info->si_pid, SIGUSR1);
		else
		{
			ft_putchar(res);
			reset(&i, &res);
		}
	}
}

int	main(int argc, char **argv)
{
	pid_t				pid;
	struct sigaction	s;

	s.__sigaction_u.__sa_sigaction = &handler;
	(void)argv;
	if (argc == 1)
	{
		pid = getpid();
		ft_putstr("The PID is : ");
		ft_putnbr(pid);
		ft_putchar('\n');
		sigaction(SIGUSR1, &s, NULL);
		sigaction(SIGUSR2, &s, NULL);
		while (1)
			pause();
	}
}
