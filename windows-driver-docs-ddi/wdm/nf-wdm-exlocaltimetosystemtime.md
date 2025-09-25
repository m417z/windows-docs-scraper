# ExLocalTimeToSystemTime function

## Description

The **ExLocalTimeToSystemTime** routine converts a system time value for the current time zone to an unbiased, GreenGMT value.

## Parameters

### `LocalTime` [in]

A pointer to a variable set to the locale-specific time.

### `SystemTime` [out]

A pointer to the returned value for GMT system time.

## Remarks

**ExLocalTimeToSystemTime** adds the time-zone bias at the current locale to compute the corresponding GMT system time value.

## See also

[ExSystemTimeToLocalTime](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-exsystemtimetolocaltime)