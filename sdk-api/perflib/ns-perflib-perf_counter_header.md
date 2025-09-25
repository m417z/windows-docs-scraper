# PERF_COUNTER_HEADER structure

## Description

Contains information about the **PERF_COUNTER_HEADER** block that contains the structure. A **PERF_COUNTER_HEADER** block provides error information and data for performance counter queries, and consists of a **PERF_COUNTER_HEADER** structure
followed by additional performance counter data.

## Members

### `dwStatus`

 An error code that indicates whether the operation to query the performance succeeded or failed.

### `dwType`

The type of performance counter information that the **PERF_COUNTER_HEADER** block provides.

| Value | Meaning |
| --- | --- |
| **PERF_ERROR_RETURN** | An error that was the result of a performance counter query. The performance library cannot get valid counter data back from provider. No additional data follows the **PERF_COUNTER_HEADER** structure. The **dwStatus** member of the structure contains the error code. |
| **PERF_SINGLE_COUNTER** | The result of a single-counter, single-instance query; for example, "\Processor(_Total)\% Processor Time". The additional data consists of a [PERF_COUNTER_DATA](https://learn.microsoft.com/windows/desktop/api/perflib/ns-perflib-perf_counter_data) block. |
| **PERF_MULTIPLE_COUNTERS** | The result of a multi-counter, single-instance query; for example, "\Processor(_Total)\*". The additional data consists of a [PERF_MULTI_COUNTERS](https://learn.microsoft.com/windows/desktop/api/perflib/ns-perflib-perf_multi_counters) block followed by [PERF_COUNTER_DATA](https://learn.microsoft.com/windows/desktop/api/perflib/ns-perflib-perf_counter_data) blocks. |
| **PERF_MULTIPLE_INSTANCES** | The result of a single-counter, multi-instance query; for example, "\Processor(*)\% Processor Time". The additional data consists of a [PERF_MULTI_INSTANCES](https://learn.microsoft.com/windows/desktop/api/perflib/ns-perflib-perf_multi_instances) block. |
| **PERF_COUNTERSET** | The result of a multi-counter, multi-instance query; for example, "\Processor(*)\*". The additional data consists of a [PERF_MULTI_COUNTERS](https://learn.microsoft.com/windows/desktop/api/perflib/ns-perflib-perf_multi_counters) block followed by a [PERF_MULTI_INSTANCES](https://learn.microsoft.com/windows/desktop/api/perflib/ns-perflib-perf_multi_instances) block. |

### `dwSize`

The total size of the **PERF_COUNTER_HEADER** block, which equals the sum of the size of the **PERF_COUNTER_HEADER** structure and the size of the additional data.

### `Reserved`

Reserved.

## Remarks

The [PerfQueryCounterData](https://learn.microsoft.com/windows/desktop/api/perflib/nf-perflib-perfquerycounterdata) function returns a [PERF_DATA_HEADER](https://learn.microsoft.com/windows/desktop/api/perflib/ns-perflib-perf_data_header) block that
contains a sequence of **PERF_COUNTER_HEADER** blocks.

## See also

[PERF_COUNTER_DATA](https://learn.microsoft.com/windows/desktop/api/perflib/ns-perflib-perf_counter_data)

[PERF_MULTI_COUNTERS](https://learn.microsoft.com/windows/desktop/api/perflib/ns-perflib-perf_multi_counters)

[PERF_MULTI_INSTANCES](https://learn.microsoft.com/windows/desktop/api/perflib/ns-perflib-perf_multi_instances)

[PerfCounterDataType](https://learn.microsoft.com/windows/desktop/api/perflib/ne-perflib-perfcounterdatatype)