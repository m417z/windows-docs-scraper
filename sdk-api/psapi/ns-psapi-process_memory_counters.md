# PROCESS_MEMORY_COUNTERS structure

## Description

Contains the memory statistics for a process.

## Members

### `cb`

The size of the structure, in bytes.

### `PageFaultCount`

The number of page faults.

### `PeakWorkingSetSize`

The peak working set size, in bytes.

### `WorkingSetSize`

The current working set size, in bytes.

### `QuotaPeakPagedPoolUsage`

The peak paged pool usage, in bytes.

### `QuotaPagedPoolUsage`

The current paged pool usage, in bytes.

### `QuotaPeakNonPagedPoolUsage`

The peak nonpaged pool usage, in bytes.

### `QuotaNonPagedPoolUsage`

The current nonpaged pool usage, in bytes.

### `PagefileUsage`

The Commit Charge value in bytes for this process. Commit Charge is the total amount of memory that the memory manager has committed for a running process.

### `PeakPagefileUsage`

The peak value in bytes of the Commit Charge during the lifetime of this process.

## See also

[GetProcessMemoryInfo](https://learn.microsoft.com/windows/desktop/api/psapi/nf-psapi-getprocessmemoryinfo)

[Memory Performance Information](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/aa965225(v=vs.85))

[Process Memory Usage Information](https://learn.microsoft.com/windows/desktop/psapi/process-memory-usage-information)

[Working Set Information](https://learn.microsoft.com/windows/desktop/psapi/working-set-information)