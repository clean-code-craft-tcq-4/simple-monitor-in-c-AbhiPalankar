#ifndef BATTERYSTATUS_UT_H
#define BATTERYSTATUS_UT_H

#include <assert.h>


extern int CheckbatteryIsOk( float expectedsoc, float expectedTemp , float expectedChargeRate);
extern int CheckbatteryIsNotOk( float expectedsoc, float expectedTemp , float expectedChargeRate);
extern void CheckBatteryStatus(void);


#endif
