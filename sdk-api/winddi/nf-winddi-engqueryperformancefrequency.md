# EngQueryPerformanceFrequency function

## Description

The **EngQueryPerformanceFrequency** function queries the frequency of the performance counter.

## Parameters

### `pFrequency` [out]

Pointer to a location that receives the performance counter frequency.

## Return value

None

## Remarks

The resolution of the timer is 1/*x*, where *x* is the value returned in the location to which *pFrequency* points. For example, if the value returned in *pFrequency* is 2 million, each tick is 1/2 millionth of a second. Each 1/*x* millionth increment of the count corresponds to one second of elapsed time.

A driver should call this routine sparingly. Frequent calls to **EngQueryPerformanceFrequency** can degrade the I/O performance for the calling driver and for the system as a whole.

## See also

[EngQueryPerformanceCounter](https://learn.microsoft.com/windows/desktop/api/winddi/nf-winddi-engqueryperformancecounter)