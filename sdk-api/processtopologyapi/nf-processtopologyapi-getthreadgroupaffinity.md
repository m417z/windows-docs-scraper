# GetThreadGroupAffinity function

## Description

Retrieves the processor group affinity of the specified thread.

## Parameters

### `hThread` [in]

A handle to the thread for which the processor group affinity is desired.

The handle must have the THREAD_QUERY_INFORMATION or THREAD_QUERY_LIMITED_INFORMATION access right. For more information, see
[Thread Security and Access Rights](https://learn.microsoft.com/windows/desktop/ProcThread/thread-security-and-access-rights).

### `GroupAffinity` [out]

A pointer to a [GROUP_AFFINITY](https://learn.microsoft.com/windows/win32/api/winnt/ns-winnt-group_affinity) structure that receives the group affinity of the thread.

## Return value

If the function succeeds, the return value is nonzero.

If the function fails, the return value is zero. To get extended error information, use [GetLastError](https://learn.microsoft.com/windows/desktop/api/adshlp/nf-adshlp-adsgetlasterror).

## Remarks

Starting with Windows 11 and Windows Server 2022, on a system with more than 64 processors, process and thread affinities span all processors in the system, across all [processor groups](https://learn.microsoft.com/windows/desktop/ProcThread/processor-groups), by default. The **GetThreadGroupAffinity** function retrieves the group affinity over the thread's primary group.

To compile an application that uses this function, set _WIN32_WINNT >= 0x0601. For more information, see [Using the Windows Headers](https://learn.microsoft.com/windows/desktop/WinProg/using-the-windows-headers).

## See also

[GetProcessGroupAffinity](https://learn.microsoft.com/windows/desktop/api/processtopologyapi/nf-processtopologyapi-getprocessgroupaffinity)

[Processor Groups](https://learn.microsoft.com/windows/desktop/ProcThread/processor-groups)