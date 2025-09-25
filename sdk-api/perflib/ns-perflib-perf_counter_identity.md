# PERF_COUNTER_IDENTITY structure

## Description

Defines the counter that is sent to a provider's callback when the consumer adds or removes a counter from the query.

## Members

### `CounterSetGuid`

GUID that uniquely identifies the counter set that this counter belongs to.

### `BufferSize`

Size, in bytes, of this structure and the computer name and instance name that are appended to this structure in memory.

### `CounterId`

Unique identifier of the counter in the counter set.

This member is set to **PERF_WILDCARD_COUNTER** if the consumer wants to add or remove all counters in the counter set.

### `InstanceId`

Identifier of the counter set instance to which the counter belongs.

Ignore this value if the instance name at **NameOffset** is PERF_WILDCARD_INSTANCE.

### `MachineOffset`

Offset to the null-terminated Unicode computer name that follows this structure in memory.

### `NameOffset`

Offset to the null-terminated Unicode instance name that follows this structure in memory.

### `Reserved`

Reserved.

## See also

[ControlCallback](https://learn.microsoft.com/windows/desktop/api/perflib/nc-perflib-perflibrequest)