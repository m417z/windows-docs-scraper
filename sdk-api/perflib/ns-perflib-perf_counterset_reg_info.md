# PERF_COUNTERSET_REG_INFO structure

## Description

Contains information about the **PERF_COUNTERSET_REG_INFO** block that contains the structure. A **PERF_COUNTERSET_REG_INFO** block provides registration information for a counter set and the performance counters it contains, and consists of a **PERF_COUNTERSET_REG_INFO** structure immediately followed by a set
[PERF_COUNTER_REG_INFO](https://learn.microsoft.com/windows/desktop/api/perflib/ns-perflib-perf_counter_reg_info) structures that correspond to the performance counters in the counter set.

## Members

### `CounterSetGuid`

The unique identifier for the counter set.

### `CounterSetType`

Reserved.

### `DetailLevel`

The target audience for the counters in the counter set.

The possible values are:

| Value | Meaning |
| --- | --- |
| **PERF_DETAIL_NOVICE** | You can display the counter to any level of user. |
| **PERF_DETAIL_ADVANCED** | The counter is complicated and should be displayed only to advanced users. |

### `NumCounters`

The number of [PERF_COUNTER_REG_INFO](https://learn.microsoft.com/windows/desktop/api/perflib/ns-perflib-perf_counter_reg_info) structures in this **PERF_COUNTERSET_REG_INFO** block.

### `InstanceType`

Specifies whether the counter set allows multiple instances such as processes and physical disks, or a single instance such as memory.

The following are the possible instance types.

| Value | Meaning |
| --- | --- |
| **PERF_COUNTERSET_SINGLE_INSTANCE** | The counter set contains single instance counters, for example, a counter that measures physical memory. |
| **PERF_COUNTERSET_MULTI_INSTANCES** | The counter set contains multiple instance counters, for example, a counter that measures the average disk I/O for a process. |
| **PERF_COUNTERSET_SINGLE_AGGREGATE** | The counter set contains single instance counters whose aggregate value is obtained from one or more sources. For example, a counter in this type of counter set might obtain the number of reads from each of the three hard disks on the computer and sum their values. |
| **PERF_COUNTERSET_MULTI_AGGREGATE** | The counter set contains multiple instance counters whose aggregate value is obtained from all instances of the counter. For example, a counter in this type of counter set might obtain the total thread execution time for all threads in a multi-threaded application and sum their values. |
| **PERF_COUNTERSET_SINGLE_AGGREGATE_HISTORY** | The difference between this type and **PERF_COUNTERSET_SINGLE_AGGREGATE** is that this counter set type stores all counter values for the lifetime of the consumer application (the counter value is cached beyond the lifetime of the counter). For example, if one of the hard disks in the single aggregate example above were to become unavailable, the total bytes read by that disk would still be available and used to calculate the aggregate value. |
| **PERF_COUNTERSET_INSTANCE_AGGREGATE** | Not implemented. |

## Remarks

The [PerfQueryCounterSetRegistrationInfo](https://learn.microsoft.com/windows/desktop/api/perflib/nf-perflib-perfquerycountersetregistrationinfo) function called with the *requestCode* parameter set to
**PERF_REG_COUNTERSET_STRUCT** gets a **PERF_COUNTERSET_REG_INFO** block.