# SetProcessAffinityMask function

## Description

Sets a processor affinity mask for the threads of the specified process.

## Parameters

### `hProcess` [in]

A handle to the process whose affinity mask is to be set. This handle must have the **PROCESS_SET_INFORMATION** access right. For more information, see
[Process Security and Access Rights](https://learn.microsoft.com/windows/desktop/ProcThread/process-security-and-access-rights).

### `dwProcessAffinityMask` [in]

The affinity mask for the threads of the process.

On a system with more than 64 processors, the affinity mask must specify processors in a single [processor group](https://learn.microsoft.com/windows/desktop/ProcThread/processor-groups).

## Return value

If the function succeeds, the return value is nonzero.

If the function fails, the return value is zero. To get extended error information, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

If the process affinity mask requests a processor that is not configured in the system, the last error code is **ERROR_INVALID_PARAMETER**.

On a system with more than 64 processors, if the calling process contains threads in more than one processor group, the last error code is **ERROR_INVALID_PARAMETER**.

## Remarks

A process affinity mask is a bit vector in which each bit represents a logical processor on which the threads of the process are allowed to run. The value of the process affinity mask must be a subset of the system affinity mask values obtained by the
[GetProcessAffinityMask](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-getprocessaffinitymask) function. A process is only allowed to run on the processors configured into a system. Therefore, the process affinity mask cannot specify a 1 bit for a processor when the system affinity mask specifies a 0 bit for that processor.

Process affinity is inherited by any child process or newly instantiated local process.

Do not call **SetProcessAffinityMask** in a DLL that may be called by processes other than your own.

On a system with more than 64 processors, the **SetProcessAffinityMask** function can be used to set the process affinity mask only for processes with threads in a single [processor group](https://learn.microsoft.com/windows/desktop/ProcThread/processor-groups). Use the [SetThreadAffinityMask](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-setthreadaffinitymask) function to set the affinity mask for individual threads in multiple groups. This effectively changes the group assignment of the process.

Starting with Windows 11 and Windows Server 2022, on a system with more than 64 processors, process and thread affinities span all processors in the system, across all processor groups, by default. Instead of always failing in case the calling process contains threads in more than one processor group, the **SetProcessAffinityMask** function fails (returning zero with **ERROR_INVALID_PARAMETER** last error code) if the process had explicitly set the affinity of one or more of its threads outside of the process' [primary group](https://learn.microsoft.com/windows/desktop/ProcThread/processor-groups).

## See also

[CreateProcess](https://learn.microsoft.com/windows/desktop/api/processthreadsapi/nf-processthreadsapi-createprocessa)

[GetProcessAffinityMask](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-getprocessaffinitymask)

[Multiple Processors](https://learn.microsoft.com/windows/desktop/ProcThread/multiple-processors)

[Process and Thread Functions](https://learn.microsoft.com/windows/desktop/ProcThread/process-and-thread-functions)

[Processes](https://learn.microsoft.com/windows/desktop/ProcThread/child-processes)

[Processor Groups](https://learn.microsoft.com/windows/desktop/ProcThread/processor-groups)

[SetThreadAffinityMask](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-setthreadaffinitymask)