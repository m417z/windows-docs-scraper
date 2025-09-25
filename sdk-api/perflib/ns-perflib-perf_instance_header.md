# PERF_INSTANCE_HEADER structure

## Description

Provides information about the **PERF_INSTANCE_HEADER** block that contains the structure. A **PERF_INSTANCE_HEADER** block provides information about the instances in a counter set, or the instances for which performance counter results are provided in a multiple-instance query. The **PERF_INSTANCE_HEADER** block consists of the following items in order:

1. A **PERF_INSTANCE_HEADER** structure
   that contains the size of the **PERF_INSTANCE_HEADER** block and the instance identifier
2. A null-terminated UTF-16LE string that contains the instance name.
3. Padding such that the total size of the **PERF_INSTANCE_HEADER** block is a multiple of 8 bytes.

## Members

### `Size`

The total size of the **PERF_INSTANCE_HEADER** block, in bytes. This total size is the sum of the sizes of the **PERF_INSTANCE_HEADER** structures, the string that contains the instance name, and the padding.

### `InstanceId`

The instance identifier.

## Remarks

Each active instance of a counter set is identified by the combination of

its instance name and instance identifier. Two active instances of a

counter set should not have the same combination of instance name and instance

identifier. Clients, however, should tolerate instances with duplicate combinations of instance name and instance

identifier.

The [PerfEnumerateCounterSetInstances](https://learn.microsoft.com/windows/desktop/api/perflib/nf-perflib-perfenumeratecountersetinstances) function gets a sequence of

**PERF_INSTANCE_HEADER** blocks.

The [PerfQueryCounterData](https://learn.microsoft.com/windows/desktop/api/perflib/nf-perflib-perfquerycounterdata) function gets a [PERF_DATA_HEADER](https://learn.microsoft.com/windows/desktop/api/perflib/ns-perflib-perf_data_header) block that may

contain **PERF_INSTANCE_HEADER** blocks within the [PERF_MULTI_INSTANCES](https://learn.microsoft.com/windows/desktop/api/perflib/ns-perflib-perf_multi_instances) block.

## See also

[PERF_DATA_HEADER](https://learn.microsoft.com/windows/desktop/api/perflib/ns-perflib-perf_data_header)

[PERF_INSTANCE_HEADER](https://learn.microsoft.com/windows/desktop/api/perflib/ns-perflib-perf_instance_header)

[PERF_MULTI_INSTANCES](https://learn.microsoft.com/windows/desktop/api/perflib/ns-perflib-perf_multi_instances)

[PerfEnumerateCounterSetInstances](https://learn.microsoft.com/windows/desktop/api/perflib/nf-perflib-perfenumeratecountersetinstances)

[PerfQueryCounterData](https://learn.microsoft.com/windows/desktop/api/perflib/nf-perflib-perfquerycounterdata)