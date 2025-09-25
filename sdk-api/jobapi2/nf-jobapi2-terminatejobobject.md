# TerminateJobObject function

## Description

Terminates all processes currently associated with the job. If the job is nested, this function terminates all processes currently associated with the job and all of its child jobs in the hierarchy.

## Parameters

### `hJob` [in]

A handle to the job whose processes will be terminated. The
[CreateJobObject](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-createjobobjecta) or
[OpenJobObject](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-openjobobjecta) function returns this handle. This handle must have the JOB_OBJECT_TERMINATE access right. For more information, see
[Job Object Security and Access Rights](https://learn.microsoft.com/windows/desktop/ProcThread/job-object-security-and-access-rights).

The handle for each process in the job object must have the PROCESS_TERMINATE access right. For more information, see
[Process Security and Access Rights](https://learn.microsoft.com/windows/desktop/ProcThread/process-security-and-access-rights).

### `uExitCode` [in]

The exit code to be used by all processes and threads in the job object. Use the
[GetExitCodeProcess](https://learn.microsoft.com/windows/desktop/api/processthreadsapi/nf-processthreadsapi-getexitcodeprocess) function to retrieve each process's exit value. Use the
[GetExitCodeThread](https://learn.microsoft.com/windows/desktop/api/processthreadsapi/nf-processthreadsapi-getexitcodethread) function to retrieve each thread's exit value.

## Return value

If the function succeeds, the return value is nonzero.

If the function fails, the return value is zero. To get extended error information, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

It is not possible for any of the processes associated with the job to postpone or handle the termination. It is as if
[TerminateProcess](https://learn.microsoft.com/windows/desktop/api/processthreadsapi/nf-processthreadsapi-terminateprocess) were called for each process associated with the job.

Terminating a nested job additionally terminates all child job objects. Resources used by the terminated jobs are charged up the parent job chain in the hierarchy.

To compile an application that uses this function, define _WIN32_WINNT as 0x0500 or later. For more information, see
[Using the Windows Headers](https://learn.microsoft.com/windows/desktop/WinProg/using-the-windows-headers).

## See also

[CreateJobObject](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-createjobobjecta)

[Job Objects](https://learn.microsoft.com/windows/desktop/ProcThread/job-objects)

[OpenJobObject](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-openjobobjecta)

[Process and Thread Functions](https://learn.microsoft.com/windows/desktop/ProcThread/process-and-thread-functions)

[TerminateProcess](https://learn.microsoft.com/windows/desktop/api/processthreadsapi/nf-processthreadsapi-terminateprocess)