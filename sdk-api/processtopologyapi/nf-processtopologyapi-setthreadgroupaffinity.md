# SetThreadGroupAffinity function

## Description

Sets the processor group affinity for the specified thread.

## Parameters

### `hThread` [in]

A handle to the thread.

The handle must have the THREAD_SET_INFORMATION access right. For more information, see
[Thread Security and Access Rights](https://learn.microsoft.com/windows/desktop/ProcThread/thread-security-and-access-rights).

### `GroupAffinity` [in]

A [GROUP_AFFINITY](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-group_affinity) structure that specifies the processor group affinity to be used for the specified thread.

### `PreviousGroupAffinity` [out, optional]

A pointer to a [GROUP_AFFINITY](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-group_affinity) structure to receive the thread's previous group affinity. This parameter can be NULL.

## Return value

If the function succeeds, the return value is nonzero.

If the function fails, the return value is zero. To get extended error information, use [GetLastError](https://learn.microsoft.com/windows/desktop/api/adshlp/nf-adshlp-adsgetlasterror).

## Remarks

Starting with Windows 11 and Windows Server 2022, on a system with more than 64 processors, process and thread affinities span all processors in the system, across all [processor groups](https://learn.microsoft.com/windows/desktop/ProcThread/processor-groups), by default.
The **SetThreadGroupAffinity** function restricts a thread's affinity to the processors over the single processor group specified by the given *GroupAffinity*. This group will also become the thread's primary group.

To compile an application that uses this function, set _WIN32_WINNT >= 0x0601. For more information, see [Using the Windows Headers](https://learn.microsoft.com/windows/desktop/WinProg/using-the-windows-headers).

## See also

[GROUP_AFFINITY](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-group_affinity)