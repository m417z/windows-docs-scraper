# FsRtlRemovePerStreamContext function

## Description

**FsRtlRemovePerStreamContext** removes a per-stream context structure from the list of per-stream contexts associated with a file stream.

## Parameters

### `StreamContext` [in]

Pointer to the FSRTL_ADVANCED_FCB_HEADER structure for the file stream. To get this pointer from a file object, use the [**FsRtlGetPerStreamContextPointer**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-fsrtlgetperstreamcontextpointer) macro.

### `OwnerId` [in, optional]

Used to identify context information as belonging to a particular filter driver.

### `InstanceId` [in, optional]

Used to search for a particular instance of a per-stream context. If not provided, any of the contexts owned by the filter driver is removed and returned.

If neither the **OwnerId** nor the **InstanceId** is provided, any associated per-stream context will be removed and returned.

## Return value

**FsRtlRemovePerStreamContext** returns a pointer to the per-stream context that is removed. If no match is found, or if the file system does not support filter contexts, **FsRtlRemovePerStreamContext** returns NULL.

## Remarks

A file system filter driver calls **FsRtlRemovePerStreamContext** to remove its own per-stream context structure from the list of per-stream contexts associated with a file stream.

**FsRtlRemovePerStreamContext** removes only the first matching per-stream context structure that is found. If there are additional matching per-stream contexts, the filter driver must call **FsRtlRemovePerStreamContext** as many times as required to remove them all.

This routine should only be used when a filter driver needs to discard the context information it has associated with a file stream while the stream is still open. For example, a filter driver might call **FsRtlRemovePerStreamContext** in the following cases:

* When it receives a request from a user-mode application to stop logging I/O requests on a particular volume.

* When it detects that a file or directory has been renamed.

When a file stream is closed, the file system is responsible for ensuring that all per-stream contexts associated with that stream are removed and freed. To do this, the file system must call [**FsRtlTeardownPerStreamContexts**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-fsrtlteardownperstreamcontexts) on the file control block (FCB) or other stream context object for the file stream. **FsRtlTeardownPerStreamContexts** walks the FilterContexts list, removing each entry and calling its **FreeCallback** routine.

Thus, a file system filter driver should not call **FsRtlRemovePerStreamContext** from within an IRP_MJ_CLOSE or IRP_MJ_PNP dispatch routine. Not only would such a call be unnecessary, but it might also interfere with the file system's call to [**FsRtlTeardownPerStreamContexts**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-fsrtlteardownperstreamcontexts).

A file system filter driver should not call **FsRtlRemovePerStreamContext** from within a per-stream context structure's **FreeCallback** routine. This is because the underlying file system calls the **FreeCallback** routine after it has already removed the context structure from the FilterContexts list.

To initialize a per-stream context structure, use the [**FsRtlInitPerStreamContext**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-fsrtlinitperstreamcontext) macro.

To associate an initialized per-stream context structure with a file stream, call [**FsRtlInsertPerStreamContext**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-fsrtlinsertperstreamcontext).

To retrieve a per-stream context structure that is associated with a file stream, call [**FsRtlLookupPerStreamContext**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-fsrtllookupperstreamcontext).

**FsRtlRemovePerStreamContext** can only be used on file systems that support filter contexts.

For more information, see [Tracking Per-Stream Context in a Legacy File System Filter Driver](https://learn.microsoft.com/windows-hardware/drivers/ifs/tracking-per-stream-context-in-a-legacy-file-system-filter-driver).

## See also

[**FSRTL_ADVANCED_FCB_HEADER**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/ns-ntifs-_fsrtl_advanced_fcb_header)

[**FSRTL_PER_STREAM_CONTEXT**](https://learn.microsoft.com/previous-versions/ff547357(v=vs.85))

[**FsRtlGetPerStreamContextPointer**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-fsrtlgetperstreamcontextpointer)

[**FsRtlInitPerStreamContext**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-fsrtlinitperstreamcontext)

[**FsRtlInsertPerStreamContext**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-fsrtlinsertperstreamcontext)

[**FsRtlLookupPerStreamContext**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-fsrtllookupperstreamcontext)

[**FsRtlSetupAdvancedHeader**](https://learn.microsoft.com/previous-versions/ff547257(v=vs.85))

[**FsRtlSupportsPerStreamContexts**](https://learn.microsoft.com/previous-versions/ff547285(v=vs.85))

[**FsRtlTeardownPerStreamContexts**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-fsrtlteardownperstreamcontexts)

[**IRP_MJ_CLOSE**](https://learn.microsoft.com/windows-hardware/drivers/kernel/irp-mj-close)

[**IRP_MJ_PNP**](https://learn.microsoft.com/windows-hardware/drivers/ifs/irp-mj-pnp)