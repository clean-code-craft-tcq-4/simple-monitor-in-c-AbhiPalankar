#ifndef EV_BMS_H
#define EV_BMS_H
#include <stdbool.h>
#define MAX_CAPACITY_BATTERY 25


#define MIN_LOWSOCBREACH         0
#define MIN_LOWSOCWARNING        20
#define MIN_SOCNORMAL		     24
#define MIN_HIGHSOCWARNING 	     75
#define MIN_HIGHSOCBREACH        80
#define MAX_HIGHOCBREACH         100

#define MIN_LOWTEMPBREACH        0
#define MIN_LOWTEMPWARNING       5
#define MIN_TEMPNORMAL           10
#define MIN_HIGHTEMPWARNING      40
#define MIN_HIGHTEMPBREACH       45
#define MAX_HIGHTEMPBREACH       80

#define MIN_LOWCHARGERATEBREACH   0
#define MIN_LOWCHARGERATEWARNING  0.2
#define MIN_CHARGERATENORMAL      0.3
#define MIN_HIGHCHARGERATEWARNING 0.7
#define MIN_HIGHCHARGERATEBREACH  0.8
#define MAX_HIGHCHARGERATEBREACH  1.0

#define TEMP_UNIT_CELCIUS         'C'
#define TEMP_UNIT_FARENHEIT       'F'

#define E_OK                       0
#define E_NOT_OK                   1



extern int SocLowLimit(float soc);
extern int SocHighLimit(float soc);
extern int BatterySocIsOk(float soc );
extern int TempLowLimit(float temp);
extern int TempHighLimit(float temp, char tempUnit);
extern int TempIsOk(float temp , char tempUnit);
extern int ChargeRateLowLimit(float chargeRate);
extern int ChargeRateHighLimit(float chargeRate);
extern int ChargeRateIsOk(float chargeRate );
extern bool inttBattTempUnit(char cel);
extern float inttBattConvertTemp(float temp, char tempUnit);

extern int batteryIsOk( float soc, float temp , float chargeRate, char tempUnit);
extern int batteryIsNotOk( float soc, float temp , float chargeRate,char tempUnit);


#endif
