/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkarim <mkarim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 14:59:50 by mkarim            #+#    #+#             */
/*   Updated: 2022/02/07 11:13:58 by mkarim           ###   ########.fr       */
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
        usleep(500);
    }
}

int main(int argc, char **argv)
{
    int     pid;
    int     i;

    i = 0;
    if (argc == 3)
    {
        pid = ft_atoi(argv[1]);
        while (argv[1][i])
        {
            ft_send(pid, argv[2][i]);
            i++;
        }
    }
    else
    {
        ft_putstr("Bghina 3 arguments assat\n");
    }
}