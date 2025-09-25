# PerfCounterDataType enumeration

## Description

Indicates the content type of a [PERF_COUNTER_HEADER](https://learn.microsoft.com/windows/desktop/api/perflib/ns-perflib-perf_counter_header) block that the [PerfQueryCounterData](https://learn.microsoft.com/windows/desktop/api/perflib/nf-perflib-perfquerycounterdata) function includes as part of the [PERF_DATA_HEADER](https://learn.microsoft.com/windows/desktop/api/perflib/ns-perflib-perf_data_header) block that the function produces as output.

## Constants

### `PERF_ERROR_RETURN:0`

An error occurred when the performance counter value was queried.

### `PERF_SINGLE_COUNTER:1`

The query returned a single counter from a single instance.

### `PERF_MULTIPLE_COUNTERS:2`

The query returned multiple counters from a single instance.

### `PERF_MULTIPLE_INSTANCES:4`

The query returned a single counter from each of multiple instances.

### `PERF_COUNTERSET`

The query returned multiple counters from each of multiple instances.

## See also

[PERF_COUNTER_HEADER](https://learn.microsoft.com/windows/desktop/api/perflib/ns-perflib-perf_counter_header)

[PerfQueryCounterData](https://learn.microsoft.com/windows/desktop/api/perflib/nf-perflib-perfquerycounterdata)