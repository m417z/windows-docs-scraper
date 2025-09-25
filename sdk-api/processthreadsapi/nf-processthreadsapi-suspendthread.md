# SuspendThread function

## Description

Suspends the specified thread.

> [!NOTE]
> A 64-bit application can suspend a WOW64 thread thread using the [Wow64SuspendThread function](https://learn.microsoft.com/windows/win32/api/wow64apiset/nf-wow64apiset-wow64suspendthread).

## Parameters

### `hThread` [in]

A handle to the thread that is to be suspended.

The handle must have the **THREAD_SUSPEND_RESUME** access right. For more information, see
[Thread Security and Access Rights](https://learn.microsoft.com/windows/desktop/ProcThread/thread-security-and-access-rights).

## Return value

If the function succeeds, the return value is the thread's previous suspend count; otherwise, it is `(DWORD) -1`. To get extended error information, use the
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror) function.

## Remarks

If the function succeeds, execution of the specified thread is suspended and the thread's suspend count is incremented. Suspending a thread causes the thread to stop executing user-mode (application) code.

This function is primarily designed for use by debuggers. It is not intended to be used for thread synchronization. Calling
**SuspendThread** on a thread that owns a synchronization object, such as a mutex or critical section, can lead to a deadlock if the calling thread tries to obtain a synchronization object owned by a suspended thread. To avoid this situation, a thread within an application that is not a debugger should signal the other thread to suspend itself. The target thread must be designed to watch for this signal and respond appropriately.

Each thread has a suspend count (with a maximum value of **MAXIMUM_SUSPEND_COUNT**). If the suspend count is greater than zero, the thread is suspended; otherwise, the thread is not suspended and is eligible for execution. Calling
**SuspendThread** causes the target thread's suspend count to be incremented. Attempting to increment past the maximum suspend count causes an error without incrementing the count.

The
[ResumeThread](https://learn.microsoft.com/windows/desktop/api/processthreadsapi/nf-processthreadsapi-resumethread) function decrements the suspend count of a suspended thread.

**Windows Phone 8.1:** This function is supported for Windows Phone Store apps on Windows Phone 8.1 and later.

**Windows 8.1** and **Windows Server 2012 R2**: This function is supported for Windows Store apps on Windows 8.1, Windows Server 2012 R2, and later.

## See also

[OpenThread](https://learn.microsoft.com/windows/desktop/api/processthreadsapi/nf-processthreadsapi-openthread)

[Process and Thread Functions](https://learn.microsoft.com/windows/desktop/ProcThread/process-and-thread-functions)

[ResumeThread](https://learn.microsoft.com/windows/desktop/api/processthreadsapi/nf-processthreadsapi-resumethread)

[Suspending Thread Execution](https://learn.microsoft.com/windows/desktop/ProcThread/suspending-thread-execution)

[Threads](https://learn.microsoft.com/windows/desktop/ProcThread/multiple-threads)