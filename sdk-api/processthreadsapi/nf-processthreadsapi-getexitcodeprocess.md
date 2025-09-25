# GetExitCodeProcess function

## Description

Retrieves the termination status of the specified process.

## Parameters

### `hProcess` [in]

A handle to the process.

The handle must have the **PROCESS_QUERY_INFORMATION** or **PROCESS_QUERY_LIMITED_INFORMATION** access right. For more information, see
[Process Security and Access Rights](https://learn.microsoft.com/windows/desktop/ProcThread/process-security-and-access-rights).

**Windows Server 2003 and Windows XP:** The handle must have the **PROCESS_QUERY_INFORMATION** access right.

### `lpExitCode` [out]

A pointer to a variable to receive the process termination status. For more information, see Remarks.

## Return value

If the function succeeds, the return value is nonzero.

If the function fails, the return value is zero. To get extended error information, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

This function returns immediately. If the process has not terminated and the function succeeds, the status returned is **STILL_ACTIVE** (a macro for **STATUS_PENDING** (minwinbase.h)). If the process has terminated and the function succeeds, the status returned is one of the following values:

* The exit value specified in the
  [ExitProcess](https://learn.microsoft.com/windows/desktop/api/processthreadsapi/nf-processthreadsapi-exitprocess) or
  [TerminateProcess](https://learn.microsoft.com/windows/desktop/api/processthreadsapi/nf-processthreadsapi-terminateprocess) function.
* The return value from the [main](https://learn.microsoft.com/cpp/cpp/main-function-command-line-args) or [WinMain](https://learn.microsoft.com/windows/win32/api/winbase/nf-winbase-winmain) function of the process.
* The exception value for an unhandled exception that caused the process to terminate.

> [!IMPORTANT]
> The **GetExitCodeProcess** function returns a valid error code defined by the application only after the thread terminates. Therefore, an application should not use **STILL_ACTIVE** (259) as an error code (**STILL_ACTIVE** is a macro for **STATUS_PENDING** (minwinbase.h)). If a thread returns **STILL_ACTIVE** (259) as an error code, then applications that test for that value could interpret it to mean that the thread is still running, and continue to test for the completion of the thread after the thread has terminated, which could put the application into an infinite loop.

## See also

[ExitProcess](https://learn.microsoft.com/windows/desktop/api/processthreadsapi/nf-processthreadsapi-exitprocess)

[ExitThread](https://learn.microsoft.com/windows/desktop/api/processthreadsapi/nf-processthreadsapi-exitthread)

[Process and Thread Functions](https://learn.microsoft.com/windows/desktop/ProcThread/process-and-thread-functions)

[Processes](https://learn.microsoft.com/windows/desktop/ProcThread/child-processes)

[TerminateProcess](https://learn.microsoft.com/windows/desktop/api/processthreadsapi/nf-processthreadsapi-terminateprocess)

[Terminating a Process](https://learn.microsoft.com/windows/desktop/ProcThread/terminating-a-process)

[WinMain](https://learn.microsoft.com/windows/win32/api/winbase/nf-winbase-winmain)