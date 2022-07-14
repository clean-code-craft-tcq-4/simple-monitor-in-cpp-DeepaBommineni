#include "checker.hpp"

float LOWER_LIMIT_TEMP = 0;
float HIGHER_LIMIT_TEMP = 45;
float LOWER_LIMIT_SOC = 20;
float HIGHER_LIMIT_SOC = 80;
float HIGHER_LIMIT_CHARGE_RATE = 0.8;
int percentageOfTolerance = 5;

bool tempOfBatteryIsOk(float temperature) {
	if (isRangeOk(temperature, LOWER_LIMIT_TEMP, HIGHER_LIMIT_TEMP)) {
		earlyWarning(temperature, LOWER_LIMIT_TEMP, HIGHER_LIMIT_TEMP);
		return true;
	}
	cout << "Temperature(Temperatur): " << temperature << "\n";
	printMessage();
	return false;
}
bool socOfbatteryIsOk(float soc) {
	if (isRangeOk(soc, LOWER_LIMIT_SOC, HIGHER_LIMIT_SOC)) {
		earlyWarning(soc, LOWER_LIMIT_SOC, HIGHER_LIMIT_SOC);
		return true;
	}
	cout << "State of Charge(Ladezustand): " << soc << "\n";
	printMessage();
	return false;
}
bool chargeRateofBatteryIsOk(float chargeRate) {
	if (chargeRate > HIGHER_LIMIT_CHARGE_RATE) {
		cout << "Charge Rate(Ladestrom): " << chargeRate << "\n";
		printMessage();
		return false;
	}
	return true;
}
bool batteryIsOk(float temperature, float soc, float chargeRate) {
	bool temperatureCondition = tempOfBatteryIsOk(temperature);
	bool socCondition = socOfbatteryIsOk(soc);
	bool chargeRateCondition = chargeRateofBatteryIsOk(chargeRate);
	bool batteryCondition = combinedCheck(temperatureCondition, socCondition, chargeRateCondition);
	return batteryCondition;
}
void earlyWarning(float value, float LOWER_LIMIT, float HIGH_LIMIT) {
	float toleranceVal = HIGH_LIMIT * percentageOfTolerance / 100;
	warnLowerLimit(value, LOWER_LIMIT, HIGH_LIMIT, toleranceVal);
	warnHigherLimit(value, LOWER_LIMIT, HIGH_LIMIT, toleranceVal);

}
void warnLowerLimit(float value, float LOWER_LIMIT, float HIGH_LIMIT,float tolVal) {
	if ((LOWER_LIMIT <= value) && (value <= (LOWER_LIMIT + tolVal))) {
		cout << "Reaching Lower Limit " << value << "\n";
		printTolMessage();
	}
}
void warnHigherLimit(float value, float LOWER_LIMIT, float HIGH_LIMIT,float tolVal) {
	if (((HIGH_LIMIT - tolVal) <= value) && (value <= HIGH_LIMIT)) {
		cout << "Reaching Higher Limit " << value << "\n";
		printTolMessage();
	}
}