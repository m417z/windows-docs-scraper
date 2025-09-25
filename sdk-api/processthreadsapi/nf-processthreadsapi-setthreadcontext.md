# SetThreadContext function

## Description

Sets the context for the specified thread.

> [!NOTE]
> A 64-bit application can set the context of a WOW64 thread using the [Wow64SetThreadContext function](https://learn.microsoft.com/windows/win32/api/wow64apiset/nf-wow64apiset-wow64setthreadcontext).

## Parameters

### `hThread` [in]

A handle to the thread whose context is to be set. The handle must have the **THREAD_SET_CONTEXT** access right to the thread. For more information, see [Thread Security and Access Rights](https://learn.microsoft.com/windows/desktop/ProcThread/thread-security-and-access-rights).

### `lpContext` [in]

A pointer to a [CONTEXT](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-arm64_nt_context) structure that contains the context to be set in the specified thread. The value of the **ContextFlags** member of this structure specifies which portions of a thread's context to set. Some values in the **CONTEXT** structure that cannot be specified are silently set to the correct value. This includes bits in the CPU status register that specify the privileged processor mode, global enabling bits in the debugging register, and other states that must be controlled by the operating system.

## Return value

If the context was set, the return value is nonzero.

If the function fails, the return value is zero. To get extended error information, call [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

The function sets the thread context based on the value of the **ContextFlags** member of the context structure. The thread identified by the *hThread* parameter is typically being debugged, but the function can also operate even when the thread is not being debugged.

Do not try to set the context for a running thread; the results are unpredictable. Use the [SuspendThread](https://learn.microsoft.com/windows/desktop/api/processthreadsapi/nf-processthreadsapi-suspendthread) function to suspend the thread before calling **SetThreadContext**.

## See also

[CONTEXT](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-arm64_nt_context)

[Debugging Functions](https://learn.microsoft.com/windows/desktop/Debug/debugging-functions)

[GetThreadContext](https://learn.microsoft.com/windows/desktop/api/processthreadsapi/nf-processthreadsapi-getthreadcontext)

[GetXStateFeaturesMask](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-getxstatefeaturesmask)

[SetXStateFeaturesMask](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-setxstatefeaturesmask)

[SuspendThread](https://learn.microsoft.com/windows/desktop/api/processthreadsapi/nf-processthreadsapi-suspendthread)