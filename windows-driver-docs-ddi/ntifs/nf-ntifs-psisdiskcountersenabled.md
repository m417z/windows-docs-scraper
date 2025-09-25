# PsIsDiskCountersEnabled function

## Description

The enabled state of the per process disk I/O counters is returned by the **PsIsDiskCountersEnabled** routine.

## Return value

If TRUE, the disk

## Remarks

A file system driver uses the **PsIsDiskCountersEnabled** routine to query the system enabled state of the disk I/O counters. A file system driver will use this routine prior to accounting for process disk I/O using [PsUpdateDiskCounters](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-psupdatediskcounters).

## See also

[PsUpdateDiskCounters](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-psupdatediskcounters)