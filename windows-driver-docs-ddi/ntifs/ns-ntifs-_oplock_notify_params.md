# _OPLOCK_NOTIFY_PARAMS structure

## Description

The OPLOCK_NOTIFY_PARAMS structure is passed as a parameter to a *NotifyRoutine* callback when such a callback is provided to [**FsRtlCheckOplockEx2**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-_fsrtl_advanced_fcb_header-fsrtlcheckoplockex2).

## Members

### `NotifyReason`

An [OPLOCK_NOTIFY_REASON](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/ne-ntifs-_oplock_notify_reason) enumeration value that specifies the reason for the notification callback.

### `NotifyContext`

Set to be the same value as **FsRtlCheckOplockEx2**'s *NotifyContext* parameter.

### `Irp`

Set to be the same value as **FsRtlCheckOplockEx2**'s *Irp* parameter.

### `Status`

The NT status code returned from the *NotifyRoutine* callback. The interpretation of the status code depends on the value of *NotifyReason*.

## Remarks

## See also

[**FsRtlCheckOplockEx2**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-_fsrtl_advanced_fcb_header-fsrtlcheckoplockex2)

[OPLOCK_NOTIFY_REASON](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/ne-ntifs-_oplock_notify_reason)