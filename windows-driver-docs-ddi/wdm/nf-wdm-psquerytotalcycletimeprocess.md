# PsQueryTotalCycleTimeProcess function

## Description

The **PsQueryTotalCycleTimeProcess** routine returns the accumulated cycle time for the specified process.

## Parameters

### `Process` [in, out]

A pointer to an [EPROCESS](https://learn.microsoft.com/windows-hardware/drivers/kernel/eprocess) structure that serves as the kernel object for the process.

### `CycleTimeStamp` [out]

A pointer to a ULONG64 variable to which the routine writes the current cycle counter value for the process.

## Return value

**PsQueryTotalCycleTimeProcess** returns the accumulated cycle time for the specified process.

## Remarks

This routine uses the time stamp counter to get the number of processor clock cycles used by the specified process.

## See also

[EPROCESS](https://learn.microsoft.com/windows-hardware/drivers/kernel/eprocess)