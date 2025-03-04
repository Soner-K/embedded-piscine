/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sokaraku <sokaraku@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 14:49:22 by sokaraku          #+#    #+#             */
/*   Updated: 2025/03/04 13:37:59 by sokaraku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <avr/io.h>
#include <util/delay.h>

# define true 1
# define BOUNCE_DELAY 10

int main(void)
{
	DDRB |= (1 << DD0); // setting D1 pin as an output
	PORTB &= ~(1 << PB0); // making voltage LOW so that it starts turned off (by clearing the bit)

	DDRD &= ~(1 << DD2); // setting DD2 as an input switch
	PORTD |= (1 << PD2); // enabling the internal pull up resistor of PD2

	while (true)
	{
		if (PIND & (1 << PD2)) // if PD2 is high, current flows, so switch1 isnt pressed : D1 is turned off
			PORTB &= ~(1 << PB0);
		else // else, current doesn't flow, so it is pressed : D1 is turned on
			PORTB |= (1 << PB0);
		_delay_ms(BOUNCE_DELAY); // allows the mechanical contact to stabilize before the code reacts to the input
	}
}

/*
Note for me
When a mechanical switch is pressed or released, the connection isn't clean and instantaneous, it "bounces",
making and breaking contact rapidly
Therefore, the mcu can read multiple inputs for a given mechanical action and act accordingly.
When placing the delay AFTER the PIN state is read, the program forces the mcu to wait for the
contact to stabilize before reading an input.
*/