# ExitThread function

## Description

Ends the calling thread.

## Parameters

### `dwExitCode` [in]

The exit code for the thread.

## Remarks

**ExitThread** is the preferred method of exiting a thread in C code. However, in C++ code, the thread is exited before any destructors can be called or any other automatic cleanup can be performed. Therefore, in C++ code, you should return from your thread function.

When this function is called (either explicitly or by returning from a thread procedure), the current thread's stack is deallocated, all pending I/O initiated by the thread that is not associated with a completion port is canceled, and the thread terminates. The entry-point function of all attached dynamic-link libraries (DLLs) is invoked with a value indicating that the thread is detaching from the DLL.

If the thread is the last thread in the process when this function is called, the thread's process is also terminated.

The state of the thread object becomes signaled, releasing any other threads that had been waiting for the thread to terminate. The thread's termination status changes from STILL_ACTIVE to the value of the *dwExitCode* parameter.

Terminating a thread does not necessarily remove the thread object from the operating system. A thread object is deleted when the last handle to the thread is closed.

The
[ExitProcess](https://learn.microsoft.com/windows/desktop/api/processthreadsapi/nf-processthreadsapi-exitprocess),
**ExitThread**,
[CreateThread](https://learn.microsoft.com/windows/desktop/api/processthreadsapi/nf-processthreadsapi-createthread),
[CreateRemoteThread](https://learn.microsoft.com/windows/desktop/api/processthreadsapi/nf-processthreadsapi-createremotethread) functions, and a process that is starting (as the result of a
[CreateProcess](https://learn.microsoft.com/windows/desktop/api/processthreadsapi/nf-processthreadsapi-createprocessa) call) are serialized between each other within a process. Only one of these events can happen in an address space at a time. This means the following restrictions hold:

* During process startup and DLL initialization routines, new threads can be created, but they do not begin execution until DLL initialization is done for the process.
* Only one thread in a process can be in a DLL initialization or detach routine at a time.
* [ExitProcess](https://learn.microsoft.com/windows/desktop/api/processthreadsapi/nf-processthreadsapi-exitprocess) does not return until no threads are in their DLL initialization or detach routines.

A thread in an executable that is linked to the static C run-time library (CRT) should use **_beginthread** and **_endthread** for thread management rather than
**CreateThread** and
**ExitThread**. Failure to do so results in small memory leaks when
the thread calls **ExitThread**. Another work around is to link the executable to the CRT in a DLL instead of the static CRT. Note that this memory leak only occurs from a DLL if the DLL is linked to the static CRT and a thread calls the [DisableThreadLibraryCalls](https://learn.microsoft.com/windows/desktop/api/libloaderapi/nf-libloaderapi-disablethreadlibrarycalls) function. Otherwise, it is safe to call **CreateThread** and
**ExitThread** from a thread in a DLL that links to the static CRT.

Use the
[GetExitCodeThread](https://learn.microsoft.com/windows/desktop/api/processthreadsapi/nf-processthreadsapi-getexitcodethread) function to retrieve a thread's exit code.

**Windows Phone 8.1:** This function is supported for Windows Phone Store apps on Windows Phone 8.1 and later.

**Windows 8.1** and **Windows Server 2012 R2**: This function is supported for Windows Store apps on Windows 8.1, Windows Server 2012 R2, and later.

#### Examples

For an example, see
[Using Event Objects](https://learn.microsoft.com/windows/desktop/Sync/using-event-objects).

## See also

[CreateProcess](https://learn.microsoft.com/windows/desktop/api/processthreadsapi/nf-processthreadsapi-createprocessa)

[CreateRemoteThread](https://learn.microsoft.com/windows/desktop/api/processthreadsapi/nf-processthreadsapi-createremotethread)

[CreateThread](https://learn.microsoft.com/windows/desktop/api/processthreadsapi/nf-processthreadsapi-createthread)

[ExitProcess](https://learn.microsoft.com/windows/desktop/api/processthreadsapi/nf-processthreadsapi-exitprocess)

[FreeLibraryAndExitThread](https://learn.microsoft.com/windows/desktop/api/libloaderapi/nf-libloaderapi-freelibraryandexitthread)

[GetExitCodeThread](https://learn.microsoft.com/windows/desktop/api/processthreadsapi/nf-processthreadsapi-getexitcodethread)

[OpenThread](https://learn.microsoft.com/windows/desktop/api/processthreadsapi/nf-processthreadsapi-openthread)

[Process and Thread Functions](https://learn.microsoft.com/windows/desktop/ProcThread/process-and-thread-functions)

[TerminateThread](https://learn.microsoft.com/windows/desktop/api/processthreadsapi/nf-processthreadsapi-terminatethread)

[Threads](https://learn.microsoft.com/windows/desktop/ProcThread/multiple-threads)