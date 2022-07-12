#ifndef BATTERYSTATUS_UT_H
#define BATTERYSTATUS_UT_H

#include <assert.h>
#include "ev_bms.h"


extern int CheckbatteryIsOk( float expectedsoc, float expectedTemp , float expectedChargeRate, char expectedTempUnit);
extern int CheckbatteryIsNotOk( float expectedsoc, float expectedTemp , float expectedChargeRate, char expectedTempUnit);
extern void CheckBatteryStatus(void);


#endif
