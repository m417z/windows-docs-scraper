# timeEndPeriod function

## Description

The **timeEndPeriod** function clears a previously set minimum timer resolution.

## Parameters

### `uPeriod`

Minimum timer resolution specified in the previous call to the [timeBeginPeriod](https://learn.microsoft.com/windows/desktop/api/timeapi/nf-timeapi-timebeginperiod) function.

## Return value

Returns **TIMERR_NOERROR** if successful or **TIMERR_NOCANDO** if the resolution specified in uPeriod is out of range.

## Remarks

Call this function immediately after you are finished using timer services.

You must match each call to [timeBeginPeriod](https://learn.microsoft.com/windows/desktop/api/timeapi/nf-timeapi-timebeginperiod) with a call to **timeEndPeriod**, specifying the same minimum resolution in both calls. An application can make multiple **timeBeginPeriod** calls as long as each call is matched with a call to **timeEndPeriod**.

## See also

[Multimedia Timer Functions](https://learn.microsoft.com/windows/desktop/Multimedia/multimedia-timer-functions)

[Multimedia Timers](https://learn.microsoft.com/windows/desktop/Multimedia/multimedia-timers)