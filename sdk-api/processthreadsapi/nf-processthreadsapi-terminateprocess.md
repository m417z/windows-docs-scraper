# TerminateProcess function

## Description

Terminates the specified process and all of its threads.

## Parameters

### `hProcess` [in]

A handle to the process to be terminated.

The handle must have the **PROCESS_TERMINATE** access right. For more information, see [Process Security and Access Rights](https://learn.microsoft.com/windows/win32/ProcThread/process-security-and-access-rights).

### `uExitCode` [in]

The exit code to be used by the process and threads terminated as a result of this call. Use the [GetExitCodeProcess](https://learn.microsoft.com/windows/win32/api/processthreadsapi/nf-processthreadsapi-getexitcodeprocess) function to retrieve a process's exit value. Use the [GetExitCodeThread](https://learn.microsoft.com/windows/win32/api/processthreadsapi/nf-processthreadsapi-getexitcodethread) function to retrieve a thread's exit value.

## Return value

If the function succeeds, the return value is nonzero.

If the function fails, the return value is zero. To get extended error information, call [GetLastError](https://learn.microsoft.com/windows/win32/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

The **TerminateProcess** function is used to unconditionally cause a process to exit. The state of global data maintained by dynamic-link libraries (DLLs) may be compromised if **TerminateProcess** is used rather than [ExitProcess](https://learn.microsoft.com/windows/win32/api/processthreadsapi/nf-processthreadsapi-exitprocess).

This function stops execution of all threads within the process and requests cancellation of all pending I/O. The terminated process cannot exit until all pending I/O has been completed or canceled. When a process terminates, its kernel object is not destroyed until all processes that have open handles to the process have released those handles.

When a process terminates itself, **TerminateProcess** stops execution of the calling thread and does not return. Otherwise, **TerminateProcess** is asynchronous; it initiates termination and returns immediately. If you need to be sure the process has terminated, call the [WaitForSingleObject](https://learn.microsoft.com/windows/win32/api/synchapi/nf-synchapi-waitforsingleobject) function with a handle to the process.

A process cannot prevent itself from being terminated.

After a process has terminated, call to **TerminateProcess** with open handles to the process fails with **ERROR_ACCESS_DENIED** (5) error code.

## See also

[ExitProcess](https://learn.microsoft.com/windows/win32/api/processthreadsapi/nf-processthreadsapi-exitprocess)

[GetExitCodeProcess](https://learn.microsoft.com/windows/win32/api/processthreadsapi/nf-processthreadsapi-getexitcodeprocess)

[GetExitCodeThread](https://learn.microsoft.com/windows/win32/api/processthreadsapi/nf-processthreadsapi-getexitcodethread)

[OpenProcess](https://learn.microsoft.com/windows/win32/api/processthreadsapi/nf-processthreadsapi-openprocess)

[Process and Thread Functions](https://learn.microsoft.com/windows/win32/ProcThread/process-and-thread-functions)

[Processes](https://learn.microsoft.com/windows/win32/ProcThread/child-processes)

[Terminating a Process](https://learn.microsoft.com/windows/win32/ProcThread/terminating-a-process)

[Vertdll APIs available in VBS enclaves](https://learn.microsoft.com/windows/win32/trusted-execution/enclaves-available-in-vertdll)