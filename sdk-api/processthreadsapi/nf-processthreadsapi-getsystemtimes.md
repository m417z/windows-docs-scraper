# GetSystemTimes function

## Description

Retrieves system timing information in "ticks" (or 100-nanosecond intervals).

## Parameters

### `lpIdleTime` [out, optional]

A pointer to a [FILETIME](https://learn.microsoft.com/windows/desktop/api/minwinbase/ns-minwinbase-filetime) structure that receives the amount of time in "ticks" that the system has been idle.

### `lpKernelTime` [out, optional]

A pointer to a [FILETIME](https://learn.microsoft.com/windows/desktop/api/minwinbase/ns-minwinbase-filetime) structure that receives the amount of time in "ticks" that the system has spent executing in Kernel mode (including all threads in all processes, on all processors). This time value also includes the amount of time the system has been idle.

### `lpUserTime` [out, optional]

A pointer to a [FILETIME](https://learn.microsoft.com/windows/desktop/api/minwinbase/ns-minwinbase-filetime) structure that receives the amount of time in "ticks" that the system has spent executing in User mode (including all threads in all processes, on all processors).

## Return value

If the function succeeds, the return value is nonzero.

If the function fails, the return value is zero. To get extended error information, call [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

On a multiprocessor system (with 64 processors or fewer), the value returned is the sum of the designated times in "ticks" across all processors.

> [!NOTE]
> On systems with more than 64 processors, the value returned is the sum of the designated times for the primary processor group that the calling thread belongs to (see [Processor Groups](https://learn.microsoft.com/windows/win32/procthread/processor-groups)).

To compile an application that uses this function, define _WIN32_WINNT as 0x0501 or later. For more information, see [Using the Windows Headers](https://learn.microsoft.com/windows/desktop/WinProg/using-the-windows-headers).

## See also

## See also

[FILETIME](https://learn.microsoft.com/windows/desktop/api/minwinbase/ns-minwinbase-filetime)

[System Time](https://learn.microsoft.com/windows/desktop/SysInfo/system-time)

[Time Functions](https://learn.microsoft.com/windows/desktop/SysInfo/time-functions)