# KeLeaveCriticalRegion function (wdm.h)

## Description

The **KeLeaveCriticalRegion** routine reenables the delivery of normal kernel-mode APCs that were disabled by a preceding call to **KeEnterCriticalRegion**.

## Remarks

Highest-level drivers can call this routine while running in the context of the thread that requested the current I/O operation.

## See also

[KeAreApcsDisabled](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-keareapcsdisabled)

[KeEnterCriticalRegion](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-keentercriticalregion)