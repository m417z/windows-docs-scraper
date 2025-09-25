# VIRTUAL_DISK_PROGRESS structure

## Description

Contains the progress and result data for the current virtual hard disk (VHD) operation, used by the
[GetVirtualDiskOperationProgress](https://learn.microsoft.com/windows/win32/api/virtdisk/nf-virtdisk-getvirtualdiskoperationprogress)
function.

## Members

### `OperationStatus`

A [system error code](https://learn.microsoft.com/windows/desktop/Debug/system-error-codes) status value, this member will
be **ERROR_IO_PENDING** if the operation is still in progress; otherwise, the value is the
result code of the completed operation.

### `CurrentValue`

The current progress of the operation, used in conjunction with the
**CompletionValue** member.

This value is meaningful only if
**OperationStatus** is **ERROR_IO_PENDING**.

### `CompletionValue`

The value that the **CurrentValue** member would be if the operation were complete.

This value is meaningful only if **OperationStatus** is
**ERROR_IO_PENDING**.

## Remarks

The **CurrentValue** and **CompletionValue** members are
intended to be used for calculating a percentage value, and the specific numeric values of each are not
significant in any way. Only the result of the following calculation is meaningful:
**CurrentValue** divided by **CompletionValue** multiplied by 100
equals percent complete, up to and including 100 percent, even when **OperationStatus** is
still returning **ERROR_IO_PENDING**. This percentage is not always guaranteed to increase
with subsequent calls to the
[GetVirtualDiskOperationProgress](https://learn.microsoft.com/windows/win32/api/virtdisk/nf-virtdisk-getvirtualdiskoperationprogress)
function, and may decrease. These decreased percentages may be safely ignored if progress tracking is desired to
be only in the positive by locally storing the current maximum percentage.

The **CurrentValue** and **CompletionValue** members can vary in
subsequent calls to the
[GetVirtualDiskOperationProgress](https://learn.microsoft.com/windows/win32/api/virtdisk/nf-virtdisk-getvirtualdiskoperationprogress)
function, so they must be used together at the same time from the same call. That is, it is not valid to save
either of them locally and then make another call to the
**GetVirtualDiskOperationProgress**
function expecting to use either of the previous values with the other value from the more recent call.

The **OperationStatus** member is the indicator of completion, not the percent-complete
calculation described previously. As long as this data member is returning with an
**ERROR_IO_PENDING** status code, the I/O operation is not yet complete.

## See also

[About VHD](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/dd323654(v=vs.85))

[GetVirtualDiskOperationProgress](https://learn.microsoft.com/windows/win32/api/virtdisk/nf-virtdisk-getvirtualdiskoperationprogress)

[VHD Reference](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/dd323700(v=vs.85))