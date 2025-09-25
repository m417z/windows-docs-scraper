# FsRtlRemovePerFileObjectContext function

## Description

For a "legacy" file system filter driver, the **FsRtlRemovePerFileObjectContext** function unlinks a per-file-object context information structure from the list of per-file-object contexts previously associated with a file object.

## Parameters

### `FileObject` [in]

A pointer to a file object for which to remove context information.

### `OwnerId` [in, optional]

A pointer to a caller-allocated variable that uniquely identifies the owning filter of the per-file-object context structure. The format of this variable is filter-driver-specific.

### `InstanceId` [in, optional]

A pointer to a caller-allocated variable that can be used to distinguish among per-file-object context structures created by the same filter driver. The format of this variable is filter-driver-specific. This parameter is optional and can be **NULL**.

## Return value

**FsRtlRemovePerFileObjectContext** unlinks and returns a pointer to the first matching per-file-object context that is found. If no match is found, **FsRtlRemovePerFileObjectContext** returns **NULL**.

## Remarks

A "legacy" file system filter driver calls **FsRtlRemovePerFileObjectContext** to unlink its own per-file-object context structure from the list of per-file-object contexts associated with the file object. All such context structures must have previously been associated with the file object by calling [FsRtlInsertPerFileObjectContext](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-fsrtlinsertperfileobjectcontext).

If the call to **FsRtlRemovePerFileObjectContext** is successful, the first per-file-object context structure matching *OwnerId* (and *InstanceId*, if present) is unlinked and a pointer to it returned. This pointer can be used by the filter driver to free the unlinked context structure.

**Note** **FsRtlRemovePerFileObjectContext** unlinks only the first matching per-file-object context structure that is found. If there are additional matching per-file-object contexts, the filter driver must call **FsRtlRemovePerFileObjectContext** as many times as required to unlink them all.

To initialize a per-file-object context structure, use the [FsRtlInitPerFileObjectContext](https://learn.microsoft.com/previous-versions/ff546170(v=vs.85)) macro.

To associate an initialized per-file-object context structure with a file object, use the [FsRtlInsertPerFileObjectContext](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-fsrtlinsertperfileobjectcontext) function.

To retrieve a per-file-object context structure that is associated with a file object, use the [FsRtlLookupPerFileObjectContext](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-fsrtllookupperfileobjectcontext) function.

**Note** Legacy filter drivers must call the **FsRtlRemovePerFileObjectContext** function to unlink and free the context information structure before completion of IRP_MJ_CLOSE. Otherwise, the memory allocated to that context structure will be leaked.

Additionally, file system minifilter drivers must not use the **FsRtl***Xxx***PerFileObjectContext** functions. Instead, they can use the appropriate **Flt***Xxx***Context** functions. For additional information, see the [FSRTL_PER_FILEOBJECT_CONTEXT](https://learn.microsoft.com/previous-versions/ff547346(v=vs.85)) topic.

## See also

[FSRTL_PER_FILEOBJECT_CONTEXT](https://learn.microsoft.com/previous-versions/ff547346(v=vs.85))

[FsRtlInitPerFileObjectContext](https://learn.microsoft.com/previous-versions/ff546170(v=vs.85))

[FsRtlInsertPerFileObjectContext](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-fsrtlinsertperfileobjectcontext)

[FsRtlLookupPerFileObjectContext](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-fsrtllookupperfileobjectcontext)