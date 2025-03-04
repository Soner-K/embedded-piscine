/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   macros.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sokaraku <sokaraku@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 15:02:22 by sokaraku          #+#    #+#             */
/*   Updated: 2025/03/04 17:52:09 by sokaraku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MACROS_H
# define MACROS_H


/* UTILS */
# define BOUNCE_DELAY 10
# define __4_BITS_MAX_VALUE 15
# define INCREMENT 1
# define DECREMENT -1
# define PRINT 0
# define true 1
/* SWITCHES */
//* Allow for a clearer access to a given switch
# define SW1 (1 << PD2)
# define SW2 (1 << PD4)


/* LEDS */
//* Allow for a clearer access to a given led
# define LED_0 (1 << PB0)
# define LED_1 (1 << PB1)
# define LED_2 (1 << PB2)
# define LED_3 (1 << PB4)

//MASK
//* Mask with all leds' pin set to output
# define B_MASK_PORT (LED_0 | LED_1 | LED_2 | LED_3)
# define B_MASK_DATA_REGISTER ((1 << DDB0) | (1 << DDB1) | (1 << DDB2) | (1 << DDB4))
//* Mask with all switchs' pin internal pull up resistor set
# define D_MASK_PORT (SW1 | SW2)
# define D_MASK_DATA_REGISTER ((1 << DDD2) | (1 << DDD4))
#endif