# GetProcessTimes function

## Description

Retrieves timing information for the specified process.

## Parameters

### `hProcess` [in]

A handle to the process whose timing information is sought. The handle must have the **PROCESS_QUERY_INFORMATION** or **PROCESS_QUERY_LIMITED_INFORMATION** access right. For more information, see
[Process Security and Access Rights](https://learn.microsoft.com/windows/desktop/ProcThread/process-security-and-access-rights).

**Windows Server 2003 and Windows XP:** The handle must have the **PROCESS_QUERY_INFORMATION** access right.

### `lpCreationTime` [out]

A pointer to a
[FILETIME](https://learn.microsoft.com/windows/desktop/api/minwinbase/ns-minwinbase-filetime) structure that receives the creation time of the process.

### `lpExitTime` [out]

A pointer to a [FILETIME](https://learn.microsoft.com/windows/desktop/api/minwinbase/ns-minwinbase-filetime) structure that receives the exit time of the process. If the process has not exited, the content of this structure is undefined.

### `lpKernelTime` [out]

A pointer to a
[FILETIME](https://learn.microsoft.com/windows/desktop/api/minwinbase/ns-minwinbase-filetime) structure that receives the amount of time that the process has executed in kernel mode. The time that each of the threads of the process has executed in kernel mode is determined, and then all of those times are summed together to obtain this value.

### `lpUserTime` [out]

A pointer to a [FILETIME](https://learn.microsoft.com/windows/desktop/api/minwinbase/ns-minwinbase-filetime) structure that receives the amount of time that the process has executed in user mode. The time that each of the threads of the process has executed in user mode is determined, and then all of those times are summed together to obtain this value. Note that this value can exceed the amount of real time elapsed (between *lpCreationTime* and *lpExitTime*) if the process executes across multiple CPU cores.

## Return value

If the function succeeds, the return value is nonzero.

If the function fails, the return value is zero. To get extended error information, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

All times are expressed using [FILETIME](https://learn.microsoft.com/windows/desktop/api/minwinbase/ns-minwinbase-filetime) data structures. Such a structure contains two 32-bit values that combine to form a 64-bit count of 100-nanosecond time units.

Process creation and exit times are points in time expressed as the amount of time that has elapsed since midnight on January 1, 1601 at Greenwich, England. There are several functions that an application can use to convert such values to more generally useful forms.

Process kernel mode and user mode times are amounts of time. For example, if a process has spent one second in kernel mode, this function will fill the
[FILETIME](https://learn.microsoft.com/windows/desktop/api/minwinbase/ns-minwinbase-filetime) structure specified by *lpKernelTime* with a 64-bit value of ten million. That is the number of 100-nanosecond units in one second.

To retrieve the number of CPU clock cycles used by the threads of the process, use the [QueryProcessCycleTime](https://learn.microsoft.com/windows/desktop/api/realtimeapiset/nf-realtimeapiset-queryprocesscycletime) function.

## See also

[FILETIME](https://learn.microsoft.com/windows/desktop/api/minwinbase/ns-minwinbase-filetime)

[FileTimeToDosDateTime](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-filetimetodosdatetime)

[FileTimeToLocalFileTime](https://learn.microsoft.com/windows/desktop/api/fileapi/nf-fileapi-filetimetolocalfiletime)

[FileTimeToSystemTime](https://learn.microsoft.com/windows/desktop/api/timezoneapi/nf-timezoneapi-filetimetosystemtime)

[Process and Thread Functions](https://learn.microsoft.com/windows/desktop/ProcThread/process-and-thread-functions)

[Processes](https://learn.microsoft.com/windows/desktop/ProcThread/child-processes)