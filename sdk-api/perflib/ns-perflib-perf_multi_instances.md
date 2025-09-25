# PERF_MULTI_INSTANCES structure

## Description

Provides information about the **PERF_MULTI_INSTANCES** block that contains the structure. A **PERF_MULTI_INSTANCES** block indicates the number of instances for which results are provided as part of the [PERF_COUNTER_HEADER](https://learn.microsoft.com/windows/desktop/api/perflib/ns-perflib-perf_counter_header) block in multiple-instance query. The **PERF_MULTI_INSTANCES** block consists of the following items in order:

1. A **PERF_MULTI_INSTANCES** structure
2. A number of instance data blocks. The number of instance data blocks that the **PERF_MULTI_INSTANCES** block contains is indicated ny the **dwInstances** member of the **PERF_MULTI_INSTANCES** structure. Each instance data block
   consists of the following items in order:
   1. A [PERF_INSTANCE_HEADER](https://learn.microsoft.com/windows/desktop/api/perflib/ns-perflib-perf_instance_header) block
   2. A number of
      [PERF_COUNTER_DATA](https://learn.microsoft.com/windows/desktop/api/perflib/ns-perflib-perf_counter_data) blocks. The number of **PERF_COUNTER_DATA** blocks depends on
      the context:
      * If the **PERF_MULTI_INSTANCES** block is part of a
        [PERF_COUNTER_HEADER](https://learn.microsoft.com/windows/desktop/api/perflib/ns-perflib-perf_counter_header) block with type **PERF_MULTIPLE_INSTANCES**, the instance data block contains one
        [PERF_COUNTER_DATA](https://learn.microsoft.com/windows/desktop/api/perflib/ns-perflib-perf_counter_data) block.
      * If the **PERF_MULTI_INSTANCES** block is part of a
        [PERF_COUNTER_HEADER](https://learn.microsoft.com/windows/desktop/api/perflib/ns-perflib-perf_counter_header) block with type **PERF_COUNTERSET**, the number of
        [PERF_COUNTER_DATA](https://learn.microsoft.com/windows/desktop/api/perflib/ns-perflib-perf_counter_data) blocks is indicated by the [PERF_MULTI_COUNTERS](https://learn.microsoft.com/windows/desktop/api/perflib/ns-perflib-perf_multi_counters) block.

## Members

### `dwTotalSize`

The total size of the **PERF_MULTI_INSTANCES** block, in bytes. This total size is the sum of the sizes of the **PERF_MULTI_INSTANCES** structure and the instance data blocks.

### `dwInstances`

The number of instance data blocks in the **PERF_MULTI_INSTANCES** block.

## Remarks

The [PerfQueryCounterData](https://learn.microsoft.com/windows/desktop/api/perflib/nf-perflib-perfquerycounterdata) function gets a [PERF_DATA_HEADER](https://learn.microsoft.com/windows/desktop/api/perflib/ns-perflib-perf_data_header) block that may
contain **PERF_MULTI_INSTANCES** blocks within the [PERF_COUNTER_HEADER](https://learn.microsoft.com/windows/desktop/api/perflib/ns-perflib-perf_counter_header) block.

## See also

[PERF_COUNTER_HEADER](https://learn.microsoft.com/windows/desktop/api/perflib/ns-perflib-perf_counter_header)

[PERF_DATA_HEADER](https://learn.microsoft.com/windows/desktop/api/perflib/ns-perflib-perf_data_header)

[PerfQueryCounterData](https://learn.microsoft.com/windows/desktop/api/perflib/nf-perflib-perfquerycounterdata)