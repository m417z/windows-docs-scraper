# GetCurrentProcess function

## Description

Retrieves a pseudo handle for the current process.

## Return value

The return value is a pseudo handle to the current process.

## Remarks

A pseudo handle is a special constant, currently (**HANDLE**)-1, that is interpreted as the current process handle. For compatibility with future operating systems, it is best to call **GetCurrentProcess** instead of hard-coding this constant value. The calling process can use a pseudo handle to specify its own process whenever a process handle is required. Pseudo handles are not inherited by child processes.

This handle has the **PROCESS_ALL_ACCESS** access right to the process object. For more information, see [Process Security and Access Rights](https://learn.microsoft.com/windows/win32/ProcThread/process-security-and-access-rights).

**Windows Server 2003 and Windows XP:** This handle has the maximum access allowed by the security descriptor of the process to the primary token of the process.

A process can create a "real" handle to itself that is valid in the context of other processes, or that can be inherited by other processes, by specifying the pseudo handle as the source handle in a call to the [DuplicateHandle](https://learn.microsoft.com/windows/win32/api/handleapi/nf-handleapi-duplicatehandle) function. A process can also use the [OpenProcess](https://learn.microsoft.com/windows/win32/api/processthreadsapi/nf-processthreadsapi-openprocess) function to open a real handle to itself.

The pseudo handle need not be closed when it is no longer needed. Calling the [CloseHandle](https://learn.microsoft.com/windows/win32/api/handleapi/nf-handleapi-closehandle) function with a pseudo handle has no effect. If the pseudo handle is duplicated by [DuplicateHandle](https://learn.microsoft.com/windows/win32/api/handleapi/nf-handleapi-duplicatehandle), the duplicate handle must be closed.

#### Examples

For an example, see [Creating a Child Process with Redirected Input and Output](https://learn.microsoft.com/windows/win32/ProcThread/creating-a-child-process-with-redirected-input-and-output).

## See also

[CloseHandle](https://learn.microsoft.com/windows/win32/api/handleapi/nf-handleapi-closehandle)

[DuplicateHandle](https://learn.microsoft.com/windows/win32/api/handleapi/nf-handleapi-duplicatehandle)

[GetCurrentProcessId](https://learn.microsoft.com/windows/win32/api/processthreadsapi/nf-processthreadsapi-getcurrentprocessid)

[GetCurrentThread](https://learn.microsoft.com/windows/win32/api/processthreadsapi/nf-processthreadsapi-getcurrentthread)

[OpenProcess](https://learn.microsoft.com/windows/win32/api/processthreadsapi/nf-processthreadsapi-openprocess)

[Process and Thread Functions](https://learn.microsoft.com/windows/win32/ProcThread/process-and-thread-functions)

[Processes](https://learn.microsoft.com/windows/win32/ProcThread/child-processes)

[Vertdll APIs available in VBS enclaves](https://learn.microsoft.com/windows/win32/trusted-execution/enclaves-available-in-vertdll)