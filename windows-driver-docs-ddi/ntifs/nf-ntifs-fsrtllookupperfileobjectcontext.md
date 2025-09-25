# FsRtlLookupPerFileObjectContext function

## Description

For a "legacy" file system filter driver, the **FsRtlLookupPerFileObjectContext** function retrieves context information previously associated with a file object.

## Parameters

### `FileObject` [in]

A pointer to a file object for which to query context information.

### `OwnerId` [in, optional]

A pointer to a caller-allocated variable that uniquely identifies the owning filter of the per-file-object context structure. The format of this variable is filter-driver-specific.

### `InstanceId` [in, optional]

A pointer to a caller-allocated variable that can be used to distinguish among per-file-object context structures created by the same filter driver. The format of this variable is filter-driver-specific. This parameter is optional and can be **NULL**.

## Return value

**FsRtlLookupPerFileObjectContext** returns a pointer to the first matching per-file-object context that is found. If no match is found, **FsRtlLookupPerFileObjectContext** returns **NULL**.

## Remarks

A "legacy" file system filter driver calls **FsRtlLookupPerFileObjectContext** to retrieve its per-file-object context structure for a file object. The context structure contains context information that the filter driver maintains for the file object. This context structure must have previously been associated with the file object by calling the **FsRtlInsertPerFileObjectContext** function.

If the FSRTL_PER_FILEOBJECT_CONTEXT structure is embedded in a filter defined per-file-object context structure, the **CONTAINING_RECORD** macro can be used to obtain a pointer to the head of the filter-defined structure.

To initialize a per-file-object context structure, use the [FsRtlInitPerFileObjectContext](https://learn.microsoft.com/previous-versions/ff546170(v=vs.85)) macro.

To associate an initialized per-file-object context structure with a file object, use the **FsRtlInsertPerFileObjectContext** function.

To remove a per-file-object context structure that is associated with a file object, use the [FsRtlRemovePerFileObjectContext](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-fsrtlremoveperfileobjectcontext) function.

**Note** File system minifilter drivers must not use the **FsRtl***Xxx***PerFileObjectContext** functions. Instead, minifilters can use the **Flt***Xxx***Context** functions to associate context information with a file object. For a complete list, see the [FSRTL_PER_FILEOBJECT_CONTEXT](https://learn.microsoft.com/previous-versions/ff547346(v=vs.85)) topic.

## See also

[FSRTL_PER_FILEOBJECT_CONTEXT](https://learn.microsoft.com/previous-versions/ff547346(v=vs.85))

[FsRtlInitPerFileObjectContext](https://learn.microsoft.com/previous-versions/ff546170(v=vs.85))

[FsRtlInsertPerFileObjectContext](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-fsrtlinsertperfileobjectcontext)

[FsRtlRemovePerFileObjectContext](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-fsrtlremoveperfileobjectcontext)