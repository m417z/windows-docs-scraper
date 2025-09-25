# Wow64SetThreadContext function

## Description

Sets the context of the specified WOW64 thread.

## Parameters

### `hThread` [in]

A handle to the thread whose context is to be set.

### `lpContext` [in]

A [WOW64_CONTEXT](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-wow64_context) structure. The caller must initialize the **ContextFlags** member of this structure.

## Return value

If the function succeeds, the return value is nonzero.

If the function fails, the return value is zero. To get extended error information, call [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

This function allows the selective context to be set based on the value of the **ContextFlags** member of the context structure. The thread handle identified by the *hThread* parameter is typically being debugged, but the function can also operate even when it is not being debugged.

This function is intended for 64-bit applications. It is not supported on 32-bit Windows; such calls fail and set the last error code to **ERROR_INVALID_FUNCTION**. A 32-bit application can call this function on a WOW64 thread; the result is the same as calling the [SetThreadContext](https://learn.microsoft.com/windows/desktop/api/processthreadsapi/nf-processthreadsapi-setthreadcontext) function.

Do not try to set the context for a running thread; the results are unpredictable. Use the [Wow64SuspendThread](https://learn.microsoft.com/windows/win32/api/wow64apiset/nf-wow64apiset-wow64suspendthread) function to suspend the thread before calling **Wow64SetThreadContext**.

## See also

[Debugging Functions](https://learn.microsoft.com/windows/desktop/Debug/debugging-functions)

[GetXStateFeaturesMask](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-getxstatefeaturesmask)

[SetThreadContext](https://learn.microsoft.com/windows/desktop/api/processthreadsapi/nf-processthreadsapi-setthreadcontext)

[SetXStateFeaturesMask](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-setxstatefeaturesmask)

[WOW64_CONTEXT](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-wow64_context)

[Wow64GetThreadContext](https://github.com/MicrosoftDocs/sdk-api/blob/docs/sdk-api-src/content/winbase/nf-winbase-wow64getthreadcontext.md)