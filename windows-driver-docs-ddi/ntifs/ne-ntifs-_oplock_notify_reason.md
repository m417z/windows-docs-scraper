# _OPLOCK_NOTIFY_REASON enumeration

## Description

OPLOCK_NOTIFY_REASON specifies the reason for calling the notification callback provided to [**FsRtlCheckOplockEx2**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-_fsrtl_advanced_fcb_header-fsrtlcheckoplockex2).

## Constants

### `OPLOCK_NOTIFY_BREAK_WAIT_INTERIM_TIMEOUT`

The first blocking wait for an opportunistic lock (oplock) break timed out.

### `OPLOCK_NOTIFY_BREAK_WAIT_TERMINATED`

The wait for an oplock break is completed, successfully or otherwise. If successful, the *Status* field of [OPLOCK_NOTIFY_PARAMS](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/ns-ntifs-_oplock_notify_params) is STATUS_SUCCESS; otherwise, *Status* is set to indicate the reason for the termination.

## Remarks

The OPLOCK_NOTIFY_REASON is specified in the *NotifyReason* member of the OPLOCK_NOTIFY_PARAMS structure.

## See also

[**FsRtlCheckOplockEx2**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-_fsrtl_advanced_fcb_header-fsrtlcheckoplockex2)

[OPLOCK_NOTIFY_PARAMS](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/ns-ntifs-_oplock_notify_params)