# CreateThread function

## Description

Creates a thread to execute within the virtual address space of the calling process.

To create a thread that runs in the virtual address space of another process, use the
[CreateRemoteThread](https://learn.microsoft.com/windows/desktop/api/processthreadsapi/nf-processthreadsapi-createremotethread) function.

## Parameters

### `lpThreadAttributes` [in, optional]

A pointer to a [SECURITY_ATTRIBUTES](https://learn.microsoft.com/windows/win32/api/wtypesbase/ns-wtypesbase-security_attributes) structure that specifies a security descriptor for the new thread and determines whether child processes can inherit the returned handle. If *lpThreadAttributes* is NULL, the thread gets a default security descriptor and the handle cannot be inherited. The access control lists (ACL) in the default security descriptor for a thread come from the primary token of the creator.

### `dwStackSize` [in]

The initial size of the stack, in bytes. The system rounds this value to the nearest page. If this parameter is zero, the new thread uses the default size for the executable. For more information, see
[Thread Stack Size](https://learn.microsoft.com/windows/desktop/ProcThread/thread-stack-size).

### `lpStartAddress` [in]

A pointer to the application-defined function to be executed by the thread. This pointer represents the starting address of the thread. For more information on the thread function, see
[ThreadProc](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/ms686736(v=vs.85)).

### `lpParameter` [in, optional]

A pointer to a variable to be passed to the thread.

### `dwCreationFlags` [in]

The flags that control the creation of the thread.

| Value | Meaning |
| --- | --- |
| 0 | The thread runs immediately after creation. |
| **CREATE_SUSPENDED**<br><br>0x00000004 | The thread is created in a suspended state, and does not run until the [ResumeThread](https://learn.microsoft.com/windows/desktop/api/processthreadsapi/nf-processthreadsapi-resumethread) function is called. |
| **STACK_SIZE_PARAM_IS_A_RESERVATION**<br><br>0x00010000 | The *dwStackSize* parameter specifies the initial reserve size of the stack. If this flag is not specified, *dwStackSize* specifies the commit size. |

### `lpThreadId` [out, optional]

A pointer to a variable that receives the thread identifier. If this parameter is
**NULL**, the thread identifier is not returned.

## Return value

If the function succeeds, the return value is a handle to the new thread.

If the function fails, the return value is **NULL**. To get extended error information, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

Note that **CreateThread** may succeed even if
*lpStartAddress* points to data, code, or is not accessible. If the start address is
invalid when the thread runs, an exception occurs, and the thread terminates. Thread termination due to a
invalid start address is handled as an error exit for the thread's process. This behavior is similar to the
asynchronous nature of [CreateProcess](https://learn.microsoft.com/windows/desktop/api/processthreadsapi/nf-processthreadsapi-createprocessa), where the
process is created even if it refers to invalid or missing dynamic-link libraries (DLLs).

## Remarks

The number of threads a process can create is limited by the available virtual memory. By default, every thread has one megabyte of stack space. Therefore, you cannot create 2,048 or more threads on a 32-bit system without `/3GB` boot.ini option. If you reduce the default stack size, you can create more threads. However, your application will have better performance if you create one thread per processor and build queues of requests for which the application maintains the context information. A thread would process all requests in a queue before processing requests in the next queue.

The new thread handle is created with the **THREAD_ALL_ACCESS** access right. If a security descriptor is not provided when the thread is created, a default security descriptor is constructed for the new thread using the primary token of the process that is creating the thread. When a caller attempts to access the thread with the [OpenThread](https://learn.microsoft.com/windows/desktop/api/processthreadsapi/nf-processthreadsapi-openthread) function, the effective token of the caller is evaluated against this security descriptor to grant or deny access.

 The newly created thread has full access rights to itself when calling the [GetCurrentThread](https://learn.microsoft.com/windows/desktop/api/processthreadsapi/nf-processthreadsapi-getcurrentthread) function.

**Windows Server 2003:** The thread's access rights to itself are computed by evaluating the primary token of the process in which the thread was created against the default security descriptor constructed for the thread. If the thread is created in a remote process, the primary token of the remote process is used. As a result, the newly created thread may have reduced access rights to itself when calling [GetCurrentThread](https://learn.microsoft.com/windows/desktop/api/processthreadsapi/nf-processthreadsapi-getcurrentthread). Some access rights including **THREAD_SET_THREAD_TOKEN** and **THREAD_GET_CONTEXT** may not be present, leading to unexpected failures. For this reason, creating a thread while impersonating another user is not recommended.

 If the thread is created in a runnable state (that is, if the **CREATE_SUSPENDED** flag is not used), the thread can start running before **CreateThread** returns and, in particular, before the caller receives the handle and identifier of the created thread.

The thread execution begins at the function specified by the *lpStartAddress* parameter. If this function returns, the **DWORD** return value is used to terminate the thread in an implicit call to the
[ExitThread](https://learn.microsoft.com/windows/desktop/api/processthreadsapi/nf-processthreadsapi-exitthread) function. Use the
[GetExitCodeThread](https://learn.microsoft.com/windows/desktop/api/processthreadsapi/nf-processthreadsapi-getexitcodethread) function to get the thread's return value.

The thread is created with a thread priority of **THREAD_PRIORITY_NORMAL**. Use the
[GetThreadPriority](https://learn.microsoft.com/windows/desktop/api/processthreadsapi/nf-processthreadsapi-getthreadpriority) and
[SetThreadPriority](https://learn.microsoft.com/windows/desktop/api/processthreadsapi/nf-processthreadsapi-setthreadpriority) functions to get and set the priority value of a thread.

When a thread terminates, the thread object attains a signaled state, satisfying any threads that were waiting on the object.

The thread object remains in the system until the thread has terminated and all handles to it have been closed through a call to
[CloseHandle](https://learn.microsoft.com/windows/desktop/api/handleapi/nf-handleapi-closehandle).

The
[ExitProcess](https://learn.microsoft.com/windows/desktop/api/processthreadsapi/nf-processthreadsapi-exitprocess),
[ExitThread](https://learn.microsoft.com/windows/desktop/api/processthreadsapi/nf-processthreadsapi-exitthread),
**CreateThread**,
[CreateRemoteThread](https://learn.microsoft.com/windows/desktop/api/processthreadsapi/nf-processthreadsapi-createremotethread) functions, and a process that is starting (as the result of a call by
[CreateProcess](https://learn.microsoft.com/windows/desktop/api/processthreadsapi/nf-processthreadsapi-createprocessa)) are serialized between each other within a process. Only one of these events can happen in an address space at a time. This means that the following restrictions hold:

* During process startup and DLL initialization routines, new threads can be created, but they do not begin execution until DLL initialization is done for the process.
* Only one thread in a process can be in a DLL initialization or detach routine at a time.
* [ExitProcess](https://learn.microsoft.com/windows/desktop/api/processthreadsapi/nf-processthreadsapi-exitprocess) does not complete until there are no threads in their DLL initialization or detach routines.

A thread in an executable that calls the C run-time library (CRT) should use the [_beginthreadex](https://learn.microsoft.com/cpp/c-runtime-library/reference/beginthread-beginthreadex) and [_endthreadex](https://learn.microsoft.com/cpp/c-runtime-library/reference/endthread-endthreadex) functions for thread management rather than
**CreateThread** and
[ExitThread](https://learn.microsoft.com/windows/desktop/api/processthreadsapi/nf-processthreadsapi-exitthread); this requires the use of the multithreaded version of the CRT. If a thread created using **CreateThread** calls the CRT, the CRT may terminate the process in low-memory conditions.

**Windows Phone 8.1:** This function is supported for Windows Phone Store apps on Windows Phone 8.1 and later.

**Windows 8.1** and **Windows Server 2012 R2**: This function is supported for Windows Store apps on Windows 8.1, Windows Server 2012 R2, and later.

#### Examples

For an example, see
[Creating Threads](https://learn.microsoft.com/windows/desktop/ProcThread/creating-threads).

## See also

[CloseHandle](https://learn.microsoft.com/windows/desktop/api/handleapi/nf-handleapi-closehandle)

[CreateProcess](https://learn.microsoft.com/windows/desktop/api/processthreadsapi/nf-processthreadsapi-createprocessa)

[CreateRemoteThread](https://learn.microsoft.com/windows/desktop/api/processthreadsapi/nf-processthreadsapi-createremotethread)

[ExitProcess](https://learn.microsoft.com/windows/desktop/api/processthreadsapi/nf-processthreadsapi-exitprocess)

[ExitThread](https://learn.microsoft.com/windows/desktop/api/processthreadsapi/nf-processthreadsapi-exitthread)

[GetExitCodeThread](https://learn.microsoft.com/windows/desktop/api/processthreadsapi/nf-processthreadsapi-getexitcodethread)

[GetThreadPriority](https://learn.microsoft.com/windows/desktop/api/processthreadsapi/nf-processthreadsapi-getthreadpriority)

[Process and Thread Functions](https://learn.microsoft.com/windows/desktop/ProcThread/process-and-thread-functions)

[ResumeThread](https://learn.microsoft.com/windows/desktop/api/processthreadsapi/nf-processthreadsapi-resumethread)

[SECURITY_ATTRIBUTES](https://learn.microsoft.com/windows/win32/api/wtypesbase/ns-wtypesbase-security_attributes)

[SetThreadPriority](https://learn.microsoft.com/windows/desktop/api/processthreadsapi/nf-processthreadsapi-setthreadpriority)

[SuspendThread](https://learn.microsoft.com/windows/desktop/api/processthreadsapi/nf-processthreadsapi-suspendthread)

[ThreadProc](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/ms686736(v=vs.85))

[Threads](https://learn.microsoft.com/windows/desktop/ProcThread/multiple-threads)