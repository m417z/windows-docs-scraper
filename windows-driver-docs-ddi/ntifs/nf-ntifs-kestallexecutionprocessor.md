# KeStallExecutionProcessor function (ntifs.h)

## Description

The **KeStallExecutionProcessor** routine stalls the caller on the current processor for a specified time interval.

## Parameters

### `MicroSeconds` [in]

Specifies the number of microseconds to stall.

## Return value

None

## Remarks

**KeStallExecutionProcessor** is a processor-dependent routine that busy-waits for at least the specified number of microseconds, but not significantly longer.

This routine is for use by device drivers and other software that must wait for an interval of less than a clock tick but more than for a few instructions. If you use this routine you must minimize the stall interval, typically to less than 50 microseconds. If a driver must wait for a longer interval, you should use a different [synchronization technique](https://learn.microsoft.com/windows-hardware/drivers/kernel/synchronization-techniques).

## See also

[**KeDelayExecutionThread**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-kedelayexecutionthread)

[**KeWaitForMultipleObjects**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-kewaitformultipleobjects)

[**KeWaitForSingleObject**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-kewaitforsingleobject)