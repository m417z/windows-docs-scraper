# FSCTL_OPLOCK_BREAK_ACKNOWLEDGE control code

The **FSCTL_OPLOCK_BREAK_ACKNOWLEDGE** control code responds to notification that an exclusive (level 1, batch, or filter) opportunistic lock (oplock) on a file has been broken.

A client application sends this control code to indicate that it acknowledges the oplock break and that, if the oplock is a level 1 oplock that was broken to level 2, it does want the level 2 oplock.

To process this control code, a minifilter calls [**FltOplockFsctrl**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltoplockfsctrl) with the following parameters. A file system or legacy filter driver calls [**FsRtlOplockFsctrl**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-_fsrtl_advanced_fcb_header-fsrtloplockfsctrl).

For more information about opportunistic locking and about the **FSCTL_OPLOCK_BREAK_ACKNOWLEDGE** control code, see the Microsoft Windows SDK documentation.

## Parameters

- **Oplock**: Opaque oplock object pointer for the file.

- **CallbackData**: [**FltOplockFsctrl**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltoplockfsctrl) only. Callback data ([**FLT_CALLBACK_DATA**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/ns-fltkernel-_flt_callback_data)) structure for an IRP_MJ_FILE_SYSTEM_CONTROL FSCTL request. The **FsControlCode** parameter for the operation must be FSCTL_OPLOCK_BREAK_ACKNOWLEDGE.

- **Irp**: [**FsRtlOplockFsctrl**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-_fsrtl_advanced_fcb_header-fsrtloplockfsctrl) only. IRP for an IRP_MJ_FILE_SYSTEM_CONTROL FSCTL request. The **FsControlCode** parameter for the operation must be FSCTL_OPLOCK_BREAK_ACKNOWLEDGE.

- **OpenCount**: Not used with this operation; set to zero.

## Status block

[**FltOplockFsctrl**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltoplockfsctrl) returns FLT_PREOP_PENDING for this operation when a level 1 oplock is broken to level 2, and the level 2 oplock has been granted. Otherwise, it returns FLT_PREOP_COMPLETE.

[**FsRtlOplockFsctrl**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-_fsrtl_advanced_fcb_header-fsrtloplockfsctrl) returns one of the following NTSTATUS values for this operation:

| Code | Meaning |
| ---- | ------- |
| STATUS_SUCCESS | The oplock break is acknowledged. No remaining oplocks are held. |
| STATUS_INVALID_OPLOCK_PROTOCOL | No oplock was held by this handle, or the oplock break is not currently in progress. This is an error code. |
| STATUS_PENDING | The oplock break is acknowledged. On return, the sender of the **FSCTL_OPLOCK_BREAK_ACKNOWLEDGE** control code holds a level 2 oplock. This is a success code. |

## Requirements

| Requirement type | Requirement |
| ---------------- | ----------- |
| Header | *Ntifs.h* (include *Ntifs.h* or *Fltkernel.h*) |

## See also

[**FLT_CALLBACK_DATA**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/ns-fltkernel-_flt_callback_data)

[**FLT_PARAMETERS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/ns-fltkernel-_flt_parameters)

[**FLT_PARAMETERS for IRP_MJ_FILE_SYSTEM_CONTROL**](https://learn.microsoft.com/windows-hardware/drivers/ifs/flt-parameters-for-irp-mj-file-system-control)

[**FltOplockFsctrl**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltoplockfsctrl)

[**FSCTL_OPBATCH_ACK_CLOSE_PENDING**](https://learn.microsoft.com/windows-hardware/drivers/ifs/fsctl-opbatch-ack-close-pending)

[**FSCTL_OPLOCK_BREAK_ACK_NO_2**](https://learn.microsoft.com/windows-hardware/drivers/ifs/fsctl-oplock-break-ack-no-2)

[**FSCTL_OPLOCK_BREAK_NOTIFY**](https://learn.microsoft.com/windows-hardware/drivers/ifs/fsctl-oplock-break-notify)

[**FSCTL_REQUEST_BATCH_OPLOCK**](https://learn.microsoft.com/windows-hardware/drivers/ifs/fsctl-request-batch-oplock)

[**FSCTL_REQUEST_FILTER_OPLOCK**](https://learn.microsoft.com/windows-hardware/drivers/ifs/fsctl-request-filter-oplock)

[**FSCTL_REQUEST_OPLOCK_LEVEL_1**](https://learn.microsoft.com/windows-hardware/drivers/ifs/fsctl-request-oplock-level-1)

[**FSCTL_REQUEST_OPLOCK_LEVEL_2**](https://learn.microsoft.com/windows-hardware/drivers/ifs/fsctl-request-oplock-level-2)

[**FsRtlOplockFsctrl**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-_fsrtl_advanced_fcb_header-fsrtloplockfsctrl)

[**IRP_MJ_FILE_SYSTEM_CONTROL**](https://learn.microsoft.com/windows-hardware/drivers/ifs/irp-mj-file-system-control)