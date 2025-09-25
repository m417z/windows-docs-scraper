# OpenThread function

## Description

Opens an existing thread object.

## Parameters

### `dwDesiredAccess` [in]

The access to the thread object. This access right is checked against the security descriptor for the thread. This parameter can be one or more of the
[thread access rights](https://learn.microsoft.com/windows/desktop/ProcThread/thread-security-and-access-rights).

If the caller has enabled the SeDebugPrivilege privilege, the requested access is granted regardless of the contents of the security descriptor.

### `bInheritHandle` [in]

If this value is TRUE, processes created by this process will inherit the handle. Otherwise, the processes do not inherit this handle.

### `dwThreadId` [in]

The identifier of the thread to be opened.

## Return value

If the function succeeds, the return value is an open handle to the specified thread.

If the function fails, the return value is NULL. To get extended error information, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

The handle returned by
**OpenThread** can be used in any function that requires a handle to a thread, such as the
[wait functions](https://learn.microsoft.com/windows/desktop/Sync/wait-functions), provided you requested the appropriate access rights. The handle is granted access to the thread object only to the extent it was specified in the *dwDesiredAccess* parameter.

When you are finished with the handle, be sure to close it by using the
[CloseHandle](https://learn.microsoft.com/windows/desktop/api/handleapi/nf-handleapi-closehandle) function.

## See also

[CloseHandle](https://learn.microsoft.com/windows/desktop/api/handleapi/nf-handleapi-closehandle)

[GetExitCodeThread](https://learn.microsoft.com/windows/desktop/api/processthreadsapi/nf-processthreadsapi-getexitcodethread)

[GetThreadContext](https://learn.microsoft.com/windows/desktop/api/processthreadsapi/nf-processthreadsapi-getthreadcontext)

[Process and Thread Functions](https://learn.microsoft.com/windows/desktop/ProcThread/process-and-thread-functions)

[ResumeThread](https://learn.microsoft.com/windows/desktop/api/processthreadsapi/nf-processthreadsapi-resumethread)

[SetThreadContext](https://learn.microsoft.com/windows/desktop/api/processthreadsapi/nf-processthreadsapi-setthreadcontext)

[SetTokenInformation](https://learn.microsoft.com/windows/desktop/api/securitybaseapi/nf-securitybaseapi-settokeninformation)

[SuspendThread](https://learn.microsoft.com/windows/desktop/api/processthreadsapi/nf-processthreadsapi-suspendthread)

[TerminateThread](https://learn.microsoft.com/windows/desktop/api/processthreadsapi/nf-processthreadsapi-terminatethread)

[Threads](https://learn.microsoft.com/windows/desktop/ProcThread/multiple-threads)