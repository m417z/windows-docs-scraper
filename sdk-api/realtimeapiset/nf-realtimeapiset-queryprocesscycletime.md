# QueryProcessCycleTime function

## Description

Retrieves the sum of the cycle time of all threads of the specified process.

## Parameters

### `ProcessHandle` [in]

A handle to the process. The handle must have the PROCESS_QUERY_INFORMATION or PROCESS_QUERY_LIMITED_INFORMATION access right. For more information, see
[Process Security and Access Rights](https://learn.microsoft.com/windows/desktop/ProcThread/process-security-and-access-rights).

### `CycleTime` [out]

The number of CPU clock cycles used by the threads of the process. This value includes cycles spent in both user mode and kernel mode.

## Return value

If the function succeeds, the return value is nonzero.

If the function fails, the return value is zero. To get extended error information, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

To enumerate the processes in the system, use the
[EnumProcesses](https://learn.microsoft.com/windows/desktop/api/psapi/nf-psapi-enumprocesses) function.

To compile an application that uses this function, define _WIN32_WINNT as 0x0600 or later.

## See also

[QueryIdleProcessorCycleTime](https://learn.microsoft.com/windows/desktop/api/realtimeapiset/nf-realtimeapiset-queryidleprocessorcycletime)

[QueryThreadCycleTime](https://learn.microsoft.com/windows/desktop/api/realtimeapiset/nf-realtimeapiset-querythreadcycletime)