# GetProcessIdOfThread function

## Description

Retrieves the process identifier of the process associated with the specified thread.

## Parameters

### `Thread` [in]

 A handle to the thread. The handle must have the THREAD_QUERY_INFORMATION or THREAD_QUERY_LIMITED_INFORMATION access right. For more information, see
[Thread Security and Access Rights](https://learn.microsoft.com/windows/desktop/ProcThread/thread-security-and-access-rights).

**Windows Server 2003:** The handle must have the THREAD_QUERY_INFORMATION access right.

## Return value

If the function succeeds, the return value is the process identifier of the process associated with the specified thread.

If the function fails, the return value is zero. To get extended error information, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

Until a process terminates, its process identifier uniquely identifies it on the system. For more information about access rights, see
[Thread Security and Access Rights](https://learn.microsoft.com/windows/desktop/ProcThread/thread-security-and-access-rights).

## See also

[GetCurrentThreadId](https://learn.microsoft.com/windows/desktop/api/processthreadsapi/nf-processthreadsapi-getcurrentthreadid)

[GetProcessId](https://learn.microsoft.com/windows/desktop/api/processthreadsapi/nf-processthreadsapi-getprocessid)

[GetThreadId](https://learn.microsoft.com/windows/desktop/api/processthreadsapi/nf-processthreadsapi-getthreadid)

[Processes](https://learn.microsoft.com/windows/desktop/ProcThread/child-processes)