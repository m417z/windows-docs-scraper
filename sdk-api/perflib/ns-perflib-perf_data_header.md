# PERF_DATA_HEADER structure

## Description

Provides information about the **PERF_DATA_HEADER** block that contains the structure. A **PERF_DATA_HEADER** block corresponds to one query specification in a query, and consists of a **PERF_DATA_HEADER** structure followed by a sequence of [PERF_COUNTER_HEADER](https://learn.microsoft.com/windows/desktop/api/perflib/ns-perflib-perf_counter_header) blocks.

## Members

### `dwTotalSize`

The sum of the size of the **PERF_DATA_HEADER** structure and the sizes of all of the [PERF_COUNTER_HEADER](https://learn.microsoft.com/windows/desktop/api/perflib/ns-perflib-perf_counter_header) blocks in the **PERF_DATA_HEADER** block.

### `dwNumCounters`

The number of [PERF_COUNTER_HEADER](https://learn.microsoft.com/windows/desktop/api/perflib/ns-perflib-perf_counter_header) blocks that the **PERF_DATA_HEADER** block contains.

### `PerfTimeStamp`

The timestamp from a high-resolution clock.

### `PerfTime100NSec`

The number of 100 nanosecond intervals since January 1, 1601, in Coordinated Universal Time (UTC).

### `PerfFreq`

The frequency of a high-resolution clock.

### `SystemTime`

The time at which data is collected by the provider.

## Remarks

The ordering of the [PERF_COUNTER_HEADER](https://learn.microsoft.com/windows/desktop/api/perflib/ns-perflib-perf_counter_header) blocks is based on the **Index** member of
the [PERF_COUNTER_IDENTIFIER](https://learn.microsoft.com/windows/desktop/api/perflib/ns-perflib-perf_counter_identifier) blocks that the [PerfQueryCounterInfo](https://learn.microsoft.com/windows/desktop/api/perflib/nf-perflib-perfquerycounterinfo) function gets. Each
**PERF_COUNTER_HEADER** block is 8-byte aligned, so the value of the **dwTotalSize** is a multiple
of 8 bytes.

The timestamp information in the **PERF_DATA_HEADER** structure is required when
you compute the display values of certain performance counters.

## See also

[PERF_COUNTER_HEADER](https://learn.microsoft.com/windows/desktop/api/perflib/ns-perflib-perf_counter_header)

[PerfQueryCounterInfo](https://learn.microsoft.com/windows/desktop/api/perflib/nf-perflib-perfquerycounterinfo)