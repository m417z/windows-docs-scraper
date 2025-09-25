# DeleteUmsThreadContext function

## Description

Deletes the specified user-mode scheduling (UMS) thread context. The thread must be terminated.

> [!WARNING]
> As of Windows 11, user-mode scheduling is not supported. All calls fail with the error `ERROR_NOT_SUPPORTED`.

## Parameters

### `UmsThread` [in]

A pointer to the UMS thread context to be deleted. The [CreateUmsThreadContext](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-createumsthreadcontext) function provides this pointer.

## Return value

If the function succeeds, it returns a nonzero value.

If the function fails, the return value is zero. To get extended error information, call [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

A UMS thread context cannot be deleted until the associated thread has terminated.

When a UMS worker thread finishes running (for example, by returning from its thread entry point function), the system terminates the thread, sets the termination status in the thread's UMS thread context, and queues the UMS thread context to the associated completion list.

 Any attempt to execute the UMS thread will fail because the thread is already terminated.

To check the termination status of a thread, the application's scheduler should call [QueryUmsThreadInformation](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-queryumsthreadinformation) with the **UmsIsThreadTerminated** information class.

## See also

[CreateUmsThreadContext](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-createumsthreadcontext)

[QueryUmsThreadInformation](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-queryumsthreadinformation)