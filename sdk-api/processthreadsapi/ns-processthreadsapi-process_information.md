# PROCESS_INFORMATION structure

## Description

Contains information about a newly created process and its primary thread. It is used with the
[CreateProcess](https://learn.microsoft.com/windows/desktop/api/processthreadsapi/nf-processthreadsapi-createprocessa), [CreateProcessAsUser](https://learn.microsoft.com/windows/desktop/api/processthreadsapi/nf-processthreadsapi-createprocessasusera), [CreateProcessWithLogonW](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-createprocesswithlogonw), or [CreateProcessWithTokenW](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-createprocesswithtokenw) function.

## Members

### `hProcess`

A handle to the newly created process. The handle is used to specify the process in all functions that perform operations on the process object.

### `hThread`

A handle to the primary thread of the newly created process. The handle is used to specify the thread in all functions that perform operations on the thread object.

### `dwProcessId`

A value that can be used to identify a process. The value is valid from the time the process is created until all handles to the process are closed and the process object is freed; at this point, the identifier may be reused.

### `dwThreadId`

A value that can be used to identify a thread. The value is valid from the time the thread is created until all handles to the thread are closed and the thread object is freed; at this point, the identifier may be reused.

## Remarks

If the function succeeds, be sure to call the [CloseHandle](https://learn.microsoft.com/windows/desktop/api/handleapi/nf-handleapi-closehandle) function to close the **hProcess** and **hThread** handles when you are finished with them. Otherwise, when the child process exits, the system cannot clean up the process structures for the child process because the parent process still has open handles to the child process. However, the system will close these handles when the parent process terminates, so the structures related to the child process object would be cleaned up at this point.

#### Examples

For an example, see
[Creating Processes](https://learn.microsoft.com/windows/desktop/ProcThread/creating-processes).

## See also

[CreateProcess](https://learn.microsoft.com/windows/desktop/api/processthreadsapi/nf-processthreadsapi-createprocessa)

[CreateProcessAsUser](https://learn.microsoft.com/windows/desktop/api/processthreadsapi/nf-processthreadsapi-createprocessasusera)

[CreateProcessWithLogonW](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-createprocesswithlogonw)

[CreateProcessWithTokenW](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-createprocesswithtokenw)