/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkarim <mkarim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 16:02:27 by mkarim            #+#    #+#             */
/*   Updated: 2022/02/07 11:16:32 by mkarim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"
#include <stdio.h>

void    handler(int s)
{
    int     i;
    int     nb;

    i = 0;
    nb = 0;
    while (i++ < 8)
    {
        if (SIGUSR1)
            nb += 0;
        else
            nb += 1;
        nb *= 10;
    }
    ft_putchar(nb);
    //printf("Hello");
}

int main(int argc, char **argv)
{
    pid_t   pid;
    struct sigaction s;
    s.sa_handler = &handler;

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