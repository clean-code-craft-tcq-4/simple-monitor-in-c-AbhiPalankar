#include <stdio.h>
#include "ev_bms.h"


/****************soc*****************************************/
int SocLowLimit(float soc)
{	
	if ((soc >= MIN_LOWSOCBREACH) || (soc <= MIN_SOCNORMAL))
	{
		return E_NOT_OK; 
	}
	else
	{
		/*SOC of Battery is in charging state*/
		return E_OK; 
	}
}

int SocHighLimit(float soc)
{
	if ((soc >= MIN_HIGHSOCWARNING) || (soc <= MIN_HIGHSOCBREACH))
	{
		return E_NOT_OK; 
	}
	else 
	{
		return E_NOT_OK; 
	}
	
}

int inttBatterySocIsOk(float soc )
{
	int socStatus = E_OK;
	if((soc >= MIN_LOWSOCBREACH) && (soc <= MIN_HIGHSOCWARNING))
	{
		socStatus = SocLowLimit(soc);
	}
	else
	{
		socStatus = SocHighLimit(soc);
	}
	return socStatus;
}

/****************TEMP*****************************************/
int TempLowLimit(float temp)
{	
	if ((temp >= MIN_LOWTEMPBREACH) || (temp <= MIN_TEMPNORMAL))
	{
		return E_NOT_OK; 
	}
	else
	{
		return E_OK; 
	}
}

int TempHighLimit(float temp)
{
	if ((temp >= MIN_HIGHTEMPWARNING) || (temp <= MIN_HIGHTEMPBREACH))
	{
		return E_NOT_OK; 
	}
	else 
	{
		inttBattConvertTemp(temp);
		return E_NOT_OK; 
	}
	
}

int BatteryTempIsOk(float temp)
{
	int tempStatus = E_OK;
	if((temp >= MIN_LOWTEMPBREACH) && (temp < MIN_HIGHTEMPWARNING))
	{
		tempStatus = TempLowLimit(temp);
	}
	else
	{
		tempStatus = TempHighLimit(temp);
	}
	return tempStatus;
}


float ConvertTemp(float temp)
{
	float celcius;
	if((temp > MAX_HIGHTEMPBREACH) && (tempUnit == TEMP_UNIT_FARENHEIT))
	{
		celcius = (temp - 32) * 5 / 9;
	}
	else
	{
		return temp;
	}
}
/****************ChargeRate*****************************************/
int ChargeRateLowLimit(float chargeRate)
{	
	if ((chargeRate >= MIN_LOWCHARGERATEBREACH) || (chargeRate <= MIN_CHARGERATENORMAL))
	{
		return E_NOT_OK; 
	}
	else
	{
		return E_OK; 
	}
}

int ChargeRateHighLimit(float chargeRate)
{
	if ((chargeRate >= MIN_HIGHCHARGERATEWARNING) || (chargeRate <= MIN_HIGHCHARGERATEBREACH))
	{
		return E_NOT_OK; 
	}
	else 
	{
		return E_NOT_OK; 
	}
	
}

int ChargeRateIsOk(float chargeRate )
{
	int chargeRateStatus = E_OK;
	if((chargeRate >= MIN_LOWCHARGERATEBREACH) && (chargeRate < MIN_HIGHCHARGERATEWARNING))
	{
		chargeRateStatus = ChargeRateLowLimit(chargeRate);
	}
	else
	{
		chargeRateStatus = ChargeRateHighLimit(chargeRate);
	}
	return chargeRateStatus;
}

int batteryIsOk( float soc, float temp , float chargeRate)
{	
	float stateOfCharge = inttBatterySocIsOk(soc);
	float temperature = BatteryTempIsOk(temp);
	float chargerate = ChargeRateIsOk(chargeRate);
	return (stateOfCharge && temperature && chargerate);
}
int batteryIsNotOk(float soc, float temp , float chargeRate)
{	
	float stateOfCharge = inttBatterySocIsOk(soc);
	float temperature = BatteryTempIsOk(temp);
	float chargerate = ChargeRateIsOk(chargeRate);
	return (stateOfCharge || temperature || chargerate);
}

