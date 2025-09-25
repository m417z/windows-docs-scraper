# GetProcessGroupAffinity function

## Description

Retrieves the processor group affinity of the specified process.

## Parameters

### `hProcess` [in]

A handle to the process.

This handle must have the PROCESS_QUERY_INFORMATION or PROCESS_QUERY_LIMITED_INFORMATION access right. For more information, see
[Process Security and Access Rights](https://learn.microsoft.com/windows/desktop/ProcThread/process-security-and-access-rights).

### `GroupCount` [in, out]

On input, specifies the number of elements in *GroupArray* array. On output, specifies the number of processor groups written to the array. If the array is too small, the function fails with ERROR_INSUFFICIENT_BUFFER and sets the *GroupCount* parameter to the number of elements required.

### `GroupArray` [out]

An array of processor group numbers. A group number is included in the array if a thread in the process is assigned to a processor in the group.

## Return value

If the function succeeds, the return value is nonzero.

If the function fails, the return value is zero. To get extended error information, use [GetLastError](https://learn.microsoft.com/windows/desktop/api/adshlp/nf-adshlp-adsgetlasterror).

If the error value is ERROR_INSUFFICIENT_BUFFER, the *GroupCount* parameter contains the required buffer size in number of elements.

## Remarks

Starting with Windows 11 and Windows Server 2022, on a system with more than 64 processors, process and thread affinities span all processors in the system, across all [processor groups](https://learn.microsoft.com/windows/desktop/ProcThread/processor-groups), by default.

To compile an application that uses this function, set _WIN32_WINNT >= 0x0601. For more information, see [Using the Windows Headers](https://learn.microsoft.com/windows/desktop/WinProg/using-the-windows-headers).

## See also

[GetThreadGroupAffinity](https://learn.microsoft.com/windows/desktop/api/processtopologyapi/nf-processtopologyapi-getthreadgroupaffinity)

[Processor Groups](https://learn.microsoft.com/windows/desktop/ProcThread/processor-groups)