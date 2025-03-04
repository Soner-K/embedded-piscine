/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sokaraku <sokaraku@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 12:04:21 by sokaraku          #+#    #+#             */
/*   Updated: 2025/03/04 14:49:29 by sokaraku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <avr/io.h>

/*
//* In an AVR register, registers are 8bit memory locations, that control the hardware. Each bit controls one pin of a specific port
//* Each pin can be an input (reads a signal) or an output (sends a signal)
//* To control a pin, the microcontroller provides special registers


This main sets up a microcontroller pin to light a given led (D1) using its register (PB0, port B)
Here, the Data Direction Register B sets its first bit to 1, making it an output pin.
PORTB then sets its first bit to 1, setting its volatage to high.
*/ 
int main( void )
{
	DDRB |= (1 << DDB0); //* sets DDB0 pin to 1
	PORTB |= (1 << PB0); //*sets PB0 pin to 1
}
