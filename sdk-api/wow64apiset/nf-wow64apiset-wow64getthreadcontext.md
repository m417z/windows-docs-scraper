# Wow64GetThreadContext function

## Description

Retrieves the context of the specified WOW64 thread.

## Parameters

### `hThread` [in]

A handle to the thread whose context is to be retrieved. The handle must have **THREAD_GET_CONTEXT** access to the thread. For more information, see [Thread Security and Access Rights](https://learn.microsoft.com/windows/desktop/ProcThread/thread-security-and-access-rights).

### `lpContext` [in, out]

A [WOW64_CONTEXT](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-wow64_context) structure. The caller must initialize the **ContextFlags** member of this structure.

## Return value

If the function succeeds, the return value is nonzero.

If the function fails, the return value is zero. To get extended error information, call [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

This function is used to retrieve the thread context of the specified thread. The function retrieves a selective context based on the value of the **ContextFlags** member of the context structure. The thread identified by the *hThread* parameter is typically being debugged, but the function can also operate when the thread is not being debugged.

You cannot get a valid context for a running thread. Use the [Wow64SuspendThread](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-wow64suspendthread) function to suspend the thread before calling **Wow64GetThreadContext**.

If you call **Wow64GetThreadContext** for the current thread, the function returns successfully; however, the context returned is not valid.

This function is intended for 64-bit applications. It is not supported on 32-bit Windows; such calls fail and set the last error code to **ERROR_INVALID_FUNCTION**. A 32-bit application can call this function on a WOW64 thread; the result is the same as calling the [GetThreadContext function](https://learn.microsoft.com/windows/win32/api/processthreadsapi/nf-processthreadsapi-getthreadcontext) function.

## See also

[Debugging Functions](https://learn.microsoft.com/windows/desktop/Debug/debugging-functions)

[GetThreadContext function](https://learn.microsoft.com/windows/win32/api/processthreadsapi/nf-processthreadsapi-getthreadcontext)

[GetXStateFeaturesMask](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-getxstatefeaturesmask)

[WOW64_CONTEXT](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-wow64_context)

[Wow64SetThreadContext](https://learn.microsoft.com/windows/win32/api/wow64apiset/)