# FsRtlInsertPerFileObjectContext function

## Description

For a "legacy" file system filter driver, the **FsRtlInsertPerFileObjectContext** function associates context information with a file object.

## Parameters

### `FileObject` [in]

A pointer to the file object for which to associate context information (given by the *Ptr* parameter).

### `Ptr` [in]

A pointer to a caller-allocated and initialized FSRTL_PER_FILEOBJECT_CONTEXT structure to be associated with *FileObject*. The structure can be used as-is or embedded in a driver-defined, per-file-object context information structure. To initialize the structure, use the [FsRtlInitPerFileObjectContext](https://learn.microsoft.com/previous-versions/ff546170(v=vs.85)) macro.

## Return value

**FsRtlInsertPerFileObjectContext** returns an appropriate NTSTATUS value, such as one of the following:

| Return code | Description |
| --- | --- |
| **STATUS_SUCCESS** | The context information structure was successfully associated with the file object. |
| **STATUS_INVALID_PARAMETER** | The *FileObject* parameter is **NULL**. |
| **STATUS_INSUFFICIENT_RESOURCES** | The system lacks sufficient resources to complete the operation. For example, a file object extension could not be allocated for *FileObject*. |

## Remarks

A file system filter driver calls **FsRtlInsertPerFileObjectContext** to associate its own per-file-object context structure with a file object. The context structure contains context information that the filter driver maintains for the file object. The **FsRtlInsertPerStreamContext** function inserts the *Ptr* context structure into the context list for *FileObject*.

All per-file-object context information structures must be or contain an initialized FSRTL_PER_FILEOBJECT_CONTEXT structure. Use the [FsRtlInitPerFileObjectContext](https://learn.microsoft.com/previous-versions/ff546170(v=vs.85)) macro to initialize a FSRTL_PER_FILEOBJECT_CONTEXT structure.

After a FSRTL_PER_FILEOBJECT_CONTEXT structure or filter-defined per-file-object context structure (containing an initialized FSRTL_PER_FILEOBJECT_CONTEXT structure) has been associated with a file object, it can be retrieved by calling [FsRtlLookupPerFileObjectContext](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-fsrtllookupperfileobjectcontext) or removed by calling [FsRtlRemovePerFileObjectContext](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-fsrtlremoveperfileobjectcontext).

**Note** File system minifilter drivers must not use the **FsRtl***Xxx***PerFileObjectContext** functions. Instead, minifilters can use the **Flt***Xxx***Context** functions to associate context information with a file object. For a complete list, see the [FSRTL_PER_FILEOBJECT_CONTEXT](https://learn.microsoft.com/previous-versions/ff547346(v=vs.85)) topic.

## See also

[FSRTL_PER_FILEOBJECT_CONTEXT](https://learn.microsoft.com/previous-versions/ff547346(v=vs.85))

[FsRtlInitPerFileObjectContext](https://learn.microsoft.com/previous-versions/ff546170(v=vs.85))

[FsRtlLookupPerFileObjectContext](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-fsrtllookupperfileobjectcontext)

[FsRtlRemovePerFileObjectContext](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-fsrtlremoveperfileobjectcontext)