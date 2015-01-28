/*
 * LEDs.h
 *
 *  Created on: Jan 24, 2015
 *      Author: Gabs
 */

#ifndef SRC_LEDS_H_
#define SRC_LEDS_H_
#include "LED.h"

class LEDs {
	LED red;
	LED green;
	LED blue;

	int lastHue = 0; // Keeps track of the last hue value used in the rainbow function
	bool hueIncreasing = true;

public:
	LEDs(uint32_t redChannel, uint32_t greenChannel, uint32_t blueChannel);

	void Set(float r, float g, float b);
	void HSV(float h, float s, float v);

	void rainbow();

	// PWM based objects (such as the LED objects above) cannot be copied. Only one object
	// can be associated with a PWM channel. This prevents copying.
	DISALLOW_COPY_AND_ASSIGN(LEDs);

};


#endif /* SRC_LEDS_H_ */
