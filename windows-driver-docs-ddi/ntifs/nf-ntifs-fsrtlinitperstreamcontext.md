# FsRtlInitPerStreamContext macro

## Description

The **FsRtlInitPerStreamContext** macro initializes a filter driver context structure.

## Parameters

### `_fc`

Pointer to a caller-allocated FSRTL_PER_STREAM_CONTEXT structure to be used to maintain context information for a file stream. This structure can be used as is or embedded in a driver-defined per-stream context structure. Both structure types are commonly allocated by calling [**ExAllocatePoolWithTag**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-exallocatepoolwithtag).

### `_owner`

Pointer to a caller-allocated variable that uniquely identifies the owner of the per-stream context structure. The format of this variable is filter driver − specific. Filter writers should choose a value that is both meaningful and convenient, such as the address of a driver object or device object. Callers must specify a non-**NULL** value for this parameter.

### `_inst`

Pointer to a filter driver − allocated variable that can be used to distinguish among per-stream context structures created by the same filter driver. The format of this variable is filter driver − specific. Filter writers should choose a value that is both meaningful and convenient, such as the address of the stream context object for the file stream. (To get this address from a file object, use the [**FsRtlGetPerStreamContextPointer**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-fsrtlgetperstreamcontextpointer) macro.) This parameter is optional and can be **NULL**.

### `_cb`

Pointer to a callback routine that frees the per-stream context structure. Callers must specify a non-**NULL** value for this parameter. This routine and its parameters are defined as follows:

|  |
| --- |
| ``` typedef VOID (*PFREE_FUNCTION) (           IN PVOID Buffer           ); ``` |

*Buffer*

Pointer to the per-stream context structure to be freed. The *FreeCallback* routine typically casts this pointer to the appropriate structure pointer type and frees it by calling [**ExFreePool**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-exfreepool).

## Remarks

A file system filter driver uses the **FsRtlInitPerStreamContext** macro to initialize a newly allocated per-stream context structure before associating it with a file stream. The initialized context structure can be passed as a parameter to [FsRtlInsertPerStreamContext](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-fsrtlinsertperstreamcontext).

**FsRtlInitPerStreamContext** stores the address of the *FreeCallback* routine in the **FreeCallback** member of the FSRTL_PER_STREAM_CONTEXT structure.

The *FreeCallback* routine is called at IRQL <= APC_LEVEL. Usually, it is called at IRQL PASSIVE_LEVEL.

**Note** The *FreeCallback* routine cannot recursively call down into the file system or acquire any file system resources. Also, this routine must assume that the file object for the file stream has already been freed.

To associate an initialized per-stream context structure with a file stream, call [FsRtlInsertPerStreamContext](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-fsrtlinsertperstreamcontext).

After the context structure has been associated with a file stream, it can be retrieved by calling [FsRtlLookupPerStreamContext](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-fsrtllookupperstreamcontext) or removed by calling [FsRtlRemovePerStreamContext](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-fsrtlremoveperstreamcontext).

For more information, see [Tracking Per-Stream Context in a Legacy File System Filter Driver](https://learn.microsoft.com/windows-hardware/drivers/ifs/tracking-per-stream-context-in-a-legacy-file-system-filter-driver).

## See also

[ExAllocatePoolWithTag](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-exallocatepoolwithtag)

[ExFreePool](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-exfreepool)

[FSRTL_PER_STREAM_CONTEXT](https://learn.microsoft.com/previous-versions/ff547357(v=vs.85))

[FsRtlGetPerStreamContextPointer](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-fsrtlgetperstreamcontextpointer)

[FsRtlInsertPerStreamContext](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-fsrtlinsertperstreamcontext)

[FsRtlLookupPerStreamContext](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-fsrtllookupperstreamcontext)

[FsRtlRemovePerStreamContext](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-fsrtlremoveperstreamcontext)

[FsRtlSetupAdvancedHeader](https://learn.microsoft.com/previous-versions/ff547257(v=vs.85))

[FsRtlSupportsPerStreamContexts](https://learn.microsoft.com/previous-versions/ff547285(v=vs.85))

[FsRtlTeardownPerStreamContexts](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-fsrtlteardownperstreamcontexts)