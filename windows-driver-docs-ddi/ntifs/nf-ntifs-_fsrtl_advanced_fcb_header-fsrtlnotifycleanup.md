# FsRtlNotifyCleanup function

## Description

When the last handle to a file object is released, the **FsRtlNotifyCleanup** routine removes the file object's notify structure, if present, from the specified notify list.

## Parameters

### `NotifySync` [in]

A pointer to an opaque synchronization object for *NotifyList*.

### `NotifyList` [in]

A pointer to the head of a notify list. Each element in the list is an opaque notify structure.

### `FsContext` [in]

A unique value assigned by the file system to identify a notify structure as belonging to a particular file object.

## Remarks

If a notify structure is found that matches *FsContext*, **FsRtlNotifyCleanup** completes all IRPs that are queued in the notify structure. When all the IRPs are completed, **FsRtlNotifyCleanup** removes the notify structure from the notify list and deallocates it.

## See also

[FsRtlNotifyFilterChangeDirectory](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-_fsrtl_advanced_fcb_header-fsrtlnotifyfilterchangedirectory)

[FsRtlNotifyFilterReportChange](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-_fsrtl_advanced_fcb_header-fsrtlnotifyfilterreportchange)

[FsRtlNotifyFullChangeDirectory](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-_fsrtl_advanced_fcb_header-fsrtlnotifyfullchangedirectory)

[FsRtlNotifyFullReportChange](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-_fsrtl_advanced_fcb_header-fsrtlnotifyfullreportchange)