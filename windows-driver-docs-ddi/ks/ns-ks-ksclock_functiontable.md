# KSCLOCK_FUNCTIONTABLE structure

## Description

The KSCLOCK_FUNCTIONTABLE structure describes a function table for the master clock.

## Members

### `GetTime`

Pointer to a driver-allocated [KStrClockGetTime](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/nc-ks-pfnksclock_gettime) routine.

### `GetPhysicalTime`

Pointer to a driver-allocated [KStrClockGetPhysicalTime](https://learn.microsoft.com/previous-versions/ff567160(v=vs.85)) routine.

### `GetCorrelatedTime`

Pointer to a driver-allocated [KStrClockGetCorrelatedTime](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/nc-ks-pfnksclock_correlatedtime) routine.

### `GetCorrelatedPhysicalTime`

Pointer to a driver-allocated [KStrClockGetCorrelatedPhysicalTime](https://learn.microsoft.com/previous-versions/ff567157(v=vs.85)) routine.

## Remarks

Supply this structure in a [KSPROPERTY_CLOCK_FUNCTIONTABLE](https://learn.microsoft.com/windows-hardware/drivers/stream/ksproperty-clock-functiontable) request. The property request then returns pointers to the requested routines.

The function pointers returned in this structure are valid until the clock's file object is released.

## See also

[KSPROPERTY_CLOCK_FUNCTIONTABLE](https://learn.microsoft.com/windows-hardware/drivers/stream/ksproperty-clock-functiontable)