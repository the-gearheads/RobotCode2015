#include "ArmHelpers.h"

float HeightToPot(float height) {
	return AngleToPot(HeightToAngle(height));
}

float HeightToAngle(float height) {
	auto pref = Preferences::GetInstance();
	return acos((pref->GetFloat("arm.height") - height) / pref->GetFloat("arm.length"));
}

int AngleToPot(float angle) {
	auto pref = Preferences::GetInstance();
	float minAngle = pref->GetFloat("arm.angle.min");
	float maxAngle = pref->GetFloat("arm.angle.max");
	int minPot = pref->GetFloat("arm.pot.min");
	int maxPot = pref->GetFloat("arm.pot.min");
	return interpolate(angle, minAngle, maxAngle, minPot, maxPot);
}

float AngleToHeight(float angle) {
	auto pref = Preferences::GetInstance();
	return pref->GetFloat("arm.height") - cos(angle) * pref->GetFloat("arm.length");
}

float PotToAngle(int pot) {
	auto pref = Preferences::GetInstance();
	float minAngle = pref->GetFloat("arm.angle.min");
	float maxAngle = pref->GetFloat("arm.angle.max");
	int minPot = pref->GetFloat("arm.pot.min");
	int maxPot = pref->GetFloat("arm.pot.min");
	return interpolate(pot, minPot, maxPot, minAngle, maxAngle);
}

float PotToHeight(int pot) {
	return AngleToPot(PotToAngle(pot));
}
