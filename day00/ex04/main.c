/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sokaraku <sokaraku@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 14:37:56 by sokaraku          #+#    #+#             */
/*   Updated: 2025/03/05 14:05:41 by sokaraku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <avr/io.h>
#include <util/delay.h>
#include <stdint.h>
#include "macros.h"

/**
 * @brief Modifies a value of an 8 bits int or prints it.
 * @param action The type of action to do `INCREMENT`, `DECREMENT` or `PRINT`
 */
void	doAction(short action)
{
	static int8_t	value = 0;

	if (action == INCREMENT)
		value == __4_BITS_MAX_VALUE ? (void)0 : (value)++; //checks for "overflow" (if value is 15)
	else if (action ==  DECREMENT)
		value == 0 ? (void)0 : (value)--; // checks for "underflow" (if value is 0)
	else
	{
		//clear all leds in port B, to avoid leting them lit all the time
		PORTB &= ~B_MASK_DATA_REGISTER;
		// set the LED bits based on the value
		value & (1 << 0) ? PORTB |= LED_0 : (void)0; //if bit 0 in *val is 1, then PORTB's bit for LED_0 is set to HIGH
		value & (1 << 1) ? PORTB |= LED_1 : (void)0; //if bit 1 in *val is 1, then PORTB's bit for LED_1 is set to HIGH
		value & (1 << 2) ? PORTB |= LED_2 : (void)0; //if bit 2 in *val is 1, then PORTB's bit for LED_2 is set to HIGH
		value & (1 << 3) ? PORTB |= LED_3 : (void)0; //if bit 3 in *val is 1, then PORTB's bit for LED_3 is set to HIGH
	}
}

int main( void )
{
	DDRB |= B_MASK_DATA_REGISTER; // set all 4 first leds as output
	PORTB &= ~(B_MASK_PORT); // set 4 first leds LOW

	DDRD &= ~D_MASK_DATA_REGISTER; // set the switch SW1 and SW2 as input
	PORTD |= D_MASK_PORT; // enabling internal pull up resistor of SW1 and SW2

	while (true)
	{
        if ((PIND & SW1) == 0) //checks if SW1 is pressed
        {
            _delay_ms(BOUNCE_DELAY); //for bouncing effect
            if ((PIND & SW1) == 0) //if still pressed, does the increment and wait for the button to be unpressed
                doAction(INCREMENT);
            while ((PIND & SW1) == 0)
                ;
        }
        else if ((PIND & SW2) == 0) // same here
        {
            _delay_ms(BOUNCE_DELAY);
            if ((PIND & SW2) == 0)
                doAction(DECREMENT);
            while ((PIND & SW2) == 0)
                ;
        }
		else
			continue ; // this makes the printing happen only when an event occured (SW1 or SW2 was pressed)
		doAction(PRINT);
	}
}