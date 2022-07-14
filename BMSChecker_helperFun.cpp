#include "checker.hpp"

bool isRangeOk(float value, float LOWER_LIMIT, float HIGH_LIMIT) {
	if (value < LOWER_LIMIT || value > HIGH_LIMIT) {
		return false;
	}
	return true;
}
void printMessage() {
	cout << " Out of Range!\n";
	cout << " Au�er Reichweite!\n";
}
void printTolMessage() {
	cout << "Early warning!: Reached  5% of Tolerance \n";
	cout << "Fr�hwarnung!: 5 % der Toleranz erreicht \n";
}
bool combinedCheck(bool tempCond, bool socCond, bool chargeRateCond) {
	return (tempCond&&socCond&&chargeRateCond);
}