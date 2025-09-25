# FsRtlNotifyFullReportChange function

## Description

The **FsRtlNotifyFullReportChange** routine completes pending notify change IRPs.

## Parameters

### `NotifySync` [in]

A pointer to an opaque synchronization object for the current volume.

### `NotifyList` [in]

A pointer to the head of a notify list. Each element in the list is an opaque notify structure.

### `FullTargetName` [in]

A pointer to an ANSI or Unicode string that contains the full pathname of the file.

### `TargetNameOffset` [in]

Offset within the *FullTargetName* string of the final component of the name.

### `StreamName` [in, optional]

Optional pointer to an ANSI or Unicode string that contains a stream name to store with the file name.

### `NormalizedParentName` [in, optional]

Optional pointer to an ANSI or Unicode string that contains the same path as in the *FullTargetName* string, but with all short names replaced by the corresponding long names.

### `FilterMatch` [in]

A bitmask of flags to be compared with the completion filter in the notify structure. If any of the corresponding bits in the completion filter are set, then a notify condition exists. For possible flag values, see the *CompletionFilter* parameter of [FsRtlNotifyFullChangeDirectory](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-_fsrtl_advanced_fcb_header-fsrtlnotifyfullchangedirectory).

### `Action` [in]

Specifies the action code to store in the user's buffer if present. The action code can be one of the values described following.

| Action Code | Meaning |
| --- | --- |
| FILE_ACTION_ADDED | A new file or subdirectory has been created. |
| FILE_ACTION_REMOVED | A file or subdirectory has been deleted. |
| FILE_ACTION_MODIFIED | A file or subdirectory has been modified (but not created or deleted). |
| FILE_ACTION_RENAMED_OLD_NAME | This is the old name of a file that has been renamed. |
| FILE_ACTION_RENAMED_NEW_NAME | This is the new name of a file that has been renamed. |
| FILE_ACTION_ADDED_STREAM | A new stream has been opened. |
| FILE_ACTION_REMOVED_STREAM | A stream has been closed. |
| FILE_ACTION_MODIFIED_STREAM | A stream has been modified (but not opened or closed). |
| FILE_ACTION_REMOVED_BY_DELETE | An object ID has been removed from the index by a delete file operation. |
| FILE_ACTION_ID_NOT_TUNNELLED | An object ID for a file could not be tunneled because its object ID matched the ID of an already existing file. |
| FILE_ACTION_TUNNELLED_ID_COLLISION | An object ID for a file could not be tunneled because the file already has an object ID. |

### `TargetContext` [in, optional]

Context pointer to pass to the file system if performing a traverse check in the case of a tree being watched. For more information, see the *TraverseCallback* parameter of [FsRtlNotifyFullChangeDirectory](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-_fsrtl_advanced_fcb_header-fsrtlnotifyfullchangedirectory).

## Remarks

**FsRtlNotifyFullReportChange** is called by a file system when a file is modified so that pending notify change IRPs can be completed.

**FsRtlNotifyFullReportChange** looks for a notify structure in the notify list that matches the specified filter and pathname. If a match is found, **FsRtlNotifyFullReportChange** completes all pending IRPs for the notify structure.

## See also

[FsRtlNotifyFullChangeDirectory](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-_fsrtl_advanced_fcb_header-fsrtlnotifyfullchangedirectory)