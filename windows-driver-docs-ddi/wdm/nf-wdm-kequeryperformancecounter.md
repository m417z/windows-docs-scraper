# KeQueryPerformanceCounter function (wdm.h)

## Description

The **KeQueryPerformanceCounter** routine retrieves the current value and frequency of the performance counter.

Use **KeQueryPerformanceCounter** to acquire high resolution (<1µs) time stamps for time interval measurements.

## Parameters

### `PerformanceFrequency` [out, optional]

A pointer to a variable to which **KeQueryPerformanceCounter** writes the performance counter frequency, in ticks per second. This parameter is optional and can be NULL if the caller does not need the counter frequency value.

## Return value

**KeQueryPerformanceCounter** returns the performance counter value in units of ticks.

## Remarks

**KeQueryPerformanceCounter** returns a 64-bit integer that represents the current value of a high-resolution monotonically nondecreasing counter.

To obtain the frequency of the performance counter, specify a non-**NULL** pointer value for the *PerformanceFrequency* parameter. The frequency of the performance counter is fixed at system boot and is consistent across all processors. Therefore, a driver can cache the frequency of the performance counter during initialization.

For more info about this function and its usage, see [Acquiring high-resolution time stamps](https://learn.microsoft.com/windows/win32/sysinfo/acquiring-high-resolution-time-stamps).

## See also

[KeQueryInterruptTime](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-kequeryinterrupttime)

[KeQuerySystemTime](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-kequerysystemtime-r1)

[KeQueryTickCount](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-kequerytickcount)

[KeQueryTimeIncrement](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-kequerytimeincrement)

[QueryPerformanceCounter](https://learn.microsoft.com/windows/win32/api/profileapi/nf-profileapi-queryperformancecounter)

[QueryPerformanceFrequency](https://learn.microsoft.com/windows/win32/api/profileapi/nf-profileapi-queryperformancefrequency)