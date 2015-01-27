/*
 * LED.cpp
 *
 *  Created on: Jan 24, 2015
 *      Author: Gabs
 */

#include "LED.h"


LED::LED(uint32_t channel) : PWM(channel) {
}

void LED::Set(float value) {

	// The smallest amount of time the PWM signal can be high is
	// 0.5ms, which is a big deal when the period is only 5ms.
	// To compensate for this, we dynamically change the period
	// multiplier as value gets smaller. Unfortunately, this adds
	// noticeable flicker, but is bearable unless you're really
	// looking at it.
	if (value < 0.25) {
		SetPeriodMultiplier(PWM::kPeriodMultiplier_4X);
		value *= 4;
	} else if (value < 0.5) {
		SetPeriodMultiplier(PWM::kPeriodMultiplier_2X);
		value *= 2;
	} else {
		SetPeriodMultiplier(PWM::kPeriodMultiplier_1X);
	}

	// 2000 is the maximum raw PWM value possible
	SetRaw((int)(value * 2000));
}
