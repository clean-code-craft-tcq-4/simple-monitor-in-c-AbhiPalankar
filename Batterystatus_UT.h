#ifndef TEST_BMSSTATUS_H
#define TEST_BMSSTATUS_H

#include <assert.h>


extern int checkbatteryIsOk( float expectedsoc, float expectedTemp , float expectedChargeRate);
extern int checkbatteryIsNotOk( float expectedsoc, float expectedTemp , float expectedChargeRate);
extern void checkBatteryStatus(void);


#endif
