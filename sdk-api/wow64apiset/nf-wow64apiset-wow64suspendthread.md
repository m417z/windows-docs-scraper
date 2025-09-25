# Wow64SuspendThread function

## Description

Suspends the specified WOW64 thread.

## Parameters

### `hThread`

A handle to the thread that is to be suspended. The handle must have the THREAD_SUSPEND_RESUME access right. For more information, see [Thread Security and Access Rights](https://learn.microsoft.com/windows/win32/procthread/thread-security-and-access-rights).

## Return value

If the function succeeds, the return value is the thread's previous suspend count; otherwise, it is (DWORD) -1. To get extended error information, use the [GetLastError](https://learn.microsoft.com/windows/win32/api/errhandlingapi/nf-errhandlingapi-getlasterror) function.

## Remarks

If the function succeeds, execution of the specified thread is suspended and the thread's suspend count is incremented. Suspending a thread causes the thread to stop executing user-mode (application) code.

This function is primarily designed for use by debuggers. It is not intended to be used for thread synchronization. Calling **Wow64SuspendThread** on a thread that owns a synchronization object, such as a mutex or critical section, can lead to a deadlock if the calling thread tries to obtain a synchronization object owned by a suspended thread. To avoid this situation, a thread within an application that is not a debugger should signal the other thread to suspend itself. The target thread must be designed to watch for this signal and respond appropriately.

Each thread has a suspend count (with a maximum value of MAXIMUM_SUSPEND_COUNT). If the suspend count is greater than zero, the thread is suspended; otherwise, the thread is not suspended and is eligible for execution. Calling
**Wow64SuspendThread** causes the target thread's suspend count to be incremented. Attempting to increment past the maximum suspend count causes an error without incrementing the count.

The [ResumeThread](https://learn.microsoft.com/windows/win32/api/processthreadsapi/nf-processthreadsapi-resumethread) function decrements the suspend count of a suspended thread.

This function is intended for 64-bit applications. It is not supported on 32-bit Windows; such calls fail and set the last error code to ERROR_INVALID_FUNCTION. A 32-bit application can call this function on a WOW64 thread; the result is the same as calling the [SuspendThread](https://learn.microsoft.com/windows/win32/api/processthreadsapi/nf-processthreadsapi-suspendthread) function.

## See also

[ResumeThread](https://learn.microsoft.com/windows/win32/api/processthreadsapi/nf-processthreadsapi-resumethread)