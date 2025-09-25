## Description

The **FsRtlSetupAdvancedHeaderEx2** macro is used by file systems to initialize an [**FSRTL_ADVANCED_FCB_HEADER**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/ns-ntifs-_fsrtl_advanced_fcb_header) structure for use with stream and file contexts.

## Parameters

### `_advhdr`

Pointer to the [**FSRTL_ADVANCED_FCB_HEADER**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/ns-ntifs-_fsrtl_advanced_fcb_header) structure to be initialized.

### `_fmutx`

Pointer to an initialized fast mutex that will be used to synchronize access to certain [**FSRTL_ADVANCED_FCB_HEADER**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/ns-ntifs-_fsrtl_advanced_fcb_header) members. The fast mutex must be allocated from nonpaged pool. This parameter is optional and can be **NULL**. Callers should set this parameter to **NULL** if they intend to use an already existing fast mutex object. If **FastMutex** is **NULL**, the caller must explicitly set the **FastMutex** member of the **FSRTL_ADVANCED_FCB_HEADER** structure, contained in the stream context object, to point to the existing fast mutex. (This can be done before or after calling **FsRtlSetupAdvancedHeaderEx2**.)

### `_fctxptr`

A pointer to a pointer field used by the file system runtime library (FSRTL) to track file contexts. This parameter is optional and can be **NULL**. If **FileContextSupportPointer** is not **NULL**, **FileContextSupportPointer** must be a pointer to a PVOID variable inside a per-file structure for the file system that created the structure. To indicate that the file system driver does not support file contexts, callers must set **FileContextSupportPointer** to **NULL**.

### `_aepushlock`

Pointer to an opaque structure used to initialize the **AePushLock** field of the [advanced header](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/ns-ntifs-_fsrtl_advanced_fcb_header). The caller of this function is responsible for first allocating and initializing the memory for this field by calling [**FsRtlAllocateAePushLock**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-fsrtlallocateaepushlock), and subsequently freeing the memory by calling [**FsRtlFreeAePushLock**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-fsrtlfreeaepushlock). See [**FSRTL_ADVANCED_FCB_HEADER**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/ns-ntifs-_fsrtl_advanced_fcb_header) for more information about auto-expand push locks.

## Remarks

File systems use the **FsRtlSetupAdvancedHeaderEx2** macro to initialize an [**FSRTL_ADVANCED_FCB_HEADER**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/ns-ntifs-_fsrtl_advanced_fcb_header) structure for use with stream and file contexts.

When the advanced FCB header structure is no longer required, the file system must call [**FsRtlTeardownPerStreamContexts**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-fsrtlteardownperstreamcontexts) to free all associated stream and file context structures.

For more information, see [Tracking Per-Stream Context in a Legacy File System Filter Driver](https://learn.microsoft.com/windows-hardware/drivers/ifs/tracking-per-stream-context-in-a-legacy-file-system-filter-driver).

## See also

[**FSRTL_ADVANCED_FCB_HEADER**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/ns-ntifs-_fsrtl_advanced_fcb_header)

[**FSRTL_PER_STREAM_CONTEXT**](https://learn.microsoft.com/previous-versions/ff547357(v=vs.85))

[**FsRtlAllocateAePushLock**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-fsrtlallocateaepushlock)

[**FsRtlFreeAePushLock**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-fsrtlfreeaepushlock)

[**FsRtlInitPerStreamContext**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-fsrtlinitperstreamcontext)

[**FsRtlInsertPerStreamContext**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-fsrtlinsertperstreamcontext)

[**FsRtlLookupPerStreamContext**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-fsrtllookupperstreamcontext)

[**FsRtlRemovePerStreamContext**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-fsrtlremoveperstreamcontext)

[**FsRtlSupportsPerStreamContexts**](https://learn.microsoft.com/previous-versions/ff547285(v=vs.85))

[**FsRtlTeardownPerStreamContexts**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-fsrtlteardownperstreamcontexts)