# VideoPortQuerySystemTime function

## Description

The **VideoPortQuerySystemTime** function obtains the current system time.

## Parameters

### `CurrentTime` [out]

Pointer to a memory location that will receive the current system time.

## Return value

None

## Remarks

System time is a count of 100-nanosecond intervals since January 1, 1601. System time is typically updated approximately every ten milliseconds. This value is computed for the GMT time zone. To adjust this value for the local time zone use [ExSystemTimeToLocalTime](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-exsystemtimetolocaltime).

## See also

[VideoPortQueryPerformanceCounter](https://learn.microsoft.com/windows-hardware/drivers/ddi/video/nf-video-videoportqueryperformancecounter)