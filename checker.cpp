#include "checker.hpp"

float LOWER_LIMIT_TEMP = 0;
float HIGHER_LIMIT_TEMP = 45;
float LOWER_LIMIT_SOC = 20;
float HIGHER_LIMIT_SOC = 80;
float HIGHER_LIMIT_CHARGE_RATE = 0.8;

bool tempOfBatteryIsOk(float temperature) {
	if (temperature < LOWER_LIMIT_TEMP || temperature > HIGHER_LIMIT_TEMP) {
		cout << temperature << " Given Temperature out of range!\n";
		return false;
	}
	return true;
}
bool socOfbatteryIsOk(float soc) {
	if (soc < LOWER_LIMIT_SOC || soc > HIGHER_LIMIT_SOC) {
		cout << soc << " Given State of Charge out of range!\n";
		return false;
	}
	return true;
}
bool chargeRateofBatteryIsOk(float chargeRate) {
	if (chargeRate > HIGHER_LIMIT_CHARGE_RATE) {
		cout << chargeRate << " Given Charge Rate out of range!\n";
		return false;
	}
	return true;
}

bool batteryIsOk(float temperature, float soc, float chargeRate) {

	bool temperatureCondition = tempOfBatteryIsOk(temperature);
	bool socCondition = socOfbatteryIsOk(soc);
	bool chargeRateCondition = chargeRateofBatteryIsOk(chargeRate);
	bool batteryCondition = (temperatureCondition && socCondition && chargeRateCondition);
	return batteryCondition;
}