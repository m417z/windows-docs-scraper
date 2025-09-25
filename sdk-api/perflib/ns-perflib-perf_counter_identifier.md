# PERF_COUNTER_IDENTIFIER structure

## Description

Contains information about the **PERF_COUNTER_IDENTIFIER** block that contains the structure. A **PERF_COUNTER_IDENTIFIER** block provides information about a performance counter specification, and consists of the following items in order:

1. A **PERF_COUNTER_IDENTIFIER** structure
2. An optional null-terminated UTF-16LE string that specifies the instance name
3. Padding as needed to make the size of the block a multiple of 8 bytes.

## Members

### `CounterSetGuid`

The **GUID** of the performance counter set.

### `Status`

An error code that indicates whether the operation to add or delete a performance counter succeeded or failed.

### `Size`

The total size of the **PERF_COUNTER_IDENTIFIER** block, in bytes. The total size of the block is the sum of the sizes of the **PERF_COUNTER_IDENTIFIER** structure, the string that specifies the instance name, and the padding.

### `CounterId`

The identifier of the performance counter. **PERF_WILDCARD_COUNTER** specifies all counters.

### `InstanceId`

The instance identifier. Specify 0xFFFFFFFF if you do not want to filter the results based on the instance identifier.

### `Index`

The position in the sequence of **PERF_COUNTER_IDENTIFIER** blocks at which the counter data that corresponds to this **PERF_COUNTER_IDENTIFIER** block is returned. Set by [PerfQueryCounterInfo](https://learn.microsoft.com/windows/desktop/api/perflib/nf-perflib-perfquerycounterinfo).

### `Reserved`

Reserved.

## Remarks

When you specify a counter set identifier for a single-instance counter set, you must not specify the
instance name in the additional data of the **PERF_COUNTER_IDENTIFIER** block. The size of the **PERF_COUNTER_IDENTIFIER** block must be the size of the **PERF_COUNTER_IDENTIFIER** structure.

On the other hand, when you specify a counter set identifier for a multiple-instance counter set, you must specify the instance name in the additional data of the **PERF_COUNTER_IDENTIFIER** block. The identifier is notconsidered valid unless the size of
the **PERF_COUNTER_IDENTIFIER** block is greater than the size of the **PERF_COUNTER_IDENTIFIER** structure. If you do not want
to filter the counter sets based on the instance name, use **PERF_WILDCARD_INSTANCE** as the instance
name.

The [PerfAddCounters](https://learn.microsoft.com/windows/desktop/api/perflib/nf-perflib-perfaddcounters) and [PerfDeleteCounters](https://learn.microsoft.com/windows/desktop/api/perflib/nf-perflib-perfdeletecounters) functions accept a sequence of
**PERF_COUNTER_IDENTIFIER** blocks to define the counter specifications that you want to be
add or remove from a query.

The [PerfQueryCounterInfo](https://learn.microsoft.com/windows/desktop/api/perflib/nf-perflib-perfquerycounterinfo) function gets a sequence of **PERF_COUNTER_IDENTIFIER** blocks to indicate the counter specifications in a query and to indicate in the **Index** member the
order in which the query gets the results.

## See also

[PerfAddCounters](https://learn.microsoft.com/windows/desktop/api/perflib/nf-perflib-perfaddcounters)

[PerfDeleteCounters](https://learn.microsoft.com/windows/desktop/api/perflib/nf-perflib-perfdeletecounters)

[PerfQueryCounterInfo](https://learn.microsoft.com/windows/desktop/api/perflib/nf-perflib-perfquerycounterinfo)