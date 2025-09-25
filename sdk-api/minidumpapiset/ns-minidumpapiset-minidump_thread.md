# MINIDUMP_THREAD structure

## Description

Contains information for a specific thread.

## Members

### `ThreadId`

The identifier of the thread.

### `SuspendCount`

The suspend count for the thread. If the suspend count is greater than zero, the thread is suspended; otherwise, the thread is not suspended. The maximum value is MAXIMUM_SUSPEND_COUNT.

### `PriorityClass`

The priority class of the thread. See
[Scheduling Priorities](https://learn.microsoft.com/windows/desktop/ProcThread/scheduling-priorities).

### `Priority`

The priority level of the thread.

### `Teb`

The thread environment block.

### `Stack`

A
[MINIDUMP_MEMORY_DESCRIPTOR](https://learn.microsoft.com/windows/win32/api/minidumpapiset/ns-minidumpapiset-minidump_memory_descriptor) structure.

### `ThreadContext`

A
[MINIDUMP_LOCATION_DESCRIPTOR](https://learn.microsoft.com/windows/win32/api/minidumpapiset/ns-minidumpapiset-minidump_location_descriptor) structure.

## See also

[MINIDUMP_LOCATION_DESCRIPTOR](https://learn.microsoft.com/windows/win32/api/minidumpapiset/ns-minidumpapiset-minidump_location_descriptor)

[MINIDUMP_MEMORY_DESCRIPTOR](https://learn.microsoft.com/windows/win32/api/minidumpapiset/ns-minidumpapiset-minidump_memory_descriptor)