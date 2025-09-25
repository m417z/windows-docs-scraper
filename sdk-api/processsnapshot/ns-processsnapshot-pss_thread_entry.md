# PSS_THREAD_ENTRY structure

## Description

Holds thread information returned by [PssWalkSnapshot](https://learn.microsoft.com/previous-versions/windows/desktop/api/processsnapshot/nf-processsnapshot-psswalksnapshot)**PssWalkSnapshot**.

## Members

### `ExitStatus`

The exit code of the process. If the process has not exited, this is set to **STILL_ACTIVE** (259).

### `TebBaseAddress`

The address of the thread environment block (TEB). Reserved for use by the operating system.

### `ProcessId`

The process ID.

### `ThreadId`

The thread ID.

### `AffinityMask`

The affinity mask of the process.

### `Priority`

The thread’s dynamic priority level.

### `BasePriority`

The base priority level of the process.

### `LastSyscallFirstArgument`

Reserved for use by the operating system.

### `LastSyscallNumber`

Reserved for use by the operating system.

### `CreateTime`

The time the thread was created. For more information, see [FILETIME](https://learn.microsoft.com/windows/desktop/api/minwinbase/ns-minwinbase-filetime).

### `ExitTime`

If the thread exited, the time of the exit. For more information, see [FILETIME](https://learn.microsoft.com/windows/desktop/api/minwinbase/ns-minwinbase-filetime).

### `KernelTime`

The amount of time the thread spent executing in kernel mode. For more information, see [FILETIME](https://learn.microsoft.com/windows/desktop/api/minwinbase/ns-minwinbase-filetime).

### `UserTime`

The amount of time the thread spent executing in user mode. For more information, see [FILETIME](https://learn.microsoft.com/windows/desktop/api/minwinbase/ns-minwinbase-filetime).

### `Win32StartAddress`

A pointer to the thread procedure for thread.

### `CaptureTime`

The capture time of this thread. For more information, see [FILETIME](https://learn.microsoft.com/windows/desktop/api/minwinbase/ns-minwinbase-filetime).

### `Flags`

Flags about the thread. For more information, see [PSS_THREAD_FLAGS](https://learn.microsoft.com/previous-versions/windows/desktop/api/processsnapshot/ne-processsnapshot-pss_thread_flags).

### `SuspendCount`

The count of times the thread suspended.

### `SizeOfContextRecord`

The size of *ContextRecord*, in bytes.

### `ContextRecord`

A pointer to the context record if thread context information was captured. The pointer is valid for the lifetime of the walk marker passed to [PssWalkSnapshot](https://learn.microsoft.com/previous-versions/windows/desktop/api/processsnapshot/nf-processsnapshot-psswalksnapshot).

## Remarks

[PssWalkSnapshot](https://learn.microsoft.com/previous-versions/windows/desktop/api/processsnapshot/nf-processsnapshot-psswalksnapshot) returns a **PSS_THREAD_ENTRY** structure when the [PSS_WALK_INFORMATION_CLASS](https://learn.microsoft.com/previous-versions/windows/desktop/api/processsnapshot/ne-processsnapshot-pss_walk_information_class) member that the caller provides it is **PSS_WALK_THREADS**.

## See also

[Process Snapshotting](https://learn.microsoft.com/previous-versions/windows/desktop/proc_snap/process-snapshotting-portal)