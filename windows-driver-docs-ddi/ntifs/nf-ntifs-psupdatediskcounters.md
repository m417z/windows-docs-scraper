# PsUpdateDiskCounters function

## Description

The **PsUpdateDiskCounters** routine updates the disk I/O counters of a given process.

## Parameters

### `Process`

A pointer to the process to update counters for.

### `BytesRead`

The number of bytes to update in the Read counter.

### `BytesWritten`

The number of bytes to update in the Write counter.

### `ReadOperationCount`

The number of read operations to update in the Read Operation counter.

### `WriteOperationCount`

The number of write operations to update in the Write Operation counter.

### `FlushOperationCount`

The number of flush operations to update in the Flush Operation counter.

## Remarks

File system drivers use **PsUpdateDiskCounters** to update counts for disk I/O accounting. A client process can be "charged" the disk I/O counts by the file system.

## See also

[PsIsDiskCountersEnabled](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-psisdiskcountersenabled)