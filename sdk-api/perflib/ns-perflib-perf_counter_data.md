# PERF_COUNTER_DATA structure

## Description

Contains information about the **PERF_COUNTER_DATA** block that contains the structure. A **PERF_COUNTER_DATA** block provides raw performance counter data, and consists of the following items in order:

1. A **PERF_COUNTER_DATA** structure.
2. Raw performance counter data.
3. Padding to make the total size of the block a multiple of eight
   bytes.

## Members

### `dwDataSize`

The size of the raw performance counter data that follows the **PERF_COUNTER_DATA** structure in the **PERF_COUNTER_DATA** block, in bytes.

### `dwSize`

The total size of the **PERF_COUNTER_DATA** block, which is the sum of the sizes opf the following items:

* The **PERF_COUNTER_DATA** structure
* The raw performance counter data
* The padding that ensures that the size of the **PERF_COUNTER_DATA** block is a multiple of 8 bytes

## Remarks

The [PerfQueryCounterData](https://learn.microsoft.com/windows/desktop/api/perflib/nf-perflib-perfquerycounterdata) function returns a [PERF_DATA_HEADER](https://learn.microsoft.com/windows/desktop/api/perflib/ns-perflib-perf_data_header) block that may contain **PERF_COUNTER_DATA** blocks directly, or indirectly as part of a [PERF_MULTI_INSTANCES](https://learn.microsoft.com/windows/desktop/api/perflib/ns-perflib-perf_multi_instances) block.

## See also

[PerfQueryCounterData](https://learn.microsoft.com/windows/desktop/api/perflib/nf-perflib-perfquerycounterdata)