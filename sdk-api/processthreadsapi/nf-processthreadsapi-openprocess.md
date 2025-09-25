# OpenProcess function

## Description

Opens an existing local process object.

## Parameters

### `dwDesiredAccess` [in]

The access to the process object. This access right is checked against the security descriptor for the process. This parameter can be one or more of the
[process access rights](https://learn.microsoft.com/windows/desktop/ProcThread/process-security-and-access-rights).

If the caller has enabled the [SeDebugPrivilege privilege](https://learn.microsoft.com/windows/win32/secauthz/privilege-constants#SE_DEBUG_NAME), the requested access is granted regardless of the contents of the security descriptor.

### `bInheritHandle` [in]

If this value is TRUE, processes created by this process will inherit the handle. Otherwise, the processes do not inherit this handle.

### `dwProcessId` [in]

The identifier of the local process to be opened.

If the specified process is the System Idle Process (0x00000000), the function fails and the last error code is `ERROR_INVALID_PARAMETER`. If the specified process is the System process or one of the Client Server Run-Time Subsystem (CSRSS) processes, this function fails and the last error code is `ERROR_ACCESS_DENIED` because their access restrictions prevent user-level code from opening them.

If you are using [GetCurrentProcessId](https://learn.microsoft.com/windows/desktop/api/processthreadsapi/nf-processthreadsapi-getcurrentprocessid) as an argument to this function, consider using [GetCurrentProcess](https://learn.microsoft.com/windows/desktop/api/processthreadsapi/nf-processthreadsapi-getcurrentprocess) instead of OpenProcess, for improved performance.

## Return value

If the function succeeds, the return value is an open handle to the specified process.

If the function fails, the return value is NULL. To get extended error information, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

To open a handle to another local process and obtain full access rights, you must enable the SeDebugPrivilege privilege. For more information, see [Changing Privileges in a Token](https://learn.microsoft.com/windows/desktop/SecBP/changing-privileges-in-a-token).

The handle returned by the
**OpenProcess** function can be used in any function that requires a handle to a process, such as the
[wait functions](https://learn.microsoft.com/windows/desktop/Sync/wait-functions), provided the appropriate access rights were requested.

When you are finished with the handle, be sure to close it using the [CloseHandle](https://learn.microsoft.com/windows/desktop/api/handleapi/nf-handleapi-closehandle) function.

#### Examples

For an example, see
[Taking a Snapshot and Viewing Processes](https://learn.microsoft.com/windows/desktop/ToolHelp/taking-a-snapshot-and-viewing-processes).

## See also

[AssignProcessToJobObject](https://learn.microsoft.com/windows/desktop/api/jobapi2/nf-jobapi2-assignprocesstojobobject)

[CloseHandle](https://learn.microsoft.com/windows/desktop/api/handleapi/nf-handleapi-closehandle)

[CreateProcess](https://learn.microsoft.com/windows/desktop/api/processthreadsapi/nf-processthreadsapi-createprocessa)

[CreateRemoteThread](https://learn.microsoft.com/windows/desktop/api/processthreadsapi/nf-processthreadsapi-createremotethread)

[DuplicateHandle](https://learn.microsoft.com/windows/desktop/api/handleapi/nf-handleapi-duplicatehandle)

[GetCurrentProcess](https://learn.microsoft.com/windows/desktop/api/processthreadsapi/nf-processthreadsapi-getcurrentprocess)

[GetCurrentProcessId](https://learn.microsoft.com/windows/desktop/api/processthreadsapi/nf-processthreadsapi-getcurrentprocessid)

[GetExitCodeProcess](https://learn.microsoft.com/windows/desktop/api/processthreadsapi/nf-processthreadsapi-getexitcodeprocess)

[GetModuleFileNameEx](https://learn.microsoft.com/windows/desktop/api/psapi/nf-psapi-getmodulefilenameexa)

[GetPriorityClass](https://learn.microsoft.com/windows/desktop/api/processthreadsapi/nf-processthreadsapi-getpriorityclass)

[Process and Thread Functions](https://learn.microsoft.com/windows/desktop/ProcThread/process-and-thread-functions)

[Processes](https://learn.microsoft.com/windows/desktop/ProcThread/child-processes)

[ReadProcessMemory](https://learn.microsoft.com/windows/desktop/api/memoryapi/nf-memoryapi-readprocessmemory)

[SetPriorityClass](https://learn.microsoft.com/windows/desktop/api/processthreadsapi/nf-processthreadsapi-setpriorityclass)

[SetProcessWorkingSetSize](https://learn.microsoft.com/windows/win32/api/memoryapi/nf-memoryapi-setprocessworkingsetsize)

[TerminateProcess](https://learn.microsoft.com/windows/desktop/api/processthreadsapi/nf-processthreadsapi-terminateprocess)

[VirtualProtectEx](https://learn.microsoft.com/windows/desktop/api/memoryapi/nf-memoryapi-virtualprotectex)

[WriteProcessMemory](https://learn.microsoft.com/windows/desktop/api/memoryapi/nf-memoryapi-writeprocessmemory)