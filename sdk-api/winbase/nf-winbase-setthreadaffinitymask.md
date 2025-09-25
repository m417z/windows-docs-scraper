# SetThreadAffinityMask function

## Description

Sets a processor affinity mask for the specified thread.

## Parameters

### `hThread` [in]

A handle to the thread whose affinity mask is to be set.

This handle must have the **THREAD_SET_INFORMATION** or **THREAD_SET_LIMITED_INFORMATION** access right and the **THREAD_QUERY_INFORMATION** or **THREAD_QUERY_LIMITED_INFORMATION** access right. For more information, see
[Thread Security and Access Rights](https://learn.microsoft.com/windows/desktop/ProcThread/thread-security-and-access-rights).

**Windows Server 2003 and Windows XP:** The handle must have the **THREAD_SET_INFORMATION** and **THREAD_QUERY_INFORMATION** access rights.

### `dwThreadAffinityMask` [in]

The affinity mask for the thread.

On a system with more than 64 processors, the affinity mask must specify processors in the thread's current [processor group](https://learn.microsoft.com/windows/desktop/ProcThread/processor-groups).

## Return value

If the function succeeds, the return value is the thread's previous affinity mask.

If the function fails, the return value is zero. To get extended error information, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

If the thread affinity mask requests a processor that is not selected for the process affinity mask, the last error code is **ERROR_INVALID_PARAMETER**.

## Remarks

A thread affinity mask is a bit vector in which each bit represents a logical processor that a thread is allowed to run on. A thread affinity mask must be a subset of the process affinity mask for the containing process of a thread. A thread can only run on the processors its process can run on. Therefore, the thread affinity mask cannot specify a 1 bit for a processor when the process affinity mask specifies a 0 bit for that processor.

Setting an affinity mask for a process or thread can result in threads receiving less processor time, as the system is restricted from running the threads on certain processors. In most cases, it is better to let the system select an available processor.

If the new thread affinity mask does not specify the processor that is currently running the thread, the thread is rescheduled on one of the allowable processors.

Starting with Windows 11 and Windows Server 2022, on a system with more than 64 processors, process and thread affinities span all processors in the system, across all [processor groups](https://learn.microsoft.com/windows/desktop/ProcThread/processor-groups), by default. The *dwThreadAffinityMask* must specify processors in the thread's current primary group.

## See also

[GetProcessAffinityMask](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-getprocessaffinitymask)

[Multiple Processors](https://learn.microsoft.com/windows/desktop/ProcThread/multiple-processors)

[OpenThread](https://learn.microsoft.com/windows/desktop/api/processthreadsapi/nf-processthreadsapi-openthread)

[Process and Thread Functions](https://learn.microsoft.com/windows/desktop/ProcThread/process-and-thread-functions)

[Processor Groups](https://learn.microsoft.com/windows/desktop/ProcThread/processor-groups)

[SetProcessAffinityMask](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-setprocessaffinitymask)

[SetThreadIdealProcessor](https://learn.microsoft.com/windows/desktop/api/processthreadsapi/nf-processthreadsapi-setthreadidealprocessor)

[Threads](https://learn.microsoft.com/windows/desktop/ProcThread/multiple-threads)