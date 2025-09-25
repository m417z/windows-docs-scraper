# GetProcessAffinityMask function

## Description

Retrieves the process affinity mask for the specified process and the system affinity mask for the system.

## Parameters

### `hProcess` [in]

A handle to the process whose affinity mask is desired.

This handle must have the **PROCESS_QUERY_INFORMATION** or **PROCESS_QUERY_LIMITED_INFORMATION** access right. For more information, see
[Process Security and Access Rights](https://learn.microsoft.com/windows/desktop/ProcThread/process-security-and-access-rights).

**Windows Server 2003 and Windows XP:** The handle must have the **PROCESS_QUERY_INFORMATION** access right.

### `lpProcessAffinityMask` [out]

A pointer to a variable that receives the affinity mask for the specified process.

### `lpSystemAffinityMask` [out]

A pointer to a variable that receives the affinity mask for the system.

## Return value

If the function succeeds, the return value is nonzero and the function sets the variables pointed to by *lpProcessAffinityMask* and *lpSystemAffinityMask* to the appropriate affinity masks.

On a system with more than 64 processors, if the threads of the calling process are in a single [processor group](https://learn.microsoft.com/windows/desktop/ProcThread/processor-groups), the function sets the variables pointed to by *lpProcessAffinityMask* and *lpSystemAffinityMask* to the process affinity mask and the processor mask of active logical processors for that group. If the calling process contains threads in multiple groups, the function returns zero for both affinity masks.

If the function fails, the return value is zero, and the values of the variables pointed to by *lpProcessAffinityMask* and *lpSystemAffinityMask* are undefined. To get extended error information, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

A process affinity mask is a bit vector in which each bit represents the processors that a process is allowed to run on. A system affinity mask is a bit vector in which each bit represents the processors that are configured into a system.

A process affinity mask is a subset of the system affinity mask. A process is only allowed to run on the processors configured into a system. Therefore, the process affinity mask cannot specify a 1 bit for a processor when the system affinity mask specifies a 0 bit for that processor.

Starting with Windows 11 and Windows Server 2022, on a system with more than 64 processors, process and thread affinities span all processors in the system, across all [processor groups](https://learn.microsoft.com/windows/desktop/ProcThread/processor-groups), by default. The **GetProcessAffinityMask** function sets the *lpProcessAffinityMask* and *lpSystemAffinityMask* to the process and system processor masks over the process' primary group. If the process had explicitly set the affinity of one or more of its threads outside of the process' primary group, the function returns zero for both affinity masks. If, however, *hHandle* specifies a handle to the current process, the function always uses the calling thread's primary group (which by default is the same as the process' primary group) in order to set the *lpProcessAffinityMask* and *lpSystemAffinityMask*.

## See also

[Multiple Processors](https://learn.microsoft.com/windows/desktop/ProcThread/multiple-processors)

[Process and Thread Functions](https://learn.microsoft.com/windows/desktop/ProcThread/process-and-thread-functions)

[Processes](https://learn.microsoft.com/windows/desktop/ProcThread/child-processes)

[Processor Groups](https://learn.microsoft.com/windows/desktop/ProcThread/processor-groups)

[SetProcessAffinityMask](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-setprocessaffinitymask)

[SetThreadAffinityMask](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-setthreadaffinitymask)