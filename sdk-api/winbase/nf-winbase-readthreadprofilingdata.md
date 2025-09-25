# ReadThreadProfilingData function

## Description

Reads the specified profiling data associated with the thread.

## Parameters

### `PerformanceDataHandle` [in]

The handle that the [EnableThreadProfiling](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-enablethreadprofiling) function returned.

### `Flags` [in]

One or more of the following flags that specify the counter data to read. The flags must have been set when you called the [EnableThreadProfiling](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-enablethreadprofiling) function.

| Value | Meaning |
| --- | --- |
| **READ_THREAD_PROFILING_FLAG_DISPATCHING**<br><br>0x00000001 | Get the thread profiling data. |
| **READ_THREAD_PROFILING_FLAG_HARDWARE_COUNTERS**<br><br>0x00000002 | Get the hardware performance counters data. |

### `PerformanceData` [out]

A [PERFORMANCE_DATA](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-performance_data) structure that contains the thread profiling and hardware counter data.

## Return value

 Returns ERROR_SUCCESS if the call is successful; otherwise, a system error code (see Winerror.h).

## See also

[EnableThreadProfiling](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-enablethreadprofiling)