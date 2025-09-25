# GetProcessIoCounters function

## Description

Retrieves accounting information for all I/O operations performed by the specified process.

## Parameters

### `hProcess` [in]

A handle to the process. The handle must have the **PROCESS_QUERY_INFORMATION** or **PROCESS_QUERY_LIMITED_INFORMATION** access right. For more information, see
[Process Security and Access Rights](https://learn.microsoft.com/windows/desktop/ProcThread/process-security-and-access-rights).

**Windows Server 2003 and Windows XP:** The handle must have the **PROCESS_QUERY_INFORMATION** access right.

### `lpIoCounters` [out]

A pointer to an
[IO_COUNTERS](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-io_counters) structure that receives the I/O accounting information for the process.

## Return value

If the function succeeds, the return value is nonzero.

If the function fails, the return value is zero. To get extended error information, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## See also

[IO_COUNTERS](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-io_counters)

[Process and Thread Functions](https://learn.microsoft.com/windows/desktop/ProcThread/process-and-thread-functions)