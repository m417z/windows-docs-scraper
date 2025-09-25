# CreateRemoteThreadEx function

## Description

Creates a thread that runs in the virtual address space of another process and optionally specifies extended attributes such as processor group affinity.

## Parameters

### `hProcess` [in]

A handle to the process in which the thread is to be created. The handle must have the PROCESS_CREATE_THREAD, PROCESS_QUERY_INFORMATION, PROCESS_VM_OPERATION, PROCESS_VM_WRITE, and PROCESS_VM_READ access rights. In Windows 10, version 1607, your code must obtain these access rights for the new handle. However, starting in Windows 10, version 1703, if the new handle is entitled to these access rights, the system obtains them for you. For more information, see
[Process Security and Access Rights](https://learn.microsoft.com/windows/desktop/ProcThread/process-security-and-access-rights).

### `lpThreadAttributes` [in, optional]

A pointer to a [SECURITY_ATTRIBUTES](https://learn.microsoft.com/windows/win32/api/wtypesbase/ns-wtypesbase-security_attributes) structure that specifies a security descriptor for the new thread and determines whether child processes can inherit the returned handle. If *lpThreadAttributes* is NULL, the thread gets a default security descriptor and the handle cannot be inherited. The access control lists (ACL) in the default security descriptor for a thread come from the primary token of the creator.

### `dwStackSize` [in]

The initial size of the stack, in bytes. The system rounds this value to the nearest page. If this parameter is 0 (zero), the new thread uses the default size for the executable. For more information, see
[Thread Stack Size](https://learn.microsoft.com/windows/desktop/ProcThread/thread-stack-size).

### `lpStartAddress` [in]

A pointer to the application-defined function of type **LPTHREAD_START_ROUTINE** to be executed by the thread and represents the starting address of the thread in the remote process. The function must exist in the remote process. For more information, see
[ThreadProc](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/ms686736(v=vs.85)).

### `lpParameter` [in, optional]

A pointer to a variable to be passed to the thread function pointed to by *lpStartAddress*. This parameter can be NULL.

### `dwCreationFlags` [in]

The flags that control the creation of the thread.

| Value | Meaning |
| --- | --- |
| 0 | The thread runs immediately after creation. |
| **CREATE_SUSPENDED**<br><br>0x00000004 | The thread is created in a suspended state and does not run until the [ResumeThread](https://learn.microsoft.com/windows/desktop/api/processthreadsapi/nf-processthreadsapi-resumethread) function is called. |
| **STACK_SIZE_PARAM_IS_A_RESERVATION**<br><br>0x00010000 | The *dwStackSize* parameter specifies the initial reserve size of the stack. If this flag is not specified, *dwStackSize* specifies the commit size. |

### `lpAttributeList` [in, optional]

An attribute list that contains additional parameters for the new thread. This list is created by the [InitializeProcThreadAttributeList](https://learn.microsoft.com/windows/desktop/api/processthreadsapi/nf-processthreadsapi-initializeprocthreadattributelist) function.

### `lpThreadId` [out, optional]

A pointer to a variable that receives the thread identifier.

If this parameter is NULL, the thread identifier is not returned.

## Return value

If the function succeeds, the return value is a handle to the new thread.

If the function fails, the return value is NULL. To get extended error information, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

The
**CreateRemoteThreadEx** function causes a new thread of execution to begin in the address space of the specified process. The thread has access to all objects that the process opens. The *lpAttribute* parameter can be used to specify extended attributes such as processor group affinity for the new thread. If *lpAttribute* is NULL, the function's behavior is the same as [CreateRemoteThread](https://learn.microsoft.com/windows/desktop/api/processthreadsapi/nf-processthreadsapi-createremotethread).

Prior to Windows 8, Terminal Services isolates each terminal session by design. Therefore,
[CreateRemoteThread](https://learn.microsoft.com/windows/desktop/api/processthreadsapi/nf-processthreadsapi-createremotethread) fails if the target process is in a different session than the calling process.

The new thread handle is created with full access to the new thread. If a security descriptor is not provided, the handle may be used in any function that requires a thread object handle. When a security descriptor is provided, an access check is performed on all subsequent uses of the handle before access is granted. If the access check denies access, the requesting process cannot use the handle to gain access to the thread.

 If the thread is created in a runnable state (that is, if the CREATE_SUSPENDED flag is not used), the thread can start running before [CreateThread](https://learn.microsoft.com/windows/desktop/api/processthreadsapi/nf-processthreadsapi-createthread) returns and, in particular, before the caller receives the handle and identifier of the created thread.

The thread is created with a thread priority of THREAD_PRIORITY_NORMAL. To get and set the priority value of a thread, use the
[GetThreadPriority](https://learn.microsoft.com/windows/desktop/api/processthreadsapi/nf-processthreadsapi-getthreadpriority) and
[SetThreadPriority](https://learn.microsoft.com/windows/desktop/api/processthreadsapi/nf-processthreadsapi-setthreadpriority) functions.

When a thread terminates, the thread object attains a signaled state, which satisfies the threads that are waiting for the object.

The thread object remains in the system until the thread has terminated and all handles to it are closed through a call to
[CloseHandle](https://learn.microsoft.com/windows/desktop/api/handleapi/nf-handleapi-closehandle).

The
[ExitProcess](https://learn.microsoft.com/windows/desktop/api/processthreadsapi/nf-processthreadsapi-exitprocess),
[ExitThread](https://learn.microsoft.com/windows/desktop/api/processthreadsapi/nf-processthreadsapi-exitthread),
[CreateThread](https://learn.microsoft.com/windows/desktop/api/processthreadsapi/nf-processthreadsapi-createthread),
[CreateRemoteThread](https://learn.microsoft.com/windows/desktop/api/processthreadsapi/nf-processthreadsapi-createremotethread) functions, and a process that is starting (as the result of a
[CreateProcess](https://learn.microsoft.com/windows/desktop/api/processthreadsapi/nf-processthreadsapi-createprocessa) call) are serialized between each other within a process. Only one of these events occurs in an address space at a time. This means the following restrictions hold:

* During process startup and DLL initialization routines, new threads can be created, but they do not begin execution until DLL initialization is done for the process.
* Only one thread in a process can be in a DLL initialization or detach routine at a time.
* [ExitProcess](https://learn.microsoft.com/windows/desktop/api/processthreadsapi/nf-processthreadsapi-exitprocess) returns after all threads have completed their DLL initialization or detach routines.

A common use of this function is to inject a thread into a process that is being debugged to issue a break. However, this use is not recommended, because the extra thread is confusing to the person debugging the application and there are several side effects to using this technique:

* It converts single-threaded applications into multithreaded applications.
* It changes the timing and memory layout of the process.
* It results in a call to the entry point of each DLL in the process.

Another common use of this function is to inject a thread into a process to query heap or other process information. This can cause the same side effects mentioned in the previous paragraph. Also, the application can deadlock if the thread attempts to obtain ownership of locks that another thread is using.

## See also

[CreateRemoteThread](https://learn.microsoft.com/windows/desktop/api/processthreadsapi/nf-processthreadsapi-createremotethread)