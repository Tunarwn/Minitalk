/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tturna <tturna@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/08 12:52:09 by tturna            #+#    #+#             */
/*   Updated: 2022/08/11 12:31:20 by tturna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void signalgeldi(int tuna)
{
	static int  x = 128;
	static char c;

	
	if(tuna == SIGUSR1)
		c += x;
	
	x /= 2;
	if(x == 0)
	{
		if(!c)
			write(1 ,"\n", 1);
		write(1, &c, 1);
		x = 128;
		c = 0;
	}
}

int	main(void)
{
	printf("PID: %d \n" ,getpid());
	signal(SIGUSR1, signalgeldi);
	signal(SIGUSR2, signalgeldi);
	while(1)
	{
		pause();
	}
	return(0);
}
