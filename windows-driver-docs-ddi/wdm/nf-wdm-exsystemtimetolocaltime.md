# ExSystemTimeToLocalTime function

## Description

The **ExSystemTimeToLocalTime** routine converts a GMT system time value to the local system time for the current time zone.

## Parameters

### `SystemTime` [in]

A pointer to a variable set to the unbiased, GMT system time.

### `LocalTime` [out]

A pointer to the returned value for the current locale.

## Remarks

**ExSystemTimeToLocalTime** subtracts the time-zone bias from the GMT system time value to compute the corresponding time at the current locale.

## See also

[ExLocalTimeToSystemTime](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-exlocaltimetosystemtime)