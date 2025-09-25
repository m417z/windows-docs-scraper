# GetCurrentThread function

## Description

Retrieves a pseudo handle for the calling thread.

## Return value

The return value is a pseudo handle for the current thread.

## Remarks

A pseudo handle is a special constant that is interpreted as the current thread handle. The calling thread can use this handle to specify itself whenever a thread handle is required. Pseudo handles are not inherited by child processes.

This handle has the **THREAD_ALL_ACCESS** access right to the thread object. For more information, see
[Thread Security and Access Rights](https://learn.microsoft.com/windows/win32/ProcThread/thread-security-and-access-rights).

**Windows Server 2003 and Windows XP:** This handle has the maximum access allowed by the security descriptor of the thread to the primary token of the process.

The function cannot be used by one thread to create a handle that can be used by other threads to refer to the first thread. The handle is always interpreted as referring to the thread that is using it. A thread can create a "real" handle to itself that can be used by other threads, or inherited by other processes, by specifying the pseudo handle as the source handle in a call to the [DuplicateHandle](https://learn.microsoft.com/windows/win32/api/handleapi/nf-handleapi-duplicatehandle) function.

The pseudo handle need not be closed when it is no longer needed. Calling the
[CloseHandle](https://learn.microsoft.com/windows/win32/api/handleapi/nf-handleapi-closehandle) function with this handle has no effect. If the pseudo handle is duplicated by
[DuplicateHandle](https://learn.microsoft.com/windows/win32/api/handleapi/nf-handleapi-duplicatehandle), the duplicate handle must be closed.

Do not create a thread while impersonating a security context. The call will succeed, however the newly created thread will have reduced access rights to itself when calling **GetCurrentThread**. The access rights granted this thread will be derived from the access rights the impersonated user has to the process. Some access rights including **THREAD_SET_THREAD_TOKEN** and **THREAD_GET_CONTEXT** may not be present, leading to unexpected failures.

#### Examples

For an example, see [Checking Client Access](https://learn.microsoft.com/windows/win32/SecAuthZ/verifying-client-access-with-acls-in-c--).

## See also

[CloseHandle](https://learn.microsoft.com/windows/win32/api/handleapi/nf-handleapi-closehandle)

[DuplicateHandle](https://learn.microsoft.com/windows/win32/api/handleapi/nf-handleapi-duplicatehandle)

[GetCurrentProcess](https://learn.microsoft.com/windows/win32/api/processthreadsapi/nf-processthreadsapi-getcurrentprocess)

[GetCurrentThreadId](https://learn.microsoft.com/windows/win32/api/processthreadsapi/nf-processthreadsapi-getcurrentthreadid)

[OpenThread](https://learn.microsoft.com/windows/win32/api/processthreadsapi/nf-processthreadsapi-openthread)

[Process and Thread Functions](https://learn.microsoft.com/windows/win32/ProcThread/process-and-thread-functions)

[Threads](https://learn.microsoft.com/windows/win32/ProcThread/multiple-threads)

[Vertdll APIs available in VBS enclaves](https://learn.microsoft.com/windows/win32/trusted-execution/enclaves-available-in-vertdll)