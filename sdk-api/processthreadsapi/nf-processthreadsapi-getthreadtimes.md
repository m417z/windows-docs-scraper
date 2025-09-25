# GetThreadTimes function

## Description

Retrieves timing information for the specified thread.

## Parameters

### `hThread` [in]

A handle to the thread whose timing information is sought. The handle must have the **THREAD_QUERY_INFORMATION** or **THREAD_QUERY_LIMITED_INFORMATION** access right. For more information, see
[Thread Security and Access Rights](https://learn.microsoft.com/windows/desktop/ProcThread/thread-security-and-access-rights).

**Windows Server 2003 and Windows XP:** The handle must have the **THREAD_QUERY_INFORMATION** access right.

### `lpCreationTime` [out]

A pointer to a
[FILETIME](https://learn.microsoft.com/windows/desktop/api/minwinbase/ns-minwinbase-filetime) structure that receives the creation time of the thread.

### `lpExitTime` [out]

A pointer to a [FILETIME](https://learn.microsoft.com/windows/desktop/api/minwinbase/ns-minwinbase-filetime) structure that receives the exit time of the thread. If the thread has not exited, the content of this structure is undefined.

### `lpKernelTime` [out]

A pointer to a
[FILETIME](https://learn.microsoft.com/windows/desktop/api/minwinbase/ns-minwinbase-filetime) structure that receives the amount of time that the thread has executed in kernel mode.

### `lpUserTime` [out]

A pointer to a [FILETIME](https://learn.microsoft.com/windows/desktop/api/minwinbase/ns-minwinbase-filetime) structure that receives the amount of time that the thread has executed in user mode.

## Return value

If the function succeeds, the return value is nonzero.

If the function fails, the return value is zero. To get extended error information, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

All times are expressed using
[FILETIME](https://learn.microsoft.com/windows/desktop/api/minwinbase/ns-minwinbase-filetime) data structures. Such a structure contains two 32-bit values that combine to form a 64-bit count of 100-nanosecond time units.

Thread creation and exit times are points in time expressed as the amount of time that has elapsed since midnight on January 1, 1601 at Greenwich, England. There are several functions that an application can use to convert such values to more generally useful forms; see
[Time Functions](https://learn.microsoft.com/windows/desktop/SysInfo/time-functions).

Thread kernel mode and user mode times are amounts of time. For example, if a thread has spent one second in kernel mode, this function will fill the [FILETIME](https://learn.microsoft.com/windows/desktop/api/minwinbase/ns-minwinbase-filetime) structure specified by *lpKernelTime* with a 64-bit value of ten million. That is the number of 100-nanosecond units in one second.

To retrieve the number of CPU clock cycles used by the threads, use the [QueryThreadCycleTime](https://learn.microsoft.com/windows/desktop/api/realtimeapiset/nf-realtimeapiset-querythreadcycletime) function.

## See also

[FILETIME](https://learn.microsoft.com/windows/desktop/api/minwinbase/ns-minwinbase-filetime)

[FileTimeToDosDateTime](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-filetimetodosdatetime)

[FileTimeToLocalFileTime](https://learn.microsoft.com/windows/desktop/api/fileapi/nf-fileapi-filetimetolocalfiletime)

[FileTimeToSystemTime](https://learn.microsoft.com/windows/desktop/api/timezoneapi/nf-timezoneapi-filetimetosystemtime)

[OpenThread](https://learn.microsoft.com/windows/desktop/api/processthreadsapi/nf-processthreadsapi-openthread)

[Process and Thread Functions](https://learn.microsoft.com/windows/desktop/ProcThread/process-and-thread-functions)

[Threads](https://learn.microsoft.com/windows/desktop/ProcThread/multiple-threads)