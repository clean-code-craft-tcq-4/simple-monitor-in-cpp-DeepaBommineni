#include "checker.hpp"

bool isRangeOk(float value, float LOWER_LIMIT, float HIGH_LIMIT) {
	if (value < LOWER_LIMIT || value > HIGH_LIMIT) {
		return false;
	}
	return true;
}
void printMessage() {
	cout << " Out of Range!!\n";
	cout << " Au�er Reichweite!!\n";
}
void printTolMessage() {
	cout << "Early warning!: Reaching  5% of Tolerance \n";
	cout << "Fr�hwarnung!: Toleran-z erreichen \n";
}