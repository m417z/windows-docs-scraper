# SetThreadIdealProcessor function

## Description

Sets a preferred processor for a thread. The system schedules threads on their preferred processors whenever possible.

On a system with more than 64 processors, this function sets the preferred processor to a logical processor in the [processor group](https://learn.microsoft.com/windows/desktop/ProcThread/processor-groups) to which the calling thread is assigned. Use the [SetThreadIdealProcessorEx](https://learn.microsoft.com/windows/desktop/api/processthreadsapi/nf-processthreadsapi-setthreadidealprocessorex) function to specify a processor group and preferred processor.

## Parameters

### `hThread` [in]

A handle to the thread whose preferred processor is to be set. The handle must have the THREAD_SET_INFORMATION access right. For more information, see
[Thread Security and Access Rights](https://learn.microsoft.com/windows/desktop/ProcThread/thread-security-and-access-rights).

### `dwIdealProcessor` [in]

The number of the preferred processor for the thread. This value is zero-based. If this parameter is MAXIMUM_PROCESSORS, the function returns the current ideal processor without changing it.

## Return value

If the function succeeds, the return value is the previous preferred processor.

If the function fails, the return value is (DWORD) – 1. To get extended error information, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

You can use the [GetSystemInfo](https://learn.microsoft.com/windows/desktop/api/sysinfoapi/nf-sysinfoapi-getsysteminfo) function to determine the number of processors on the computer. You can also use the
[GetProcessAffinityMask](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-getprocessaffinitymask) function to check the processors on which the thread is allowed to run. Note that
**GetProcessAffinityMask** returns a bitmask whereas
**SetThreadIdealProcessor** uses an integer value to represent the processor.

Starting with Windows 11 and Windows Server 2022, on a system with more than 64 processors, process and thread affinities span all processors in the system, across all [processor groups](https://learn.microsoft.com/windows/desktop/ProcThread/processor-groups), by default.
The **SetThreadIdealProcessor** function sets the preferred processor to a logical processor in the thread's primary group.

To compile an application that uses this function, define _WIN32_WINNT as 0x0400 or later. For more information, see
[Using the Windows Headers](https://learn.microsoft.com/windows/desktop/WinProg/using-the-windows-headers).

**Windows 8.1** and **Windows Server 2012 R2**: This function is supported for Windows Store apps on Windows 8.1, Windows Server 2012 R2, and later.

## See also

[GetProcessAffinityMask](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-getprocessaffinitymask)

[GetSystemInfo](https://learn.microsoft.com/windows/desktop/api/sysinfoapi/nf-sysinfoapi-getsysteminfo)

[Multiple Processors](https://learn.microsoft.com/windows/desktop/ProcThread/multiple-processors)

[OpenThread](https://learn.microsoft.com/windows/desktop/api/processthreadsapi/nf-processthreadsapi-openthread)

[Process and Thread Functions](https://learn.microsoft.com/windows/desktop/ProcThread/process-and-thread-functions)

[SetThreadAffinityMask](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-setthreadaffinitymask)

[SetThreadIdealProcessorEx](https://learn.microsoft.com/windows/desktop/api/processthreadsapi/nf-processthreadsapi-setthreadidealprocessorex)

[Threads](https://learn.microsoft.com/windows/desktop/ProcThread/multiple-threads)