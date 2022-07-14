#include <assert.h>
#include <iostream>
#include "checker.hpp"
#include <string>
using namespace std;

int main() {
	assert(tempOfBatteryIsOk(24) == true);
	assert(tempOfBatteryIsOk(50) == false);
	assert(tempOfBatteryIsOk(2) == true);
	assert(socOfbatteryIsOk(70) == true);
	assert(socOfbatteryIsOk(85) == false);
	assert(socOfbatteryIsOk(76) == true);
	assert(chargeRateofBatteryIsOk(0.7) == true);
	assert(chargeRateofBatteryIsOk(0) == true);
	assert(chargeRateofBatteryIsOk(0.9) == false);
	assert(batteryIsOk(25, 70, 0.7) == true);
	assert(batteryIsOk(50, 85, 0) == false);
	return 0;
}
