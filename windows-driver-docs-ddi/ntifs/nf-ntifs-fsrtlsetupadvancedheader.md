# FsRtlSetupAdvancedHeader function

## Description

The **FsRtlSetupAdvancedHeader** macro is used by file systems to initialize an [FSRTL_ADVANCED_FCB_HEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/ns-ntifs-_fsrtl_advanced_fcb_header) structure for use with filter contexts.

## Parameters

### `AdvHdr`

A pointer to the [**FSRTL_ADVANCED_FCB_HEADER**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/ns-ntifs-_fsrtl_advanced_fcb_header) structure to be initialized.

### `FMutex`

A pointer to an initialized fast mutex that will be used to synchronize access to the [**FSRTL_ADVANCED_FCB_HEADER**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/ns-ntifs-_fsrtl_advanced_fcb_header) structure. The fast mutex must be allocated from nonpaged pool.

This parameter can be **NULL**. Callers should set this parameter to **NULL** if they intend to use an already existing fast mutex object. If *FastMutex* is **NULL**, the caller must explicitly set the *FastMutex* member of the stream context object to point to the existing fast mutex. (This can be done before or after calling **FsRtlSetupAdvancedHeader**.)

## Remarks

File systems use the **FsRtlSetupAdvancedHeader** macro to initialize an [FSRTL_ADVANCED_FCB_HEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/ns-ntifs-_fsrtl_advanced_fcb_header) structure for use with filter contexts.

When the advanced FCB header structure is no longer required, the file system must call [FsRtlTeardownPerStreamContexts](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-fsrtlteardownperstreamcontexts) to free all associated per-stream context structures.

For more information, see [Tracking Per-Stream Context in a Legacy File System Filter Driver](https://learn.microsoft.com/windows-hardware/drivers/ifs/tracking-per-stream-context-in-a-legacy-file-system-filter-driver).

## See also

[FSRTL_ADVANCED_FCB_HEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/ns-ntifs-_fsrtl_advanced_fcb_header)

[FSRTL_PER_STREAM_CONTEXT](https://learn.microsoft.com/previous-versions/ff547357(v=vs.85))

[FsRtlGetPerStreamContextPointer](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-fsrtlgetperstreamcontextpointer)

[FsRtlInitPerStreamContext](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-fsrtlinitperstreamcontext)

[FsRtlInsertPerStreamContext](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-fsrtlinsertperstreamcontext)

[FsRtlLookupPerStreamContext](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-fsrtllookupperstreamcontext)

[FsRtlRemovePerStreamContext](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-fsrtlremoveperstreamcontext)

[FsRtlSupportsPerStreamContexts](https://learn.microsoft.com/previous-versions/ff547285(v=vs.85))

[FsRtlTeardownPerStreamContexts](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-fsrtlteardownperstreamcontexts)