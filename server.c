/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkarim <mkarim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 16:02:27 by mkarim            #+#    #+#             */
/*   Updated: 2022/02/07 15:14:47 by mkarim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"
#include <stdio.h>

void    handler(int sig, siginfo_t *info, void *p)
{
    static int     i;
    static int     res;

    
    if (sig == SIGUSR1)
    {
        res = res * 2;
        res += 1;
        i++;
    }
    else if (sig == SIGUSR2)
    {
         res = res * 2;       
        res += 0;
        i++;
    }
    if (i == 8)
    {
        ft_putchar(res);
        i = 0;
        res = 0;
    }
}

int main(int argc, char **argv)
{
    pid_t   pid;
    struct sigaction s;
    s.__sigaction_u.__sa_sigaction = &handler;

    if (argc == 1)
    {
        pid = getpid();
        ft_putstr("The PID is : ");
        ft_putnbr(pid);
        ft_putchar('\n');
        sigaction(SIGUSR1, &s, NULL);
        sigaction(SIGUSR2, &s, NULL);
        while (1)
            sleep(1);
    }
}