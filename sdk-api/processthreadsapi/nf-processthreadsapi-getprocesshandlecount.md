# GetProcessHandleCount function

## Description

Retrieves the number of open handles that belong to the specified process.

## Parameters

### `hProcess` [in]

A handle to the process whose handle count is being requested. The
handle must have the PROCESS_QUERY_INFORMATION
or PROCESS_QUERY_LIMITED_INFORMATION access right. For more information, see [Process Security and Access Rights](https://learn.microsoft.com/windows/desktop/ProcThread/process-security-and-access-rights).

**Windows Server 2003 and Windows XP:** The handle must have the PROCESS_QUERY_INFORMATION access right.

### `pdwHandleCount` [in, out]

A pointer to a variable that receives the number of open handles that belong to the specified process.

## Return value

If the function succeeds, the return value is nonzero.

If the function fails, the return value is zero. To get extended error information, call [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

This function retrieves information about the executive objects for the process. For more information, see [Kernel Objects](https://learn.microsoft.com/windows/desktop/SysInfo/kernel-objects).

To compile an application that uses this function, define _WIN32_WINNT as 0x0501 or later. For more information, see [Using the Windows Headers](https://learn.microsoft.com/windows/desktop/WinProg/using-the-windows-headers).

## See also

[Process and Thread Functions](https://learn.microsoft.com/windows/desktop/ProcThread/process-and-thread-functions)

[Processes](https://learn.microsoft.com/windows/desktop/ProcThread/child-processes)