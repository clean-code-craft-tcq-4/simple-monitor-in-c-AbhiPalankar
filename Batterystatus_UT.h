#ifndef BATTERYSTATUS_UT_H
#define BATTERYSTATUS_UT_H

#include <assert.h>

extern int batteryIsOk( float soc, float temp , float chargeRate);
extern int batteryIsNotOk( float soc, float temp , float chargeRate);
extern int CheckbatteryIsOk( float expectedsoc, float expectedTemp , float expectedChargeRate);
extern int CheckbatteryIsNotOk( float expectedsoc, float expectedTemp , float expectedChargeRate);
extern void CheckBatteryStatus(void);


#endif
