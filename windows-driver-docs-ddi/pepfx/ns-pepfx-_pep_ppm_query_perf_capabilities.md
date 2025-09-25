# _PEP_PPM_QUERY_PERF_CAPABILITIES structure (pepfx.h)

## Description

The **PEP_PPM_QUERY_PERF_CAPABILITIES** structure describes the performance capabilities of the processors in the specified processor performance domain.

## Members

### `HighestPerformance` [out]

The highest performance level in platform-specific units. For more information, see Remarks.

### `NominalPerformance` [out]

The nominal performance level in platform-specific units. For more information, see Remarks.

### `LowestNonlinearPerformance` [out]

The lowest nonlinear performance level in platform-specific units. For more information, see Remarks.

### `LowestPerformance` [out]

The lowest performance level in platform-specific units. For more information, see Remarks.

### `DomainId` [out]

The domain ID of the processor performance domain.

### `DomainMembers` [out]

The number of processors in this performance domain.

## Remarks

This structure is used by the [PEP_NOTIFY_PPM_QUERY_PERF_CAPABILITIES](https://learn.microsoft.com/windows-hardware/drivers/ddi/pepfx/ns-pepfx-_pep_ppm_query_perf_capabilities) notification. All six members contain output values that the platform extension plug-in (PEP) writes to the structure in response to this notification.

Processor performance levels are specified in platform-specific units. For example, a hardware platform might use a metric such as the processor clock frequency to provide a rough approximation to the amount of processing work that is being done. For more information, see [Platform Performance Thresholds](https://learn.microsoft.com/windows-hardware/drivers/kernel/platform-performance-thresholds).

## See also

[PEP_NOTIFY_PPM_QUERY_PERF_CAPABILITIES](https://learn.microsoft.com/windows-hardware/drivers/ddi/pepfx/ns-pepfx-_pep_ppm_query_perf_capabilities)

[Platform Performance Thresholds](https://learn.microsoft.com/windows-hardware/drivers/kernel/platform-performance-thresholds)