# _PEP_PPM_PERF_SET structure (pepfx.h)

## Description

The **PEP_PPM_PERF_SET** structure specifies the new performance level that the operating system is requesting for the processor.

## Members

### `MinimumPerformance` [in]

The new minimum performance level in platform-specific units. This member indicates the absolute minimum performance level that the processor can run at.

### `MaximumPerformance` [in]

The new maximum performance level in platform-specific units. This member indicates the absolute maximum performance level that the processor can run at.

### `DesiredPerformance` [in]

The new desired performance level in platform-specific units. This member is set to a value in the range **MinimumPerformance** to **MaximumPerformance**.

### `TimeWindow` [in]

The width, in milliseconds, of the new time window over which the platform must provide the required average performance. If this time window is nonzero, the instantaneous performance provided by the platform does not need to match the desired performance level, and only needs to fall within the constraints specified by the minimum and maximum performance level.

### `PerformanceTolerance` [in]

The new performance tolerance in platform-specific units. This member contains the minimum performance level that the platform can deliver and still meet the operating system's performance requirements.

## Remarks

This structure is used by the [PEP_NOTIFY_PPM_PERF_SET](https://learn.microsoft.com/windows-hardware/drivers/ddi/pepfx/ns-pepfx-_pep_ppm_perf_set) notification. All five members of this structure contain input values that PoFx supplies when this notification is sent to the PEP.

Processor performance levels are specified in platform-specific units. For example, a hardware platform might use a metric such as the processor clock frequency to provide a rough approximation to the amount of processing work that is being done. For more information, see [Platform Performance Thresholds](https://learn.microsoft.com/windows-hardware/drivers/kernel/platform-performance-thresholds).

## See also

[PEP_NOTIFY_PPM_PERF_SET](https://learn.microsoft.com/windows-hardware/drivers/ddi/pepfx/ns-pepfx-_pep_ppm_perf_set)

[Platform Performance Thresholds](https://learn.microsoft.com/windows-hardware/drivers/kernel/platform-performance-thresholds)