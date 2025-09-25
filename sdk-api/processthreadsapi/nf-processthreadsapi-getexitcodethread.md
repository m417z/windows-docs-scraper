# GetExitCodeThread function

## Description

Retrieves the termination status of the specified thread.

## Parameters

### `hThread` [in]

A handle to the thread.

The handle must have the **THREAD_QUERY_INFORMATION** or **THREAD_QUERY_LIMITED_INFORMATION** access right. For more information, see
[Thread Security and Access Rights](https://learn.microsoft.com/windows/desktop/ProcThread/thread-security-and-access-rights).

**Windows Server 2003 and Windows XP:** The handle must have the **THREAD_QUERY_INFORMATION** access right.

### `lpExitCode` [out]

A pointer to a variable to receive the thread termination status. For more information, see Remarks.

## Return value

If the function succeeds, the return value is nonzero.

If the function fails, the return value is zero. To get extended error information, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

This function returns immediately. If the specified thread has not terminated and the function succeeds, the status returned is **STILL_ACTIVE**. If the thread has terminated and the function succeeds, the status returned is one of the following values:

* The exit value specified in the
  [ExitThread](https://learn.microsoft.com/windows/desktop/api/processthreadsapi/nf-processthreadsapi-exitthread) or
  [TerminateThread](https://learn.microsoft.com/windows/desktop/api/processthreadsapi/nf-processthreadsapi-terminatethread) function.
* The return value from the thread function.
* The exit value of the thread's process.

**Important** The **GetExitCodeThread** function returns a valid error code defined by the application only after the thread terminates. Therefore, an application should not use **STILL_ACTIVE** (259) as an error code. If a thread returns **STILL_ACTIVE** (259) as an error code, applications that test for this value could interpret it to mean that the thread is still running and continue to test for the completion of the thread after the thread has terminated, which could put the application into an infinite loop. To avoid this problem, callers should call the **GetExitCodeThread** function only after the thread has been confirmed to have exited. Use the [WaitForSingleObject](https://learn.microsoft.com/windows/desktop/api/synchapi/nf-synchapi-waitforsingleobject) function with a wait duration of zero to determine whether a thread has exited.

**Windows Phone 8.1:** This function is supported for Windows Phone Store apps on Windows Phone 8.1 and later.

**Windows 8.1** and **Windows Server 2012 R2**: This function is supported for Windows Store apps on Windows 8.1, Windows Server 2012 R2, and later.

## See also

[ExitThread](https://learn.microsoft.com/windows/desktop/api/processthreadsapi/nf-processthreadsapi-exitthread)

[GetExitCodeProcess](https://learn.microsoft.com/windows/desktop/api/processthreadsapi/nf-processthreadsapi-getexitcodeprocess)

[OpenThread](https://learn.microsoft.com/windows/desktop/api/processthreadsapi/nf-processthreadsapi-openthread)

[Process and Thread Functions](https://learn.microsoft.com/windows/desktop/ProcThread/process-and-thread-functions)

[TerminateThread](https://learn.microsoft.com/windows/desktop/api/processthreadsapi/nf-processthreadsapi-terminatethread)

[Terminating a Thread](https://learn.microsoft.com/windows/desktop/ProcThread/terminating-a-thread)