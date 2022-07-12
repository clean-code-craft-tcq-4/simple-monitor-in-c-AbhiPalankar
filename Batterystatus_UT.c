#include "Batterystatus_UT.h"


int CheckbatteryIsOk(float expectedsoc, float expectedTemp , float expectedChargeRate)
{	
	batteryIsOk(expectedsoc,expectedTemp,expectedChargeRate);
}
int CheckbatteryIsNotOk(float expectedsoc, float expectedTemp , float expectedChargeRate)
{	
	batteryIsNotOk(expectedsoc,expectedTemp,expectedChargeRate);
}

void CheckBatteryStatus(void)
{
  assert(CheckbatteryIsOk(25, 70, 0.7));
  assert(CheckbatteryIsNotOk(50, 85, 0));

}
