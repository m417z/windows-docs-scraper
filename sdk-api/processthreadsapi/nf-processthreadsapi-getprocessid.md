# GetProcessId function

## Description

Retrieves the process identifier of the specified process.

## Parameters

### `Process` [in]

A handle to the process. The handle must have the PROCESS_QUERY_INFORMATION or PROCESS_QUERY_LIMITED_INFORMATION access right. For more information, see
[Process Security and Access Rights](https://learn.microsoft.com/windows/desktop/ProcThread/process-security-and-access-rights).

**Windows Server 2003 and Windows XP:** The handle must have the PROCESS_QUERY_INFORMATION access right.

## Return value

If the function succeeds, the return value is the process identifier.

If the function fails, the return value is zero. To get extended error information, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

Until a process terminates, its process identifier uniquely identifies it on the system. For more information about access rights, see
[Process Security and Access Rights](https://learn.microsoft.com/windows/desktop/ProcThread/process-security-and-access-rights).

## See also

[GetCurrentProcessId](https://learn.microsoft.com/windows/desktop/api/processthreadsapi/nf-processthreadsapi-getcurrentprocessid)

[GetProcessIdOfThread](https://learn.microsoft.com/windows/desktop/api/processthreadsapi/nf-processthreadsapi-getprocessidofthread)

[GetThreadId](https://learn.microsoft.com/windows/desktop/api/processthreadsapi/nf-processthreadsapi-getthreadid)

[Processes](https://learn.microsoft.com/windows/desktop/ProcThread/child-processes)