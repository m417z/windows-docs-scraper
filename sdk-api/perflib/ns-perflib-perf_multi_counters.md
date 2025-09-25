# PERF_MULTI_COUNTERS structure

## Description

Provides information about the **PERF_MULTI_COUNTERS** block that contains the structure. A **PERF_MULTI_COUNTERS** block indicates the performance counters for which results are provided as part of the [PERF_COUNTER_HEADER](https://learn.microsoft.com/windows/desktop/api/perflib/ns-perflib-perf_counter_header) block in multiple-counter query. The **PERF_MULTI_COUNTERS** block consists of a **PERF_MULTI_COUNTERS** structure
followed by a sequence of **DWORD** values that specify performance counter identifiers.

## Members

### `dwSize`

The total size of the **PERF_MULTI_COUNTERS** block, in bytes. This total size is the sum of the sizes of the **PERF_MULTI_COUNTERS** structure and all of the performance counter identifiers.

### `dwCounters`

The number of performance counter identifiers that the **PERF_MULTI_COUNTERS** block contains.

## Remarks

The [PerfQueryCounterData](https://learn.microsoft.com/windows/desktop/api/perflib/nf-perflib-perfquerycounterdata) function gets a [PERF_DATA_HEADER](https://learn.microsoft.com/windows/desktop/api/perflib/ns-perflib-perf_data_header) block that may
contain a **PERF_MULTI_COUNTERS** block within the [PERF_COUNTER_HEADER](https://learn.microsoft.com/windows/desktop/api/perflib/ns-perflib-perf_counter_header) block.

## See also

[PERF_COUNTER_HEADER](https://learn.microsoft.com/windows/desktop/api/perflib/ns-perflib-perf_counter_header)

[PERF_DATA_HEADER](https://learn.microsoft.com/windows/desktop/api/perflib/ns-perflib-perf_data_header)

[PerfQueryCounterData](https://learn.microsoft.com/windows/desktop/api/perflib/nf-perflib-perfquerycounterdata)