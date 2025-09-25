# PFNKSCLOCK_GETTIME callback function

## Description

The routine gets system time.

*KStrClockGetTime* is a system-supplied routine that retrieves the current system time.

*KStrClockGetPhysicalTime* is a system-supplied routine that retrieves the current system time minus any suspended delta.

## Parameters

### `FileObject` [in]

A pointer to the [FILE_OBJECT](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_file_object) structure to which a handle was returned when the clock instance was created.

## Return value

This routine returns the requested time value as a value of type LONGLONG. This value is specified in 100 nanosecond units.

## Remarks

You can obtain an entry point for this routine by supplying a driver-allocated [KSCLOCK_FUNCTIONTABLE](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/ns-ks-ksclock_functiontable) structure in a [KSPROPERTY_CLOCK_FUNCTIONTABLE](https://learn.microsoft.com/windows-hardware/drivers/stream/ksproperty-clock-functiontable) request.

## See also

[KSCLOCK_FUNCTIONTABLE](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/ns-ks-ksclock_functiontable)

[KSPROPERTY_CLOCK_FUNCTIONTABLE](https://learn.microsoft.com/windows-hardware/drivers/stream/ksproperty-clock-functiontable)