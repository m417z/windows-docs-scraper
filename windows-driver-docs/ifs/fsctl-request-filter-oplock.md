# FSCTL_REQUEST_FILTER_OPLOCK control code

The **FSCTL_REQUEST_FILTER_OPLOCK** control code requests a filter opportunistic lock (oplock) on a file.

To process this control code, a minifilter calls [**FltOplockFsctrl**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltoplockfsctrl) with the following parameters. A file system or legacy filter driver calls [**FsRtlOplockFsctrl**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-_fsrtl_advanced_fcb_header-fsrtloplockfsctrl).

For more information about opportunistic locking and about the **FSCTL_REQUEST_FILTER_OPLOCK** control code, see the Microsoft Windows SDK documentation.

## Parameters

- **Oplock**: Opaque oplock object pointer for the file.

- **CallbackData**: [**FltOplockFsctrl**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltoplockfsctrl) only. Callback data ([**FLT_CALLBACK_DATA**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/ns-fltkernel-_flt_callback_data)) structure for an IRP_MJ_FILE_SYSTEM_CONTROL FSCTL request. The *FsControlCode* parameter for the operation must be FSCTL_REQUEST_FILTER_OPLOCK.

- **Irp**: [**FsRtlOplockFsctrl**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-_fsrtl_advanced_fcb_header-fsrtloplockfsctrl) only. IRP for an IRP_MJ_FILE_SYSTEM_CONTROL FSCTL request. The *FsControlCode* parameter for the operation must be FSCTL_REQUEST_FILTER_OPLOCK.

- **OpenCount**: Number of user handles for the file.

## Status block

[**FltOplockFsctrl**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltoplockfsctrl) returns FLT_PREOP_PENDING for this operation if the oplock was granted. Otherwise, it returns FLT_PREOP_COMPLETE.

[**FsRtlOplockFsctrl**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-_fsrtl_advanced_fcb_header-fsrtloplockfsctrl) returns one of the following NTSTATUS values for this operation:

| Code | Meaning |
| ---- | ------- |
| STATUS_PENDING | The oplock was granted. This is a success code. |
| STATUS_CANCELLED | The IRP was canceled before the FSCTL_REQUEST_BATCH_OPLOCK operation was completed. This is an error code. |
| STATUS_OPLOCK_NOT_GRANTED | The oplock could not be granted. This is an error code. |

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

[**FSCTL_OPLOCK_BREAK_NOTIFY**](https://learn.microsoft.com/windows-hardware/drivers/ifs/fsctl-oplock-break-notify)

[**FSCTL_REQUEST_BATCH_OPLOCK**](https://learn.microsoft.com/windows-hardware/drivers/ifs/fsctl-request-batch-oplock)

[**FSCTL_REQUEST_OPLOCK_LEVEL_1**](https://learn.microsoft.com/windows-hardware/drivers/ifs/fsctl-request-oplock-level-1)

[**FSCTL_REQUEST_OPLOCK_LEVEL_2**](https://learn.microsoft.com/windows-hardware/drivers/ifs/fsctl-request-oplock-level-2)

[**FsRtlOplockFsctrl**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-_fsrtl_advanced_fcb_header-fsrtloplockfsctrl)

[**IRP_MJ_FILE_SYSTEM_CONTROL**](https://learn.microsoft.com/windows-hardware/drivers/ifs/irp-mj-file-system-control)