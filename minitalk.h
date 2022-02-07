/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkarim <mkarim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 15:03:08 by mkarim            #+#    #+#             */
/*   Updated: 2022/01/17 17:29:57 by mkarim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
#define MINITALK_H

# include <signal.h>
# include <unistd.h>

void    ft_putstr(char *s);
void    ft_putchar(char c);
void    ft_putnbr(int n);
int	ft_atoi(const char *s);

#endif