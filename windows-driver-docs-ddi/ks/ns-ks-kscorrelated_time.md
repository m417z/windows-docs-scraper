# KSCORRELATED_TIME structure

## Description

The KSCORRELATED_TIME structure contains a clock time as well as the corresponding number of clock ticks since system boot.

## Members

### `Time`

Specifies the current clock time in 100-nanosecond units.

### `SystemTime`

A 64-bit integer containing the number of clock ticks since system boot.

## Remarks

Supply this structure in a [KSPROPERTY_CLOCK_CORRELATEDTIME](https://learn.microsoft.com/windows-hardware/drivers/stream/ksproperty-clock-correlatedtime) property request.

The system time is acquired from [KeQueryPerformanceCounter](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-kequeryperformancecounter). Note that the performance counter is not suspended when the machine is suspended, so that correlations change when the machine goes through a suspend.

## See also

[KSPROPERTY_CLOCK_CORRELATEDTIME](https://learn.microsoft.com/windows-hardware/drivers/stream/ksproperty-clock-correlatedtime)

[KeQueryPerformanceCounter](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-kequeryperformancecounter)