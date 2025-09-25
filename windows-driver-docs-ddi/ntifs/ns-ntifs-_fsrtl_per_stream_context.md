# _FSRTL_PER_STREAM_CONTEXT structure

## Description

The **FSRTL_PER_STREAM_CONTEXT** structure contains context information that a file system filter driver maintains about a file stream.

## Members

### `Links`

Link for this structure in the list of all per-stream context structures associated with the same file stream. [FsRtlInsertPerStreamContext](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-fsrtlinsertperstreamcontext) inserts this member into the list of all per-stream context structures for a file stream. To get a pointer to the head of the list from a file object, use the [FsRtlGetPerStreamContextPointer](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-fsrtlgetperstreamcontextpointer) macro, and cast the result to a **PFSRTL_ADVANCED_FCB_HEADER** pointer. The list pointer is the **FilterContexts** member in the advanced file control block (FCB) header structure for the file stream.

### `OwnerId`

Pointer to a filter-driver-allocated variable that uniquely identifies the owner of the per-stream context structure. The format of this variable is filter-driver-specific. Filter writers should choose a value that is both meaningful and convenient, such as the address of a driver object or device object. Filter drivers must set this member to a non-**NULL** value.

### `InstanceId`

Pointer to a filter-driver-allocated variable that can be used to distinguish among per-stream context structures created by the same filter driver. The format of this variable is filter-driver-specific. Filter writers should choose a value that is both meaningful and convenient, such as the address of the stream context object for the file stream. (To get this address from a file object, use the [FsRtlGetPerStreamContextPointer](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-fsrtlgetperstreamcontextpointer) macro.)

This member is optional and can be **NULL**.

### `FreeCallback`

Pointer to a callback routine that frees the per-stream context structure. This routine and its parameters are defined as follows:

```
VOID
(*PFREE_FUNCTION) (
     IN PVOID Buffer
     );
```

#### Buffer

Pointer to the **FSRTL_PER_STREAM_CONTEXT** structure to free.

## Remarks

File system filter drivers can use a **FSRTL_PER_STREAM_CONTEXT** structure to maintain context information for a file stream. This structure can be used as is or embedded in a driver-defined, per-stream context structure.

When a file system tears down the stream context object for a file stream, it must call [FsRtlTeardownPerStreamContexts](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-fsrtlteardownperstreamcontexts), which in turn calls the *FreeCallback* routines of all per-stream context structures associated with the file stream.

**Note** The *FreeCallback* routine cannot recursively call down into the file system or acquire any file system resources. Also, this routine must assume that the file object for the file stream has already been freed.

The **FSRTL_PER_STREAM_CONTEXT** structure can be allocated from paged or nonpaged pool.

The **FsRtlSupportsPerStreamContexts** macro determines whether a file system supports per-stream contexts for a given file stream.

```
BOOLEAN FsRtlSupportsPerStreamContexts(
  [in] PFILE_OBJECT FileObject
);
```

Parameters

*FileObject [in]*

**PFILE_OBJECT**

A pointer to a file object for the file stream.

Return value

**BOOLEAN**

The **FsRtlSupportsPerStreamContexts** macro returns **TRUE** if the file system supports per-stream contexts for the file stream, **FALSE** otherwise.

File system filter drivers call **FsRtlSupportsPerStreamContexts** to determine whether the underlying file system supports per-stream contexts for the file stream represented by a given file object. Note that a file system might support per-stream contexts for some types of files but not for others. For example, NTFS and FAT do not currently support per-stream contexts for paging files.

For more information, see [Tracking Per-Stream Context in a Legacy File System Filter Driver](https://learn.microsoft.com/windows-hardware/drivers/ifs/tracking-per-stream-context-in-a-legacy-file-system-filter-driver).

## See also

[FSRTL_ADVANCED_FCB_HEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/ns-ntifs-_fsrtl_advanced_fcb_header)

[FSRTL_COMMON_FCB_HEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/ns-ntifs-_fsrtl_common_fcb_header)

[FsRtlGetPerStreamContextPointer](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-fsrtlgetperstreamcontextpointer)

[FsRtlInsertPerStreamContext](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-fsrtlinsertperstreamcontext)

[FsRtlLookupPerStreamContext](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-fsrtllookupperstreamcontext)

[FsRtlRemovePerStreamContext](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-fsrtlremoveperstreamcontext)

[FsRtlTeardownPerStreamContexts](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-fsrtlteardownperstreamcontexts)

[PFREE_FUNCTION](https://learn.microsoft.com/windows-hardware/drivers/ifs/pfree-function)

[Tracking Per-Stream Context in a Legacy File System Filter Driver](https://learn.microsoft.com/windows-hardware/drivers/ifs/tracking-per-stream-context-in-a-legacy-file-system-filter-driver)