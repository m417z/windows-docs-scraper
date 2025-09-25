# FsRtlNotifyFilterReportChange function

## Description

**FsRtlNotifyFilterReportChange** completes IRP_MN_NOTIFY_CHANGE_DIRECTORY requests that are pending in the specified notify list.

## Parameters

### `NotifySync` [in]

Pointer to an opaque synchronization object for the change directory notify list that is pointed to by the *NotifyList* parameter.

### `NotifyList` [in]

Pointer to the head of the change directory notify list for the current volume. Each element in the list is an opaque notify structure.

### `FullTargetName` [in]

Pointer to an ANSI or Unicode string that contains the full pathname of the file or directory that changed.

### `TargetNameOffset` [in]

Offset, in bytes, within the *FullTargetName* string of the final component of the file name for the file or directory that changed.

### `StreamName` [in, optional]

Optional pointer to an ANSI or Unicode string that contains a stream name to store with the file name.

### `NormalizedParentName` [in, optional]

Optional pointer to an ANSI or Unicode string that contains the same path as in the *FullTargetName* string, but with all short names replaced by the corresponding long names.

### `FilterMatch` [in]

Bitmask of flags to be compared with the completion filter in the notify structure. If any of the corresponding bits in the completion filter are set, then a notify condition exists. For possible flag values, see the *CompletionFilter* parameter of [FsRtlNotifyFilterChangeDirectory](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-_fsrtl_advanced_fcb_header-fsrtlnotifyfilterchangedirectory).

### `Action` [in]

Specifies the action code to store in the user's buffer if present. For possible action code values, see the *Action* parameter of [FsRtlNotifyFullReportChange](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-_fsrtl_advanced_fcb_header-fsrtlnotifyfullreportchange).

### `TargetContext` [in, optional]

Context pointer to pass to the file system if performing a traverse check in the case of a tree being watched. For more information, see the *TraverseCallback* parameter of [FsRtlNotifyFilterChangeDirectory](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-_fsrtl_advanced_fcb_header-fsrtlnotifyfilterchangedirectory).

### `FilterContext` [in, optional]

Context pointer to pass to the filter callback routine. For more information, see the *FilterCallback* parameter of [FsRtlNotifyFilterChangeDirectory](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-_fsrtl_advanced_fcb_header-fsrtlnotifyfilterchangedirectory).

## Remarks

A file system that has received an IRP with major function code [IRP_MJ_DIRECTORY_CONTROL](https://learn.microsoft.com/windows-hardware/drivers/ifs/irp-mj-directory-control), minor function code IRP_MN_NOTIFY_CHANGE_DIRECTORY, calls [FsRtlNotifyFilterChangeDirectory](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-_fsrtl_advanced_fcb_header-fsrtlnotifyfilterchangedirectory) to create a notify structure to hold the IRP and add the notify structure to the notify list for the current volume.

When a change occurs to the directory, the file system calls **FsRtlNotifyFilterReportChange** to complete the pending IRP_MN_NOTIFY_CHANGE_DIRECTORY requests in the notify list.

## See also

[FsRtlNotifyFilterChangeDirectory](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-_fsrtl_advanced_fcb_header-fsrtlnotifyfilterchangedirectory)

[FsRtlNotifyFullChangeDirectory](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-_fsrtl_advanced_fcb_header-fsrtlnotifyfullchangedirectory)

[FsRtlNotifyFullReportChange](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-_fsrtl_advanced_fcb_header-fsrtlnotifyfullreportchange)

[IRP_MJ_DIRECTORY_CONTROL](https://learn.microsoft.com/windows-hardware/drivers/ifs/irp-mj-directory-control)