# PERF_COUNTER_BLOCK structure

## Description

Describes the block of memory that contains the raw performance counter data for an
object's counters.

## Members

### `ByteLength`

Size of this structure and the raw counter data that follows, in bytes.

## Remarks

The **CounterOffset** member of [PERF_COUNTER_DEFINITION](https://learn.microsoft.com/windows/desktop/api/winperf/ns-winperf-perf_counter_definition) provides the offset from the beginning of this structure to the counter value.

The location of the **PERF_COUNTER_BLOCK** structure within the [PERF_OBJECT_TYPE](https://learn.microsoft.com/windows/desktop/api/winperf/ns-winperf-perf_object_type) block depends on if the object contains instances. For details, see [Performance Data Format](https://learn.microsoft.com/windows/desktop/PerfCtrs/performance-data-format).

You must ensure that the size of the counter block is aligned to an 8-byte boundary. For example, if the performance object includes two DWORD counters, you must add an additional four bytes to the counter block to make it aligned to an 8-byte boundary.

## See also

[PERF_COUNTER_DEFINITION](https://learn.microsoft.com/windows/desktop/api/winperf/ns-winperf-perf_counter_definition)

[PERF_INSTANCE_DEFINITION](https://learn.microsoft.com/windows/desktop/api/winperf/ns-winperf-perf_instance_definition)

[PERF_OBJECT_TYPE](https://learn.microsoft.com/windows/desktop/api/winperf/ns-winperf-perf_object_type)