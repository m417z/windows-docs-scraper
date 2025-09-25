# PFNKSCLOCK_CORRELATEDTIME callback function

## Description

The routine
is a system-supplied routine that retrieves and the following:

*KStrClockGetCorrelatedTime* is a system-supplied routine that retrieves both the current system time and the corresponding clock tick count since boot.

*KStrClockGetCorrelatedPhysicalTime* is a system-supplied routine that retrieves both the current system time minus suspended delta and the corresponding clock tick since boot.

## Parameters

### `FileObject` [in]

A pointer to the [FILE_OBJECT](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_file_object) structure to which a handle was returned when the clock instance was created.

### `SystemTime` [out]

A pointer to a 64-bit integer containing the number of clock ticks since system boot.

## Return value

This routine returns the current system time as a value of type LONGLONG. This value is specified in 100 nanosecond units.

## Remarks

You can obtain an entry point for this routine by supplying a driver-allocated [KSCLOCK_FUNCTIONTABLE](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/ns-ks-ksclock_functiontable) structure in a [KSPROPERTY_CLOCK_FUNCTIONTABLE](https://learn.microsoft.com/windows-hardware/drivers/stream/ksproperty-clock-functiontable) request.

The system time is acquired from [KeQueryPerformanceCounter](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-kequeryperformancecounter).

Both time values are specified in 100 nanosecond units.

## See also

[KSCLOCK_FUNCTIONTABLE](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/ns-ks-ksclock_functiontable)

[KSCORRELATED_TIME](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/ns-ks-kscorrelated_time)

[KSPROPERTY_CLOCK_FUNCTIONTABLE](https://learn.microsoft.com/windows-hardware/drivers/stream/ksproperty-clock-functiontable)

[KeQueryPerformanceCounter](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-kequeryperformancecounter)