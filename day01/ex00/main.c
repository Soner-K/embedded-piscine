/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sokaraku <sokaraku@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 13:50:19 by sokaraku          #+#    #+#             */
/*   Updated: 2025/03/06 20:16:48 by sokaraku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <avr/io.h>

# define TIME 500


//Note : volatile keyword used here to avoid compiler optimization
void	myTimer(unsigned int ms)
{
	while (ms--)
	{
		for (volatile unsigned int i = 0; i < 800 ; i++); // 800 is just honestly trial and error
			__asm__(""); //assembler instruction for a no operation (takes 1 cycle)
	}
}


int main( void )
{
	DDRB |= (1 << DDB1);

	while (1)
	{
		PORTB ^= (1 << DDB1); //XOR op to avoid an if/else statement
		myTimer(1000);
	}
}
