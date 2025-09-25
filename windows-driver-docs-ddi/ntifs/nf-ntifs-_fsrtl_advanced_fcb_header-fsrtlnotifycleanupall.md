# FsRtlNotifyCleanupAll function

## Description

The **FsRtlNotifyCleanupAll** routine removes all members of the specified notification list.

## Parameters

### `NotifySync` [in]

A pointer to the opaque synchronization object for *NotifyList*.

### `NotifyList` [in]

A pointer to the head of the notify list to be cleaned up. Each element in the list is an opaque notify structure.

## Remarks

For each entry in the *NotifyList* list, **FsRtlNotifyCleanupAll** completes all pending IRPs. Then the routine removes the entry from the list and deallocates the entry.

Because a notify list is typically associated with a volume, the **FsRtlNotifyCleanupAll** routine can be used to complete all the IRP requests for the volume.

## See also

[FsRtlNotifyCleanup](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-_fsrtl_advanced_fcb_header-fsrtlnotifycleanup)

[FsRtlNotifyFilterChangeDirectory](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-_fsrtl_advanced_fcb_header-fsrtlnotifyfilterchangedirectory)

[FsRtlNotifyFilterReportChange](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-_fsrtl_advanced_fcb_header-fsrtlnotifyfilterreportchange)

[FsRtlNotifyFullChangeDirectory](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-_fsrtl_advanced_fcb_header-fsrtlnotifyfullchangedirectory)

[FsRtlNotifyFullReportChange](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-_fsrtl_advanced_fcb_header-fsrtlnotifyfullreportchange)