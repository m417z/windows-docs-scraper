# FsRtlNotifyInitializeSync function

## Description

The **FsRtlNotifyInitializeSync** routine allocates and initializes a synchronization object for a notify list.

## Parameters

### `NotifySync` [in]

A pointer to a location in which to return a pointer to the opaque synchronization object.

## Remarks

The system allocates the synchronization object from nonpaged pool. If a pool allocation failure occurs, **FsRtlNotifyInitializeSync** raises a STATUS_INSUFFICIENT_RESOURCES exception. To gain control if this pool allocation failure occurs, the driver should wrap the call to **FsRtlNotifyInitializeSync** in a **try-except** or **try-finally** statement.

Every successful call to **FsRtlNotifyInitializeSync** must be matched by a subsequent call to [FsRtlNotifyUninitializeSync](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-_fsrtl_advanced_fcb_header-fsrtlnotifyuninitializesync).

## See also

[FsRtlNotifyUninitializeSync](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-_fsrtl_advanced_fcb_header-fsrtlnotifyuninitializesync)