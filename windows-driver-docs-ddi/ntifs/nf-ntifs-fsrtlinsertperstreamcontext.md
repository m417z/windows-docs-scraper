# FsRtlInsertPerStreamContext function

## Description

The **FsRtlInsertPerStreamContext** routine associates a file system filter driver's per-stream context structure with a file stream.

## Parameters

### `PerStreamContext`

Pointer to the FSRTL_ADVANCED_FCB_HEADER structure for the file stream. To get this pointer from a file object, use the [**FsRtlGetPerStreamContextPointer**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-fsrtlgetperstreamcontextpointer) macro.

### `Ptr` [in]

Pointer to a FSRTL_PER_STREAM_CONTEXT structure that the filter driver has allocated and initialized. To initialize this structure, use the [FsRtlInitPerStreamContext](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-fsrtlinitperstreamcontext) macro.

## Return value

**FsRtlInsertPerStreamContext** returns one of the following NTSTATUS values:

| Return code | Description |
| --- | --- |
| **STATUS_SUCCESS** | The call to **FsRtlInsertPerStreamContext** was successful. |
| **STATUS_INVALID_DEVICE_REQUEST** | The underlying file system does not support filter contexts. |

## Remarks

A file system filter driver calls **FsRtlInsertPerStreamContext** to associate its own per-stream context structure with a file stream. The per-stream context structure contains context information that the filter driver maintains for the file stream.

After the per-stream context structure has been associated with a file stream, it can be retrieved by calling [FsRtlLookupPerStreamContext](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-fsrtllookupperstreamcontext) or removed by calling [FsRtlRemovePerStreamContext](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-fsrtlremoveperstreamcontext).

For more information, see [Tracking Per-Stream Context in a Legacy File System Filter Driver](https://learn.microsoft.com/windows-hardware/drivers/ifs/tracking-per-stream-context-in-a-legacy-file-system-filter-driver).

## See also

[FSRTL_ADVANCED_FCB_HEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/ns-ntifs-_fsrtl_advanced_fcb_header)

[FSRTL_PER_STREAM_CONTEXT](https://learn.microsoft.com/previous-versions/ff547357(v=vs.85))

[FsRtlGetPerStreamContextPointer](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-fsrtlgetperstreamcontextpointer)

[FsRtlInitPerStreamContext](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-fsrtlinitperstreamcontext)

[FsRtlLookupPerStreamContext](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-fsrtllookupperstreamcontext)

[FsRtlRemovePerStreamContext](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-fsrtlremoveperstreamcontext)

[FsRtlSetupAdvancedHeader](https://learn.microsoft.com/previous-versions/ff547257(v=vs.85))

[FsRtlSupportsPerStreamContexts](https://learn.microsoft.com/previous-versions/ff547285(v=vs.85))

[FsRtlTeardownPerStreamContexts](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-fsrtlteardownperstreamcontexts)