# FsRtlTeardownPerStreamContexts function

## Description

The **FsRtlTeardownPerStreamContexts** routine frees all per-stream context structures associated with a given FSRTL_ADVANCED_FCB_HEADER structure.

## Parameters

### `AdvancedHeader` [in]

Pointer to the FSRTL_ADVANCED_FCB_HEADER structure.

## Remarks

File systems call **FsRtlTeardownPerStreamContexts** to free all per-stream context structures associated with a given FSRTL_ADVANCED_FCB_HEADER structure. When a file system tears down the stream context object for a file stream, it must call **FsRtlTeardownPerStreamContexts**, which in turn calls the *FreeCallback* routines of all per-stream context structures associated with the file stream.

To avoid conflicts in synchronization, the **FsRtlTeardownPerStreamContexts** routine releases the lock for the per file context objects before calling *FreeCallback*. This avoids blocking access to the to the per file context objects by the filter for own list operations, such as removal with [FsRtlRemovePerStreamContext](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-fsrtlremoveperstreamcontext).

## See also

[FSRTL_ADVANCED_FCB_HEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/ns-ntifs-_fsrtl_advanced_fcb_header)

[FSRTL_PER_STREAM_CONTEXT](https://learn.microsoft.com/previous-versions/ff547357(v=vs.85))

[FsRtlGetPerStreamContextPointer](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-fsrtlgetperstreamcontextpointer)

[FsRtlInitPerStreamContext](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-fsrtlinitperstreamcontext)

[FsRtlInsertPerStreamContext](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-fsrtlinsertperstreamcontext)

[FsRtlLookupPerStreamContext](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-fsrtllookupperstreamcontext)

[FsRtlRemovePerStreamContext](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-fsrtlremoveperstreamcontext)

[FsRtlSetupAdvancedHeader](https://learn.microsoft.com/previous-versions/ff547257(v=vs.85))

[FsRtlSupportsPerStreamContexts](https://learn.microsoft.com/previous-versions/ff547285(v=vs.85))

[Tracking Per-Stream Context in a Legacy File System Filter Driver](https://learn.microsoft.com/windows-hardware/drivers/ifs/tracking-per-stream-context-in-a-legacy-file-system-filter-driver)