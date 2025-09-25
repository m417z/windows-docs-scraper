# EngQueryPerformanceCounter function

## Description

The **EngQueryPerformanceCounter** function queries the performance counter.

## Parameters

### `pPerformanceCount` [out]

Pointer to a location that receives the performance counter value, in hertz.

## Return value

None

## Remarks

**EngQueryPerformanceCounter** always returns a 64-bit integer that represents the number of ticks per second. The count begins accumulating when the system is booted.

A driver should call this routine sparingly. Frequent calls to **EngQueryPerformanceCounter** can degrade the I/O performance for the calling driver and for the system as a whole.

## See also

[EngQueryPerformanceFrequency](https://learn.microsoft.com/windows/desktop/api/winddi/nf-winddi-engqueryperformancefrequency)