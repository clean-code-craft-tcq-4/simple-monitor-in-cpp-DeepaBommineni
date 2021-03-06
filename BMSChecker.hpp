#include <assert.h>
#include <iostream>
using namespace std;

extern float LOWER_LIMIT_TEMP;
extern float HIGHER_LIMIT_TEMP;
extern float LOWER_LIMIT_SOC;
extern float HIGHER_LIMIT_SOC;
extern float HIGHER_LIMIT_CHARGE_RATE;

bool tempOfBatteryIsOk(float temperature);
bool socOfbatteryIsOk(float soc);
bool chargeRateofBatteryIsOk(float chargeRate);
bool batteryIsOk(float temperature, float soc, float chargeRate);
void earlyWarning(float value, float LOWER_LIMIT, float HIGH_LIMIT);
bool isRangeOk(float value, float LOWER_LIMIT, float HIGH_LIMIT);
void printMessage();
void printTolMessage();
bool combinedCheck(bool tempCond, bool socCond, bool chargeRateCond);
void warnLowerLimit(float value, float LOWER_LIMIT, float HIGH_LIMIT, float tolVal);
void warnHigherLimit(float value, float LOWER_LIMIT, float HIGH_LIMIT, float tolVal);
