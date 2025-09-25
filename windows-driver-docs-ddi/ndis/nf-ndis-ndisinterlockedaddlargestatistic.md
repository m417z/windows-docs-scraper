# NdisInterlockedAddLargeStatistic macro

## Description

The
**NdisInterlockedAddLargeStatistic** function performs an interlocked addition of a ULONG increment value
to a LARGE_INTEGER addend value.

## Parameters

### `_Addend` [in]

A pointer to a LARGE_INTEGER value that is incremented by the value of
*Increment* .

### `_Increment` [in]

A ULONG value that is added to the value to which the
*Addend* parameter points.

## Remarks

Functions that perform interlocked operations must not cause a page fault to occur. Neither their code
nor any of the data that they access can cause a page fault without bringing down the local computer.

**NdisInterlockedAddLargeStatistic** masks interrupts and can be safely used to synchronize a driver's
[MiniportInterrupt](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-miniport_isr) function with other
driver code.

## See also

[MiniportInterrupt](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-miniport_isr)