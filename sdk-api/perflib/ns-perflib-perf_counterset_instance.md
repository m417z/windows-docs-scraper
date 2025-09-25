# PERF_COUNTERSET_INSTANCE structure

## Description

Defines an instance of a counter set.

## Members

### `CounterSetGuid`

GUID that identifies the counter set to which this instance belongs.

### `dwSize`

Size, in bytes, of the instance block. The instance block contains this structure, followed by one or more [PERF_COUNTER_INFO](https://learn.microsoft.com/windows/desktop/api/perflib/ns-perflib-perf_counter_info) blocks, and ends with the instance name.

### `InstanceId`

Identifier that uniquely identifies this instance.

The provider specified the identifier when calling [PerfCreateInstance](https://learn.microsoft.com/windows/desktop/api/perflib/nf-perflib-perfcreateinstance).

### `InstanceNameOffset`

Byte offset from the beginning of this structure to the null-terminated Unicode instance name.

The provider specified the instance name when calling [PerfCreateInstance](https://learn.microsoft.com/windows/desktop/api/perflib/nf-perflib-perfcreateinstance).

### `InstanceNameSize`

Size, in bytes, of the instance name. The size includes the null-terminator.

## Remarks

The **Offset** member of [PERF_COUNTER_INFO](https://learn.microsoft.com/windows/desktop/api/perflib/ns-perflib-perf_counter_info) contains the byte offset from the beginning of the **PERF_COUNTERSET_INSTANCE** block to the counter's raw counter value.

## See also

[PERF_COUNTER_INFO](https://learn.microsoft.com/windows/desktop/api/perflib/ns-perflib-perf_counter_info)

[PerfCreateInstance](https://learn.microsoft.com/windows/desktop/api/perflib/nf-perflib-perfcreateinstance)

[PerfDeleteInstance](https://learn.microsoft.com/windows/desktop/api/perflib/nf-perflib-perfdeleteinstance)

[PerfQueryInstance](https://learn.microsoft.com/windows/desktop/api/perflib/nf-perflib-perfqueryinstance)