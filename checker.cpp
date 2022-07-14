#include "checker.hpp"

float LOWER_LIMIT_TEMP = 0;
float HIGHER_LIMIT_TEMP = 45;
float LOWER_LIMIT_SOC = 20;
float HIGHER_LIMIT_SOC = 80;
float HIGHER_LIMIT_CHARGE_RATE = 0.8;
int percentageOfTolerance = 5;
bool tempOfBatteryIsOk(float temperature) {
	if(isRangeOk(temperature, LOWER_LIMIT_TEMP, HIGHER_LIMIT_TEMP)){
		earlyWarning(temperature, LOWER_LIMIT_TEMP, HIGHER_LIMIT_TEMP);
	    return true;
	}
	cout << "Temperature is " << temperature<<"\n";
	printMessage();
	return false;
}
bool socOfbatteryIsOk(float soc) {
	if (isRangeOk(soc,LOWER_LIMIT_SOC,HIGHER_LIMIT_SOC)) {
		earlyWarning(soc,LOWER_LIMIT_SOC, HIGHER_LIMIT_SOC);
        return true;
	}
	cout << "State of Charge is " << soc<<"\n";
	printMessage();
	return false;
}
bool chargeRateofBatteryIsOk(float chargeRate) {
	if (chargeRate > HIGHER_LIMIT_CHARGE_RATE) {
		cout << "Charge Rate is "<< chargeRate << "\n";
		printMessage();
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
void earlyWarning(float value, float LOWER_LIMIT, float HIGH_LIMIT) {
	float tolValue = HIGH_LIMIT * percentageOfTolerance / 100;
	if ((LOWER_LIMIT <= value) && (value <= (LOWER_LIMIT + tolValue))) {
		cout << "Reaching Lower Limit " << value << "\n";
		printTolMessage();
	}
	if (((HIGH_LIMIT - tolValue) <= value) && (value <= HIGH_LIMIT)) {
		cout << "Reaching Higher Limit " << value << "\n";
		printTolMessage();
	}
}

bool isRangeOk(float value, float LOWER_LIMIT, float HIGH_LIMIT) {
	if (value < LOWER_LIMIT || value > HIGH_LIMIT) {
		return false;
	}
	return true;
}
void printMessage() {
	cout << " Out of Range!!\n";
	cout << " Außer Reichweite!!\n";
}
void printTolMessage() {
	cout << "Early warning!: Reaching  5% of Tolerance \n";
	cout << "Frühwarnung!: Toleranz erreichen \n";
}
