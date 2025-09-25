# KeQueryTickCount macro (wdm.h)

## Description

The **KeQueryTickCount** routine maintains a count of the interval timer interrupts that have occurred since the system was booted.

## Parameters

### `CurrentCount` [out]

Pointer to the LARGE_INTEGER tick count value on return from **KeQueryTickCount**.

## Remarks

The *TickCount* value increases by one at each interval timer interrupt while the system is running.

The preferred method of determining elapsed time is by using *TickCount* for relative timing and time stamps.

To determine the absolute elapsed time multiply the returned *TickCount* by the [KeQueryTimeIncrement](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-kequerytimeincrement) return value using compiler support for 64-bit integer operations.

You should not make any assumptions about the length of a tick, because it might vary depending on hardware and other considerations.

## See also

[KeQueryInterruptTime](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-kequeryinterrupttime)

[KeQueryPerformanceCounter](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-kequeryperformancecounter)

[KeQueryTimeIncrement](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-kequerytimeincrement)