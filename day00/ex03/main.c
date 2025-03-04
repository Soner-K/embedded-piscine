/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sokaraku <sokaraku@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 13:39:46 by sokaraku          #+#    #+#             */
/*   Updated: 2025/03/04 15:04:13 by sokaraku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <avr/io.h>
#include <util/delay.h>

# define true 1
# define BOUNCE_DELAY 10


//main issue here is bounce and how to handle it
int main( void )
{
	DDRB |= (1 << DDB0);
	PORTB &= ~(1 << PB0);

	DDRD &= ~(1 << PD2);
	PORTD |= (1 << PD2);

	while (true)
	{
		if ((PIND & (1 << PD2)) == 0) // switch is turned on
		{
			_delay_ms(BOUNCE_DELAY); //we wait here for the bounce
			if ((PIND & (1 << PD2)) == 0) //if the switch is still pressed, then we invert PB0's state
				PORTB ^= (1 << PB0); //XOR is used at the bit PB0
			while ((PIND & (1 << PD2)) == 0) //as long as the button is pressed, we wait, to avoid multiple same read
				;
			//if the while loop wasn't there, a long switch will be interpreted as multiple ones
		}
	}
}