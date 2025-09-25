# EnableThreadProfiling function

## Description

Enables thread profiling on the specified thread.

## Parameters

### `ThreadHandle` [in]

The handle to the thread on which you want to enable profiling. This must be the current thread.

### `Flags` [in]

To receive thread profiling data such as context switch count, set this parameter to THREAD_PROFILING_FLAG_DISPATCH; otherwise, set to 0.

### `HardwareCounters` [in]

To receive hardware performance counter data, set this parameter to a bitmask that identifies the hardware counters to collect. You can specify up to 16 performance counters. Each bit relates directly to the zero-based hardware counter index for the hardware performance counters that you configured. Set to zero if you are not collecting hardware counter data. If you set a bit for a hardware counter that has not been configured, the counter value that is read for that counter is zero.

### `PerformanceDataHandle` [out]

An opaque handle that you use when calling the [ReadThreadProfilingData](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-readthreadprofilingdata) and [DisableThreadProfiling](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-disablethreadprofiling) functions.

## Return value

 Returns ERROR_SUCCESS if the call is successful; otherwise, a system error code (see Winerror.h).

## Remarks

You must call the [DisableThreadProfiling](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-disablethreadprofiling) function before exiting the thread.

To profile hardware performance counters, you need a driver to configure the counters. The performance counters are configured globally for the system, so every thread has access to the same hardware counter data. The counters must be configured before you enable profiling. For information on configuring hardware performance counters, see the **KeSetHardwareCounterConfiguration** function in the Windows Driver Kit (WDK).

## See also

[DisableThreadProfiling](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-disablethreadprofiling)

[QueryThreadProfiling](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-querythreadprofiling)

[ReadThreadProfilingData](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-readthreadprofilingdata)