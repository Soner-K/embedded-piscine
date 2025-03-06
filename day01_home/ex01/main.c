/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sokaraku <sokaraku@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 19:43:57 by sokaraku          #+#    #+#             */
/*   Updated: 2025/03/06 20:44:00 by sokaraku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <avr/io.h>

/**
 * @brief set Clear Timer on Compare mode (CTC).
 * 
 * When this mode is set, a given timer count the clock cycles, and compares it to the
 * value in `OCR1A`. When this value is reached, the counter resets to 0.
 * 
 */
void	setCTC( void ) { TCCR1B |= (1 << WGM12); }

/**
 * @brief Makes led D2 toggle when the counter in `TCCR1B` resets to 0.
 * 
 * `COM1A0` stands for compare outpute mode for channel A. This line allows to
 * automatically toggle the pin connected to `OC1A` (which is `PB1`) every time
 * the counter reaches the value in `OCR1A`. 
 */
void	makePinToggle( void ) { TCCR1A |= (1 << COM1A0); }

void	setPreScaler( void ) { TCCR1B |= ((1 << CS12) | (1 << CS10));}

void	setHz(unsigned int hz) { OCR1A = hz; }

int main(void)
{
	// Set PB1 as Output
	DDRB |= (1 << DDB1);

	setCTC();
	makePinToggle();
	setPreScaler();
	setHz(7812);

	while (1)
		; // Empty loop
}


/*
CTC is Clear Timer on Compare.


*/