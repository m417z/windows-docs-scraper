# PERF_COUNTERSET_INFO structure

## Description

Defines information about a counter set that a provider uses. The [CTRPP](https://learn.microsoft.com/windows/desktop/PerfCtrs/ctrpp) tool automatically generates this structure based on the schema you specify.

## Members

### `CounterSetGuid`

GUID that uniquely identifies the counter set. The **guid** attribute of the [counterSet](https://learn.microsoft.com/windows/desktop/PerfCtrs/performance-counters-counterset--provider--element) element contains the GUID.

### `ProviderGuid`

GUID that uniquely identifies the provider that supports the counter set. The **providerGuid** attribute of the [provider](https://learn.microsoft.com/previous-versions/aa373164(v=vs.85)) element contains the GUID.

### `NumCounters`

Number of counters in the counter set. See Remarks.

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
| **PERF_COUNTERSET_INSTANCE_AGGREGATE** | This type is similar to PERF_COUNTERSET_MULTI_AGGREGATE, except that instead of aggregating all instance data to one aggregated (_Total) instance, it will aggregate counter data from instances of the same name.<br><br> <br><br>For example, if multiple provider processes contained instances named IExplore, PERF_COUNTERSET_MULTIPLE and PERF_COUNTERSET_MULTI_AGGREGATE CounterSet will show multiple IExplore instances (IExplore, IExplore#1, IExplore#2, and so on); however, a PERF_COUNTERSET_INSTANCE_AGGREGATE instance type will only publish one IExplore instance with aggregated counter data from all instances named IExplore.<br><br>**Windows Vista:** This type is not available. |

## Remarks

The memory block for this structure also contains one or more [PERF_COUNTER_INFO](https://learn.microsoft.com/windows/desktop/api/perflib/ns-perflib-perf_counter_info) structures. The **NumCounter** member determines the number of **PERF_COUNTER_INFO** structures that follow this structure in memory.

## See also

[PERF_COUNTER_INFO](https://learn.microsoft.com/windows/desktop/api/perflib/ns-perflib-perf_counter_info)

[PerfSetCounterSetInfo](https://learn.microsoft.com/windows/desktop/api/perflib/nf-perflib-perfsetcountersetinfo)