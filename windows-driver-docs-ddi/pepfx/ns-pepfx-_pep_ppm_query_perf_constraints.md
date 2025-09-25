# _PEP_PPM_QUERY_PERF_CONSTRAINTS structure (pepfx.h)

## Description

The **PEP_PPM_PERF_CONSTRAINTS** structure describes the performance limits to apply to the processor.

## Members

### `GuaranteedPerformanceLimit` [out]

The guaranteed performance threshold in platform-specific units. If nonzero, this value specifies the maximum sustained performance level of the processor, taking into account all known external constraints (power budgeting, thermal constraints, power source, and so on). All processors are expected to be able to simultaneously sustain their guaranteed performance levels. For more information, see [Platform Performance Thresholds](https://learn.microsoft.com/windows-hardware/drivers/kernel/platform-performance-thresholds).

### `LimitReasons` [out]

The reasons for which the processor's performance can be limited. Set this member to zero or to the bitwise-OR of one or more of the following values:

| Limit reason | Meaning |
| --- | --- |
| **PERFORMANCE_LIMIT_THERMAL**<br><br>0x1 | The processor performance can be limited due to an out-of-band (that is, non-ACPI Thermal Zone) thermal condition. |
| **PERFORMANCE_LIMIT_POWER**<br><br>0x2 | The processor performance can be limited to keep power consumption of the processor within hardware safety limits. |
| **PERFORMANCE_LIMIT_DOMAIN_DEPENDENCY**<br><br>0x4 | The processor performance can be limited because of a voltage or frequency dependency between this processor and another, non-processor device. |

## Remarks

This structure is used by the [PEP_NOTIFY_PPM_PERF_CONSTRAINTS](https://learn.microsoft.com/windows-hardware/drivers/ddi/pepfx/ns-pepfx-_pep_ppm_query_perf_constraints) notification. The **GuaranteedPerformanceLimit** and **LimitReasons** members contain output values that the platform extension plug-in (PEP) writes to the structure in response to this notification.

The **GuaranteedPerformanceLimit** member value is specified in platform-specific units. For example, a hardware platform might use a metric such as the processor clock frequency to provide a rough approximation to the amount of processing work that is being done.

## See also

[PEP_NOTIFY_PPM_PERF_CONSTRAINTS](https://learn.microsoft.com/windows-hardware/drivers/ddi/pepfx/ns-pepfx-_pep_ppm_query_perf_constraints)