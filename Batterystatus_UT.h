#ifndef BATTERYSTATUS_UT_H
#define BATTERYSTATUS_UT_H

#include <assert.h>


extern int checkbatteryIsOk( float expectedsoc, float expectedTemp , float expectedChargeRate);
extern int checkbatteryIsNotOk( float expectedsoc, float expectedTemp , float expectedChargeRate);
extern void CheckBatteryStatus(void);


#endif
