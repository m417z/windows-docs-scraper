# FsRtlGetPerStreamContextPointer macro

## Description

The **FsRtlGetPerStreamContextPointer** macro returns the file system's stream context for a file stream.

## Parameters

### `_fo`

Pointer to a file object for the file stream.

## Remarks

File system filter drivers can use the **FsRtlGetPerStreamContextPointer** macro to obtain a stream context pointer for the file stream that is represented by a given file object. A stream context pointer is a pointer to the file system's stream context for the file stream. This pointer can be passed as a parameter to [FsRtlInsertPerStreamContext](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-fsrtlinsertperstreamcontext), [FsRtlLookupPerStreamContext](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-fsrtllookupperstreamcontext), and [FsRtlRemovePerStreamContext](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-fsrtlremoveperstreamcontext).

The stream context pointer points to a [FSRTL_ADVANCED_FCB_HEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/ns-ntifs-_fsrtl_advanced_fcb_header) structure that uniquely identifies the file stream to the file system. This structure is usually embedded in a stream context object, such as a file control block (FCB) or stream control block (SCB). When the file stream is opened, the file system stores a pointer to the FCB or SCB in the file object's **FsContext** member.

**Note** The **FsRtlGetPerStreamContextPointer** macro can only be used on file systems that support advanced FCB headers.

For more information, see [Tracking Per-Stream Context in a Legacy File System Filter Driver](https://learn.microsoft.com/windows-hardware/drivers/ifs/tracking-per-stream-context-in-a-legacy-file-system-filter-driver).

## See also

[FSRTL_ADVANCED_FCB_HEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/ns-ntifs-_fsrtl_advanced_fcb_header)

[FsRtlInitPerStreamContext](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-fsrtlinitperstreamcontext)

[FsRtlInsertPerStreamContext](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-fsrtlinsertperstreamcontext)

[FsRtlLookupPerStreamContext](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-fsrtllookupperstreamcontext)

[FsRtlRemovePerStreamContext](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-fsrtlremoveperstreamcontext)

[FsRtlSetupAdvancedHeader](https://learn.microsoft.com/previous-versions/ff547257(v=vs.85))

[FsRtlSupportsPerStreamContexts](https://learn.microsoft.com/previous-versions/ff547285(v=vs.85))

[FsRtlTeardownPerStreamContexts](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-fsrtlteardownperstreamcontexts)