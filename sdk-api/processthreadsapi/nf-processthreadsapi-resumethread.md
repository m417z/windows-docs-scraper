# ResumeThread function

## Description

Decrements a thread's suspend count. When the suspend count is decremented to zero, the execution of the thread is resumed.

## Parameters

### `hThread` [in]

A handle to the thread to be restarted.

This handle must have the THREAD_SUSPEND_RESUME access right. For more information, see
[Thread Security and Access Rights](https://learn.microsoft.com/windows/desktop/ProcThread/thread-security-and-access-rights).

## Return value

If the function succeeds, the return value is the thread's previous suspend count.

If the function fails, the return value is (DWORD) -1. To get extended error information, call [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

The
**ResumeThread** function checks the suspend count of the subject thread. If the suspend count is zero, the thread is not currently suspended. Otherwise, the subject thread's suspend count is decremented. If the resulting value is zero, then the execution of the subject thread is resumed.

If the return value is zero, the specified thread was not suspended. If the return value is 1, the specified thread was suspended but was restarted. If the return value is greater than 1, the specified thread is still suspended.

Note that while reporting debug events, all threads within the reporting process are frozen. Debuggers are expected to use the
[SuspendThread](https://learn.microsoft.com/windows/desktop/api/processthreadsapi/nf-processthreadsapi-suspendthread) and
**ResumeThread** functions to limit the set of threads that can execute within a process. By suspending all threads in a process except for the one reporting a debug event, it is possible to "single step" a single thread. The other threads are not released by a continue operation if they are suspended.

**Windows Phone 8.1:** This function is supported for Windows Phone Store apps on Windows Phone 8.1 and later.

**Windows 8.1** and **Windows Server 2012 R2**: This function is supported for Windows Store apps on Windows 8.1, Windows Server 2012 R2, and later.

## See also

[OpenThread](https://learn.microsoft.com/windows/desktop/api/processthreadsapi/nf-processthreadsapi-openthread)

[Process and Thread Functions](https://learn.microsoft.com/windows/desktop/ProcThread/process-and-thread-functions)

[SuspendThread](https://learn.microsoft.com/windows/desktop/api/processthreadsapi/nf-processthreadsapi-suspendthread)

[Suspending Thread Execution](https://learn.microsoft.com/windows/desktop/ProcThread/suspending-thread-execution)

[Threads](https://learn.microsoft.com/windows/desktop/ProcThread/multiple-threads)