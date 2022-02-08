/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkarim <mkarim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 14:59:50 by mkarim            #+#    #+#             */
/*   Updated: 2022/02/08 17:05:00 by mkarim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void    ft_send(int pid, char c)
{
    int     i = 7;
    while (i >= 0)
    {
        if ((c >> i) & 1)
            kill(pid, SIGUSR1);
        else
            kill(pid, SIGUSR2);
        i--;
        usleep(800);
    }
}

void    clientHandler(int s, siginfo_t *info, void *p)
{
    (void)p;
    (void)info;
    (void)s;
    ft_putstr("L'msg wsal\n");
    exit(1);
}

int main(int argc, char **argv)
{
    int     pid;
    int     i;
    struct sigaction s;

    s.__sigaction_u.__sa_sigaction= &clientHandler;
    sigaction(SIGUSR1, &s, NULL);
    i = 0;
    if (argc == 3)
    {
        pid = ft_atoi(argv[1]);
        while (argv[2][i])
        {
            ft_send(pid, argv[2][i]);
            i++;
        }
        ft_send(pid, '\0');
    }
    else
    {
        ft_putstr("Bghina 3 arguments assat\n");
    }
}