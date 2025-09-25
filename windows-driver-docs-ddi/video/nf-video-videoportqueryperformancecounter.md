# VideoPortQueryPerformanceCounter function

## Description

The **VideoPortQueryPerformanceCounter** function provides the finest-grained running count available in the system.

## Parameters

### `HwDeviceExtension`

[in] Pointer to the miniport driver's device extension.

### `PerformanceFrequency`

[out, optional] An optional pointer to a variable that is to receive the performance counter frequency.

## Return value

**VideoPortQueryPerformanceCounter** returns the performance counter value in units of ticks.

## Remarks

**VideoPortQueryPerformanceCounter** always returns a 64-bit integer representing the number of ticks. Accumulating the count begins when the system is booted. The count is in ticks; the frequency is reported by **PerformanceFrequency** if this optional parameter is supplied.

The resolution of the timer used to accumulate the current count can be obtained by specifying **PerformanceFrequency**. For example, if the returned **PerformanceFrequency** is 2 million, each tick is 1/2 millionth of a second. Each 1/*x* millionth increment of the count corresponds to one second of elapsed time.

**VideoPortQueryPerformanceCounter** is intended for time-stamping packets or for computing performance and capacity measurements. It is not intended for measuring elapsed time, for computing stalls or waits, or for iterations.

Use this routine as infrequently as possible. Depending on the platform, **VideoPortQueryPerformanceCounter** can disable system-wide interrupts for a minimal interval. Consequently, calling this routine frequently or repeatedly, as in an iteration, defeats its purpose of returning very fine-grained, running time-stamp information. Calling this routine too frequently can degrade I/O performance for the calling driver and for the system as a whole.