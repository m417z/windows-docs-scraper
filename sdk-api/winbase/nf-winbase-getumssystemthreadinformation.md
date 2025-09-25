# GetUmsSystemThreadInformation function

## Description

Queries whether the specified thread is a UMS scheduler thread, a UMS worker thread, or a non-UMS thread.

> [!WARNING]
> As of Windows 11, user-mode scheduling is not supported. All calls fail with the error `ERROR_NOT_SUPPORTED`.

## Parameters

### `ThreadHandle` [in]

A handle to a thread. The thread handle must have the THREAD_QUERY_INFORMATION access right. For more information, see [Thread Security and Access Rights](https://learn.microsoft.com/windows/desktop/ProcThread/thread-security-and-access-rights).

### `SystemThreadInfo` [in, out]

A pointer to a [UMS_SYSTEM_THREAD_INFORMATION](https://learn.microsoft.com/windows/desktop/api/winbase/ns-winbase-ums_system_thread_information) structure that receives information about the specified thread.

The caller must initialize the `UmsVersion` member before calling.

## Return value

If the function fails, the return value is zero.

To get extended error information, call [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

The **GetUmsSystemThreadInformation** function is intended for use in debuggers, troubleshooting tools, and profiling applications. For example, thread-isolated tracing or single-stepping through instructions might involve suspending all other threads in the process. However, if the thread to be traced is a UMS worker thread, suspending UMS scheduler threads might cause a deadlock because a UMS worker thread requires the intervention of a UMS scheduler thread in order to run. A debugger can call **GetUmsSystemThreadInformation** for each thread that it might suspend to determine the kind of thread, and then suspend it or not as needed for the code being debugged.