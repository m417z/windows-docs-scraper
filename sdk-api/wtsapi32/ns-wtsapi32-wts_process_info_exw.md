# WTS_PROCESS_INFO_EXW structure

## Description

Contains extended information about a process running on a Remote Desktop Session Host (RD Session Host) server. This structure is returned by the [WTSEnumerateProcessesEx](https://learn.microsoft.com/windows/desktop/api/wtsapi32/nf-wtsapi32-wtsenumerateprocessesexa) function when you set the *pLevel* parameter to one.

## Members

### `SessionId`

The Remote Desktop Services session identifier for the session associated with the process.

### `ProcessId`

The process identifier that uniquely identifies the process on the RD Session Host server.

### `pProcessName`

A pointer to a null-terminated string that contains the name of the executable file associated with the process.

### `pUserSid`

A pointer to the user security identifiers (SIDs) in the primary access token of the process. For more
information about SIDs and access tokens, see
[Access Control](https://learn.microsoft.com/windows/desktop/SecAuthZ/access-control) and
[Security Identifiers](https://learn.microsoft.com/windows/desktop/SecAuthZ/security-identifiers).

### `NumberOfThreads`

The number of threads in the process.

### `HandleCount`

The number of handles in the process.

### `PagefileUsage`

The page file usage of the process, in bytes.

### `PeakPagefileUsage`

The peak page file usage of the process, in bytes.

### `WorkingSetSize`

The working set size of the process, in bytes.

### `PeakWorkingSetSize`

The peak working set size of the process, in bytes.

### `UserTime`

The amount of time, in milliseconds, the process has been running in user mode.

### `KernelTime`

The amount of time, in milliseconds, the process has been running in kernel mode.

## See also

[WTSEnumerateProcesses](https://learn.microsoft.com/windows/desktop/api/wtsapi32/nf-wtsapi32-wtsenumerateprocessesa)

[WTSEnumerateProcessesEx](https://learn.microsoft.com/windows/desktop/api/wtsapi32/nf-wtsapi32-wtsenumerateprocessesexa)

[WTS_PROCESS_INFO](https://learn.microsoft.com/windows/desktop/api/wtsapi32/ns-wtsapi32-wts_process_infoa)

## Remarks

> [!NOTE]
> The wtsapi32.h header defines WTS_PROCESS_INFO_EX as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).