# NdisStallExecution macro

## Description

The
**NdisStallExecution** function stalls the caller on the current processor for a given interval.

## Parameters

### `MicroSecondsToStall`

The number of microseconds to delay. A driver should specify no more than 50 microseconds.

## Remarks

**NdisStallExecution** is a processor-dependent function that busy-waits for at least the specified
number of microseconds, but not significantly longer.

This function should be called by drivers that must wait for an interval of more than a few
instructions but less than 50 microseconds. Drivers that call this routine should minimize the number of
microseconds that they specify.

If a driver must wait for an interval longer than 50 microseconds, it should call the
[NdisMSleep](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndismsleep) function. Note that callers of
**NdisMSleep** run at IRQL < DISPATCH_LEVEL.

## See also

[MiniportInitializeEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-miniport_initialize)

[MiniportResetEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-miniport_reset)

[NdisMSleep](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndismsleep)

[NdisSetTimerObject](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndissettimerobject)