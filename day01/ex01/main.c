/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sokaraku <sokaraku@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 19:43:57 by sokaraku          #+#    #+#             */
/*   Updated: 2025/03/07 12:54:54 by sokaraku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <avr/io.h>

/**
 * @brief set Clear Timer on Compare mode (CTC).
 * 
 * When this mode is set, a given timer count the clock cycles, and compares it to the
 * value in `OCR1A`. When this value is reached, the counter resets to 0,
 * because here only the WGM12 bit is set (Clear Timer on Compare Mode).
 * 
 * 
 */
void	setCTC( void ) { TCCR1B |= (1 << WGM12); }

/**
 * @brief Makes led D2 toggle when the counter in `TCCR1B` resets to 0.
 * 
 * `COM1A0` stands for compare outpute mode for channel A. This line allows to
 * automatically toggle the pin connected to `OC1A` (which is `PB1`) every time
 * the counter reaches the value in `OCR1A`. 
 * So when the condition for TCCR1B is fulfilled, the pin (in this case) is toggled. 
 */
void	makePinToggle( void ) { TCCR1A |= (1 << COM1A0); }


/**
 * @brief Sets the prescaler. A prescaler is a mechanism for dividing the timer's clock frequency.
 * The higher the clock frequency, the faster the timer counts.
 * 
 * It is set to 1024 here.
 */
void	setPreScaler( void ) { TCCR1B |= ((1 << CS12) | (1 << CS10));}

/**
 * @brief Sets the value to reach for the counter to toggle its pin.
 * @param value The value to reach, stored in OCR1A.
 */
void	setReachValue(unsigned int value) { OCR1A = value; }

int main(void)
{
	// Set PB1 as Output
	DDRB |= (1 << DDB1);

	setCTC();
	makePinToggle();
	setPreScaler();
	setReachValue(15625);

	while (1)
		; // Empty loop
}


/*
 * TCCR1A controls the output behavior of the timer by determining what happens to the output pins
 * in OC1A and OC1B when the timer's counter value matches the compare values (OCR1A and OCR1B)

 * TCCR1B controls the core operation of the timer, i.e. the mode in which the timer operates (normal, or CTC for example)
 * and also (among others) the clock source for the timer (prescaler).
 * 
 * WGM12 Waveform Generation Mode 12 is a bit within the TCCR1B register, used to determine how the timer counts,
 * when it resets and how it interacts with output pins.
 * 
 * Prescaler TCCR1B uses 3 bits.
 * 001 : 1
 * 010 : 8
 * 011 : 64
 * 100 : 256
 * 101 : 1024
 * 110 : rising edge (external clock signal transitions from low to high)
 * 111 : falling edge (same but high to low)
 * 
 * COM1A0 is a bit in the TCCR1A register. Determines what happens to the OC1A pin when the timer's counter
 * reaches the one in the OCR1A register.
 * 
 * Timer Clock Frequency = F_CPU / Prescaler
 * Desired Time = x
 * OCR1A = TCF * x
 * Note : OCR1A is a 16 bit register, so some operations are impossible (1-second toggle with a prescaler of 64
 * would imply that OCR1A should be 125 000).
 * Datasheet : 16.11.2 (Table 16.5)
*/