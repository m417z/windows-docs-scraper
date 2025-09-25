# PSS_ALLOCATOR structure

## Description

Specifies custom functions which the Process Snapshotting functions use to allocate and free the internal walk marker structures.

## Members

### `Context`

An arbitrary pointer-sized value that the Process Snapshotting functions pass to **AllocRoutine** and **FreeRoutine**.

### `AllocRoutine`

A pointer to a WINAPI-calling convention function that takes two parameters. It returns a pointer to the block of memory that it allocates, or **NULL** if allocation fails.

#### Context

The context value, as passed in **PSS_ALLOCATOR**.

#### Size

Number of bytes to allocate.

### `FreeRoutine`

A pointer to a WINAPI-calling convention function taking two parameters. It deallocates a block of memory that **AllocRoutine** allocated.

#### Context

The context value, as passed in **PSS_ALLOCATOR**.

#### Address

The address of a block of memory that **AllocRoutine** allocated.

## Remarks

To use custom memory allocation functions, pass this structure to [PssWalkMarkerCreate](https://learn.microsoft.com/previous-versions/windows/desktop/api/processsnapshot/nf-processsnapshot-psswalkmarkercreate). Otherwise, the Process Snapshotting functions use the default process heap.

The **PSS_ALLOCATOR** structure that provides the custom functions should remain valid for the lifetime of the walk marker that [PssWalkMarkerCreate](https://learn.microsoft.com/previous-versions/windows/desktop/api/processsnapshot/nf-processsnapshot-psswalkmarkercreate) creates.

**FreeRoutine** must accept **NULL** address parameters without failing.

The custom functions are called from [PssWalkMarkerCreate](https://learn.microsoft.com/previous-versions/windows/desktop/api/processsnapshot/nf-processsnapshot-psswalkmarkercreate), [PssWalkMarkerFree](https://learn.microsoft.com/previous-versions/windows/desktop/api/processsnapshot/nf-processsnapshot-psswalkmarkerfree) and [PssWalkSnapshot](https://learn.microsoft.com/previous-versions/windows/desktop/api/processsnapshot/nf-processsnapshot-psswalksnapshot) using the same thread that calls **PssWalkMarkerCreate**, **PssWalkMarkerFree** and **PssWalkSnapshot**. Therefore the custom functions need not be multi-threaded.

## See also

[Process Snapshotting](https://learn.microsoft.com/previous-versions/windows/desktop/proc_snap/process-snapshotting-portal)