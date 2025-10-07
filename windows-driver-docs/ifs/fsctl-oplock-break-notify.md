# FSCTL_OPLOCK_BREAK_NOTIFY control code

The **FSCTL_OPLOCK_BREAK_NOTIFY** control code allows the calling application to wait for completion of an opportunistic lock (oplock) break.

This operation is useful only for an oplock break that was already initiated when the caller's handle was opened. The handle must have been opened with FILE_COMPLETE_IF_OPLOCKED. This operation is meaningless if an oplock is currently held and the oplock break has not started.

To process this control code, a minifilter calls [**FltOplockFsctrl**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltoplockfsctrl) with the following parameters. A file system or legacy filter driver calls [**FsRtlOplockFsctrl**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-_fsrtl_advanced_fcb_header-fsrtloplockfsctrl).

For more information about opportunistic locking and about the **FSCTL_OPLOCK_BREAK_NOTIFY** control code, see the Microsoft Windows SDK documentation.

## Parameters

- **Oplock**: Opaque oplock object pointer for the file.

- **CallbackData**: [**FltOplockFsctrl**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltoplockfsctrl) only. Callback data ([**FLT_CALLBACK_DATA**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/ns-fltkernel-_flt_callback_data)) structure for an IRP_MJ_FILE_SYSTEM_CONTROL FSCTL request. The **FsControlCode** parameter for the operation must be FSCTL_OPLOCK_BREAK_NOTIFY.

- **Irp**: [**FsRtlOplockFsctrl**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-_fsrtl_advanced_fcb_header-fsrtloplockfsctrl) only. IRP for an IRP_MJ_FILE_SYSTEM_CONTROL FSCTL request. The **FsControlCode** parameter for the operation must be FSCTL_OPLOCK_BREAK_NOTIFY.

- **OpenCount**: Not used with this operation; set to zero.

## Status block

[**FltOplockFsctrl**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltoplockfsctrl) returns FLT_PREOP_PENDING if the oplock break is underway, and the IRP will be completed when the oplock break completes. (In this case, the IRP can eventually complete with either STATUS_SUCCESS or STATUS_CANCELLED.) Otherwise, **FltOplockFsctrl** returns FLT_PREOP_COMPLETE.

[**FsRtlOplockFsctrl**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-_fsrtl_advanced_fcb_header-fsrtloplockfsctrl) returns one of the following NTSTATUS values for this operation:

| Code | Meaning |
| ---- | ------- |
| STATUS_SUCCESS | No oplock was held by this handle, or an oplock is held and the oplock break has not started. |
| STATUS_INVALID_OPLOCK_PROTOCOL | The IRP was canceled before the FSCTL_OPLOCK_BREAK_NOTIFY operation was completed. |
| STATUS_PENDING | The oplock break is underway. The IRP will be completed when the oplock break completes. The IRP can eventually complete with either STATUS_SUCCESS or STATUS_CANCELLED. This is a success code. |

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

[**FSCTL_OPLOCK_BREAK_ACKNOWLEDGE**](https://learn.microsoft.com/windows-hardware/drivers/ifs/fsctl-oplock-break-acknowledge)

[**FSCTL_REQUEST_BATCH_OPLOCK**](https://learn.microsoft.com/windows-hardware/drivers/ifs/fsctl-request-batch-oplock)

[**FSCTL_REQUEST_FILTER_OPLOCK**](https://learn.microsoft.com/windows-hardware/drivers/ifs/fsctl-request-filter-oplock)

[**FSCTL_REQUEST_OPLOCK_LEVEL_1**](https://learn.microsoft.com/windows-hardware/drivers/ifs/fsctl-request-oplock-level-1)

[**FSCTL_REQUEST_OPLOCK_LEVEL_2**](https://learn.microsoft.com/windows-hardware/drivers/ifs/fsctl-request-oplock-level-2)

[**FsRtlOplockFsctrl**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-_fsrtl_advanced_fcb_header-fsrtloplockfsctrl)

[**IRP_MJ_FILE_SYSTEM_CONTROL**](https://learn.microsoft.com/windows-hardware/drivers/ifs/irp-mj-file-system-control)