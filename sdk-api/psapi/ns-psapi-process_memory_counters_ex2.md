## Description

Contains extended memory statistics for a process. Extends PROCESS_MEMORY_COUNTERS_EX.

## Members

### `cb`

The size of the structure, in bytes.

### `PageFaultCount`

The number of page faults.

### `PeakWorkingSetSize`

The peak working set size, in bytes.

### `WorkingSetSize`

The current working set size, in bytes

### `QuotaPeakPagedPoolUsage`

The peak paged pool usage, in bytes.

### `QuotaPagedPoolUsage`

The current paged pool usage, in bytes.

### `QuotaPeakNonPagedPoolUsage`

The peak non-paged pool usage, in bytes.

### `QuotaNonPagedPoolUsage`

The current non-paged pool usage, in bytes.

### `PagefileUsage`

The Commit Charge value in bytes for this process. Commit Charge is the total amount of private memory that the memory manager has committed for a running process.

### `PeakPagefileUsage`

The peak value in bytes of the Commit Charge during the lifetime of this process.

### `PrivateUsage`

Same as **PagefileUsage**. The Commit Charge value in bytes for this process. Commit Charge is the total amount of private memory that the memory manager has committed for a running process.

### `PrivateWorkingSetSize`

The current private working set size, in bytes.

### `SharedCommitUsage`

The current shared commit usage, in bytes.

## Remarks

## See also

[PROCESS_MEMORY_COUNTERS_EX](https://learn.microsoft.com/windows/win32/api/psapi/ns-psapi-process_memory_counters_ex)