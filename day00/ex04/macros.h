/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   macros.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sokaraku <sokaraku@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 15:02:22 by sokaraku          #+#    #+#             */
/*   Updated: 2025/03/04 18:04:45 by sokaraku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MACROS_H
# define MACROS_H

/* UTILS */
# define BOUNCE_DELAY 10           /* Debounce delay for switches in milliseconds */
# define __4_BITS_MAX_VALUE 15     /* Maximum value for 4-bit representation (0b1111) */
# define INCREMENT 1               /* Value representing the increment action */
# define DECREMENT -1              /* Value representing the decrement action */
# define PRINT 0                   /* Value representing the print action */
# define true 1                    /* Define 'true' as 1 for boolean logic */

/* SWITCHES */
//* Allow for a clearer access to a given switch
# define SW1 (1 << PD2)            /* Define SW1 as bit 2 of Port D */
# define SW2 (1 << PD4)            /* Define SW2 as bit 4 of Port D */

/* LEDS */
//* Allow for a clearer access to a given led
# define LED_0 (1 << PB0)            /* Define LED_0 as bit 0 of Port B */
# define LED_1 (1 << PB1)            /* Define LED_1 as bit 1 of Port B */
# define LED_2 (1 << PB2)            /* Define LED_2 as bit 2 of Port B */
# define LED_3 (1 << PB4)            /* Define LED_3 as bit 4 of Port B */

//MASK
//* Mask with all leds' pin set to output
# define B_MASK_PORT (LED_0 | LED_1 | LED_2 | LED_3)  /* Mask for all LED pins on Port B */
# define B_MASK_DATA_REGISTER ((1 << DDB0) | (1 << DDB1) | (1 << DDB2) | (1 << DDB4)) /* Mask for setting LED pins as output in DDRB */
//* Mask with all switchs' pin internal pull up resistor set
# define D_MASK_PORT (SW1 | SW2)           /* Mask for all switch pins on Port D (for enabling pull-up resistors) */
# define D_MASK_DATA_REGISTER ((1 << DDD2) | (1 << DDD4)) /* Mask for setting switch pins as input in DDRD */

#endif