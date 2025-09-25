# TerminateThread function

## Description

Terminates a thread.

## Parameters

### `hThread` [in, out]

A handle to the thread to be terminated.

The handle must have the **THREAD_TERMINATE** access right. For more information, see
[Thread Security and Access Rights](https://learn.microsoft.com/windows/desktop/ProcThread/thread-security-and-access-rights).

### `dwExitCode` [in]

The exit code for the thread. Use the
[GetExitCodeThread](https://learn.microsoft.com/windows/desktop/api/processthreadsapi/nf-processthreadsapi-getexitcodethread) function to retrieve a thread's exit value.

## Return value

If the function succeeds, the return value is nonzero.

If the function fails, the return value is zero. To get extended error information, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

**TerminateThread** is used to cause a thread to exit. When this occurs, the target thread has no chance to execute any user-mode code. DLLs attached to the thread are not notified that the thread is terminating. The system frees the thread's initial stack.

**Windows Server 2003 and Windows XP:** The target thread's initial stack is not freed, causing a resource leak.

**TerminateThread** is a dangerous function that should only be used in the most extreme cases. You should call
**TerminateThread** only if you know exactly what the target thread is doing, and you control all of the code that the target thread could possibly be running at the time of the termination. For example,
**TerminateThread** can result in the following problems:

* If the target thread owns a critical section, the critical section will not be released.
* If the target thread is allocating memory from the heap, the heap lock will not be released.
* If the target thread is executing certain kernel32 calls when it is terminated, the kernel32 state for the thread's process could be inconsistent.
* If the target thread is manipulating the global state of a shared DLL, the state of the DLL could be destroyed, affecting other users of the DLL.

A thread cannot protect itself against
**TerminateThread**, other than by controlling access to its handles. The thread handle returned by the
[CreateThread](https://learn.microsoft.com/windows/desktop/api/processthreadsapi/nf-processthreadsapi-createthread) and
[CreateProcess](https://learn.microsoft.com/windows/desktop/api/processthreadsapi/nf-processthreadsapi-createprocessa) functions has **THREAD_TERMINATE** access, so any caller holding one of these handles can terminate your thread.

If the target thread is the last thread of a process when this function is called, the thread's process is also terminated.

The state of the thread object becomes signaled, releasing any other threads that had been waiting for the thread to terminate. The thread's termination status changes from **STILL_ACTIVE** to the value of the *dwExitCode* parameter.

Terminating a thread does not necessarily remove the thread object from the system. A thread object is deleted when the last thread handle is closed.

## See also

[CreateProcess](https://learn.microsoft.com/windows/desktop/api/processthreadsapi/nf-processthreadsapi-createprocessa)

[CreateThread](https://learn.microsoft.com/windows/desktop/api/processthreadsapi/nf-processthreadsapi-createthread)

[ExitThread](https://learn.microsoft.com/windows/desktop/api/processthreadsapi/nf-processthreadsapi-exitthread)

[GetExitCodeThread](https://learn.microsoft.com/windows/desktop/api/processthreadsapi/nf-processthreadsapi-getexitcodethread)

[OpenThread](https://learn.microsoft.com/windows/desktop/api/processthreadsapi/nf-processthreadsapi-openthread)

[Process and Thread Functions](https://learn.microsoft.com/windows/desktop/ProcThread/process-and-thread-functions)

[Terminating a Thread](https://learn.microsoft.com/windows/desktop/ProcThread/terminating-a-thread)

[Threads](https://learn.microsoft.com/windows/desktop/ProcThread/multiple-threads)