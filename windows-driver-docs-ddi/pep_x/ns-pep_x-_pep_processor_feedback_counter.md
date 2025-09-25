# _PEP_PROCESSOR_FEEDBACK_COUNTER structure (pep_x.h)

## Description

The **PEP_PROCESSOR_FEEDBACK_COUNTER** structure describes a feedback counter to the operating system.

## Members

### `Affinitized`

Identifies the counter process affinity. If set to 1, the counter must be read while executing on the target processor, otherwise, it will be set to 0.

### `Type`

Specifies the data type of the counter.

The processor feedback counter data types are:

|Value|Meaning|
|--- |--- |
|**PROCESSOR_FEEDBACK_TYPE_INSTANTANEOUS** (0x00) |The feedback counter returns the instantaneous value of the property being counted.|
|**PROCESSOR_FEEDBACK_TYPE_RELATIVE** (0x01) |The feedback counter returns two incrementing values: the nominal count, and the actual count. Nominal count increments at a fixed nominal rate. Actual count increments at a variable rate relative to the property being counted. When the property is incrementing at its nominal rate, the two values should increment at the same rate. To compute an average rate over a time period, the OS reads the counter once and the beginning of the period and once at the end and computes: ![The average rate is equal to the nominal rate multiplied by the quotient of the variable rate divided by the fixed rate.](https://learn.microsoft.com/windows-hardware/drivers/ddi/pep_x/images/PEP_PROCESSOR_FEEDBACK_COUNTER_equation.png)|

### `Counter`

Specifies the data the counter is providing.

The processor feedback counter types are:

| Value | Meaning |
| --- | --- |
| **PROCESSOR_FEEDBACK_COUNTER_FREQUENCY**<br><br>0x00 | The feedback counter returns the clock speed of the processor. The nominal rate is the nominal clock speed, in MHz. |
| **PROCESSOR_FEEDBACK_COUNTER_PERFORMANCE**<br><br>0x01 | The feedback counter returns the current processor performance. The nominal rate is equivalent to the processor's **NominalPerformance** (see [PEP_NOTIFY_PPM_QUERY_PERF_CAPABILITIES notification](https://learn.microsoft.com/windows-hardware/drivers/ddi/pepfx/ns-pepfx-_pep_ppm_query_perf_capabilities)). |

### `DiscountIdle`

### `Reserved`

This member is reserved and should be set to zero.

### `NominalRate`

Specifies the nominal rate of the counter.

## Remarks

This structure

## See also

[PEP structures](https://learn.microsoft.com/windows-hardware/drivers/ddi/)

[PEP_NOTIFY_PPM_QUERY_PERF_CAPABILITIES notification](https://learn.microsoft.com/windows-hardware/drivers/ddi/pepfx/ns-pepfx-_pep_ppm_query_perf_capabilities)