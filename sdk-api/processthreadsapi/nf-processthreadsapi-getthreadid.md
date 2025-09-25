# GetThreadId function

## Description

Retrieves the thread identifier of the specified thread.

## Parameters

### `Thread` [in]

A handle to the thread. The handle must have the THREAD_QUERY_INFORMATION or THREAD_QUERY_LIMITED_INFORMATION access right. For more information about access rights, see
[Thread Security and Access Rights](https://learn.microsoft.com/windows/desktop/ProcThread/thread-security-and-access-rights).

**Windows Server 2003:** The handle must have the THREAD_QUERY_INFORMATION access right.

## Return value

If the function fails, the return value is zero. To get extended error information, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

Until a thread terminates, its thread identifier uniquely identifies it on the system.

To compile an application that uses this function, define _WIN32_WINNT as 0x0502 or later. For more information, see
[Using the Windows Headers](https://learn.microsoft.com/windows/desktop/WinProg/using-the-windows-headers).

## See also

[GetCurrentThreadId](https://learn.microsoft.com/windows/desktop/api/processthreadsapi/nf-processthreadsapi-getcurrentthreadid)

[GetProcessId](https://learn.microsoft.com/windows/desktop/api/processthreadsapi/nf-processthreadsapi-getprocessid)

[GetProcessIdOfThread](https://learn.microsoft.com/windows/desktop/api/processthreadsapi/nf-processthreadsapi-getprocessidofthread)

[Process and Thread Functions](https://learn.microsoft.com/windows/desktop/ProcThread/process-and-thread-functions)

[Threads](https://learn.microsoft.com/windows/desktop/ProcThread/multiple-threads)