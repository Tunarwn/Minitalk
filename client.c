/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tturna <tturna@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/08 13:06:08 by tturna            #+#    #+#             */
/*   Updated: 2022/08/10 17:27:29 by tturna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int ft_atoi(char *s)
{
	int a;

	a = 0;
	while(*s)
	{
		a = a * 10 + (*s - 48);
		s++;
	}
	return(a);
}
void signalyollama(int pid, char *arg)
{
	int sayac;
	int i = 0;

	while(arg[i])
	{
		sayac = 8;
		while(sayac--)
		{
			if(((arg[i] >> sayac) & 1) == 1)
				kill(pid, SIGUSR1);
			else
				kill(pid, SIGUSR2);
			usleep(100);
		}
		i++;
	}
	i = 8;
	while (i--)
	{
		kill(pid, SIGUSR2);
		usleep(100);
	}
}

int	main(int	ac, char	**av)
{
	if(ac > 3)
		write(1 ,"hatalı arguman sayısı\n" ,23);
	else
	{
		signalyollama(ft_atoi(av[1]), av[2]);
	}
	return(0);
}

