# FsRtlNotifyUninitializeSync function

## Description

The **FsRtlNotifyUninitializeSync** routine deallocates the synchronization object for a notify list.

## Parameters

### `NotifySync` [in]

A pointer to a location that contains a pointer to the opaque synchronization object.

## Remarks

The **FsRtlNotifyUninitializeSync** routine deallocates an opaque synchronization object that was allocated by an earlier call to [FsRtlNotifyInitializeSync](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-_fsrtl_advanced_fcb_header-fsrtlnotifyinitializesync).

## See also

[FsRtlNotifyInitializeSync](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-_fsrtl_advanced_fcb_header-fsrtlnotifyinitializesync)