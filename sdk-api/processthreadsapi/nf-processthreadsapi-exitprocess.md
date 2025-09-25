# ExitProcess function

## Description

Ends the calling process and all its threads.

## Parameters

### `uExitCode` [in]

The exit code for the process and all threads.

## Remarks

Use the
[GetExitCodeProcess](https://learn.microsoft.com/windows/desktop/api/processthreadsapi/nf-processthreadsapi-getexitcodeprocess) function to retrieve the process's exit value. Use the
[GetExitCodeThread](https://learn.microsoft.com/windows/desktop/api/processthreadsapi/nf-processthreadsapi-getexitcodethread) function to retrieve a thread's exit value.

Exiting a process causes the following:

1. All of the threads in the process, except the calling thread, terminate their execution without receiving a DLL_THREAD_DETACH notification.
2. The states of all of the threads terminated in step 1 become signaled.
3. The entry-point functions of all loaded dynamic-link libraries (DLLs) are called with DLL_PROCESS_DETACH.
4. After all attached DLLs have executed any process termination code, the **ExitProcess** function terminates the current process, including the calling thread.
5. The state of the calling thread becomes signaled.
6. All of the object handles opened by the process are closed.
7. The termination status of the process changes from STILL_ACTIVE to the exit value of the process.
8. The state of the process object becomes signaled, satisfying any threads that had been waiting for the process to terminate.

If one of the terminated threads in the process holds a lock and the DLL detach code in one of the loaded DLLs attempts to acquire the same lock, then calling **ExitProcess** results in a deadlock. In contrast, if a process terminates by calling
[TerminateProcess](https://learn.microsoft.com/windows/desktop/api/processthreadsapi/nf-processthreadsapi-terminateprocess), the DLLs that the process is attached to are not notified of the process termination. Therefore, if you do not know the state of all threads in your process, it is better to call **TerminateProcess** than **ExitProcess**. Note that returning from the **main** function of an application results in a call to **ExitProcess**.

Calling
**ExitProcess** in a DLL can lead to unexpected application or system errors. Be sure to call
**ExitProcess** from a DLL only if you know which applications or system components will load the DLL and that it is safe to call
**ExitProcess** in this context.

Exiting a process does not cause child processes to be terminated.

Exiting a process does not necessarily remove the process object from the operating system. A process object is deleted when the last handle to the process is closed.

#### Examples

For an example, see
[Creating a Child Process with Redirected Input and Output](https://learn.microsoft.com/windows/desktop/ProcThread/creating-a-child-process-with-redirected-input-and-output).

## See also

[CreateProcess](https://learn.microsoft.com/windows/desktop/api/processthreadsapi/nf-processthreadsapi-createprocessa)

[CreateRemoteThread](https://learn.microsoft.com/windows/desktop/api/processthreadsapi/nf-processthreadsapi-createremotethread)

[CreateThread](https://learn.microsoft.com/windows/desktop/api/processthreadsapi/nf-processthreadsapi-createthread)

[ExitThread](https://learn.microsoft.com/windows/desktop/api/processthreadsapi/nf-processthreadsapi-exitthread)

[GetExitCodeProcess](https://learn.microsoft.com/windows/desktop/api/processthreadsapi/nf-processthreadsapi-getexitcodeprocess)

[GetExitCodeThread](https://learn.microsoft.com/windows/desktop/api/processthreadsapi/nf-processthreadsapi-getexitcodethread)

[OpenProcess](https://learn.microsoft.com/windows/desktop/api/processthreadsapi/nf-processthreadsapi-openprocess)

[Process and Thread Functions](https://learn.microsoft.com/windows/desktop/ProcThread/process-and-thread-functions)

[Processes](https://learn.microsoft.com/windows/desktop/ProcThread/child-processes)

[TerminateProcess](https://learn.microsoft.com/windows/desktop/api/processthreadsapi/nf-processthreadsapi-terminateprocess)

[Terminating a Process](https://learn.microsoft.com/windows/desktop/ProcThread/terminating-a-process)