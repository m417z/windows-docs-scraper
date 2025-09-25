# ProcessIdToSessionId function

## Description

Retrieves the Remote Desktop Services session
associated with a specified process.

## Parameters

### `dwProcessId` [in]

Specifies a process identifier. Use the
[GetCurrentProcessId](https://learn.microsoft.com/windows/desktop/api/processthreadsapi/nf-processthreadsapi-getcurrentprocessid) function to retrieve the
process identifier for the current process.

### `pSessionId` [out]

Pointer to a variable that receives the identifier of the Remote Desktop Services session under which the
specified process is running. To retrieve the identifier of the session currently attached to the console, use
the [WTSGetActiveConsoleSessionId](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-wtsgetactiveconsolesessionid)
function.

## Return value

If the function succeeds, the return value is a nonzero value.

If the function fails, the return value is zero. To get extended error information, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

Callers must hold the **PROCESS_QUERY_INFORMATION** access right for the specified
process. For more information, see
[Process Security and Access Rights](https://learn.microsoft.com/windows/desktop/ProcThread/process-security-and-access-rights).

## See also

[OSVERSIONINFOEX](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-osversioninfoexa)

[WTSQuerySessionInformation](https://learn.microsoft.com/windows/desktop/api/wtsapi32/nf-wtsapi32-wtsquerysessioninformationa)