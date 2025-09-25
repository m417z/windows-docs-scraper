# PERFORMANCE_DATA structure

## Description

Contains the thread profiling and hardware counter data that you requested.

## Members

### `Size`

The size of this structure.

### `Version`

The version of this structure. Must be set to PERFORMANCE_DATA_VERSION.

### `HwCountersCount`

The number of array elements in the **HwCounters** array that contain hardware counter data. A value of 3 means that the array contains data for three hardware counters, not that elements 0 through 2 contain counter data.

### `ContextSwitchCount`

The number of context switches that occurred from the time profiling was enabled.

### `WaitReasonBitMap`

A bitmask that identifies the reasons for the context switches that occurred since the last time the data was read. For possible values, see the **KWAIT_REASON** enumeration (the enumeration is included in the Wdm.h file in the WDK).

### `CycleTime`

The cycle time of the thread (excludes the time spent interrupted) from the time profiling was enabled.

### `RetryCount`

The number of times that the read operation read the data to ensure a consistent snapshot of the data.

### `Reserved`

Reserved. Set to zero.

### `HwCounters`

An array of [HARDWARE_COUNTER_DATA](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-hardware_counter_data) structures that contain the counter values. The elements of the array that contain counter data relate directly to the bits set in the *HardwareCounters* bitmask that you specified when you called the [EnableThreadProfiling](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-enablethreadprofiling) function. For example, if you set bit 3 in the *HardwareCounters* bitmask, HwCounters[3] will contain the counter data for that counter.

## Remarks

You must initialize the **Size** and **Version** members before calling the [ReadThreadProfilingData](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-readthreadprofilingdata) function to read the profiling data.

The profile data contained in this structure depends on the data that you requested when you called the [ReadThreadProfilingData](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-readthreadprofilingdata) function. The following members are set when you specify the READ_THREAD_PROFILING_FLAG_DISPATCHING flag:

* **ContextSwitchCount**
* **CycleTime**
* **RetryCount**
* **WaitReasonBitMap**

The following members are set when you specify the READ_THREAD_PROFILING_FLAG_HARDWARE_COUNTERS flag:

* **HwCounters**
* **HwCountersCount**

## See also

[ReadThreadProfilingData](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-readthreadprofilingdata)