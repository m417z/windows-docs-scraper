# FsRtlLookupPerStreamContext macro

## Description

The **FsRtlLookupPerStreamContext** macro retrieves a per-stream context structure for a file stream.

## Parameters

### `_sc`

Pointer to the FSRTL_ADVANCED_FCB_HEADER structure for the file stream. To get this pointer from a file object, use the [**FsRtlGetPerStreamContextPointer**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-fsrtlgetperstreamcontextpointer) macro.

### `_oid`

Pointer to a caller-allocated variable that uniquely identifies the owner of the per-stream context structure. The format of this variable is filter driver − specific. Must be non-**NULL** if a non-**NULL** value is supplied for *InstanceId*.

### `_iid`

Pointer to a filter driver − allocated variable that can be used to distinguish among per-stream context structures created by the same filter driver. The format of this variable is filter driver − specific.

If *OwnerId* and *InstanceId* are both **NULL**, **FsRtlLookupPerStreamContext** returns the first per-stream context found.

If a non-**NULL** value is supplied for *OwnerId* and *InstanceId* is **NULL**, **FsRtlLookupPerStreamContext** returns the first per-stream context found whose **OwnerId** member matches the *OwnerId* parameter.

## Remarks

A file system filter driver calls **FsRtlLookupPerStreamContext** to retrieve its per-stream context structure for a file stream. The per-stream context structure contains context information that the filter driver maintains for the file stream.

**Note** **FsRtlLookupPerStreamContext** can only be used on file systems that support per-stream contexts.

To initialize a per-stream context structure, use the [FsRtlInitPerStreamContext](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-fsrtlinitperstreamcontext) macro.

To associate an initialized per-stream context structure with a file stream, call [FsRtlInsertPerStreamContext](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-fsrtlinsertperstreamcontext).

To remove a per-stream context structure that is associated with a file stream, call [FsRtlRemovePerStreamContext](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-fsrtlremoveperstreamcontext).

For more information, see [Tracking Per-Stream Context in a Legacy File System Filter Driver](https://learn.microsoft.com/windows-hardware/drivers/ifs/tracking-per-stream-context-in-a-legacy-file-system-filter-driver).

## See also

[FSRTL_ADVANCED_FCB_HEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/ns-ntifs-_fsrtl_advanced_fcb_header)

[FSRTL_PER_STREAM_CONTEXT](https://learn.microsoft.com/previous-versions/ff547357(v=vs.85))

[FsRtlGetPerStreamContextPointer](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-fsrtlgetperstreamcontextpointer)

[FsRtlInitPerStreamContext](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-fsrtlinitperstreamcontext)

[FsRtlInsertPerStreamContext](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-fsrtlinsertperstreamcontext)

[FsRtlRemovePerStreamContext](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-fsrtlremoveperstreamcontext)

[FsRtlSetupAdvancedHeader](https://learn.microsoft.com/previous-versions/ff547257(v=vs.85))

[FsRtlSupportsPerStreamContexts](https://learn.microsoft.com/previous-versions/ff547285(v=vs.85))

[FsRtlTeardownPerStreamContexts](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-fsrtlteardownperstreamcontexts)