#include "Batterystatus_UT.h"


int CheckbatteryIsOk(float expectedsoc, float expectedTemp , float expectedChargeRate, char expectedTempUnit)
{	
	batteryIsOk(expectedsoc,expectedTemp,expectedChargeRate,expectedTempUnit);
}
int CheckbatteryIsNotOk(float expectedsoc, float expectedTemp , float expectedChargeRate, char expectedTempUnit)
{	
	batteryIsNotOk(expectedsoc,expectedTemp,expectedChargeRate,expectedTempUnit);
}

void CheckBatteryStatus(void)
{
  assert(CheckbatteryIsOk(25, 70, 0.7,'C'));
  assert(CheckbatteryIsNotOk(50, 85, 0,'F'));

}
