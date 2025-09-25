# GetThreadContext function

## Description

Retrieves the context of the specified thread.

> [!NOTE]
> A 64-bit application can retrieve the context of a WOW64 thread using the [Wow64GetThreadContext function](https://learn.microsoft.com/windows/win32/api/wow64apiset/nf-wow64apiset-wow64getthreadcontext).

## Parameters

### `hThread` [in]

A handle to the thread whose context is to be retrieved. The handle must have **THREAD_GET_CONTEXT** access to the thread. For more information, see [Thread Security and Access Rights](https://learn.microsoft.com/windows/desktop/ProcThread/thread-security-and-access-rights).

**Windows XP or Windows Server 2003:** The handle must also have **THREAD_QUERY_INFORMATION** access.

### `lpContext` [in, out]

A pointer to a [CONTEXT](https://learn.microsoft.com/windows/win32/api/winnt/ns-winnt-context) structure (such as [ARM64_NT_CONTEXT](https://learn.microsoft.com/windows/win32/api/winnt/ns-winnt-arm64_nt_context)) that receives the appropriate context of the specified thread. The value of the **ContextFlags** member of this structure specifies which portions of a thread's context are retrieved. The **CONTEXT** structure is highly processor specific. Refer to the WinNT.h header file for processor-specific definitions of this structures and any alignment requirements.

## Return value

If the function succeeds, the return value is nonzero.

If the function fails, the return value is zero. To get extended error information, call [GetLastError](https://learn.microsoft.com/windows/win32/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

This function is used to retrieve the thread context of the specified thread. The function retrieves a selective context based on the value of the **ContextFlags** member of the context structure. The thread identified by the *hThread* parameter is typically being debugged, but the function can also operate when the thread is not being debugged.

You cannot get a valid context for a running thread. Use the [SuspendThread](https://learn.microsoft.com/windows/win32/api/processthreadsapi/nf-processthreadsapi-suspendthread) function to suspend the thread before calling **GetThreadContext**.

If you call **GetThreadContext** for the current thread, the function returns successfully; however, the context returned is not valid.

## See also

- [CONTEXT](https://learn.microsoft.com/windows/win32/api/winnt/ns-winnt-context)
- [ARM64_NT_CONTEXT](https://learn.microsoft.com/windows/win32/api/winnt/ns-winnt-arm64_nt_context)
- [Debugging Functions](https://learn.microsoft.com/windows/desktop/Debug/debugging-functions)
- [GetXStateFeaturesMask](https://learn.microsoft.com/windows/win32/api/winbase/nf-winbase-getxstatefeaturesmask)
- [SetThreadContext](https://learn.microsoft.com/windows/win32/api/processthreadsapi/nf-processthreadsapi-setthreadcontext)
- [SuspendThread](https://learn.microsoft.com/windows/win32/api/processthreadsapi/nf-processthreadsapi-suspendthread)
- [Wow64GetThreadContext](https://learn.microsoft.com/windows/win32/api/wow64apiset/nf-wow64apiset-wow64getthreadcontext)