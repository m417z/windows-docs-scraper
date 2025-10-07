# FSCTL_OPBATCH_ACK_CLOSE_PENDING control code

The **FSCTL_OPBATCH_ACK_CLOSE_PENDING** control code responds to notification that an exclusive (level 1, batch, or filter) opportunistic lock (oplock) on a file has been broken. A client application sends this control code to indicate that it acknowledges the oplock break and it is about to close the file handle.

For a batch or filter oplock break, the caller must close its file handle after sending this control code. Otherwise, the system will block waiting for the file handle to be closed.

This control code is not intended to be used with level 1 oplocks. Nevertheless, for a level 1 oplock break, the system treats this control code as a complete acknowledgment of the break, and the caller is not required to close the file handle.

This control code is rarely used. When a client application is notified of an oplock break for a file, and it closes its handle for the file, the system treats the file handle close as a complete acknowledgment of the oplock break. Thus it is never necessary to send this control code.

To process this control code, a minifilter calls [**FltOplockFsctrl**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltoplockfsctrl) with the following parameters. A file system or legacy filter driver calls [**FsRtlOplockFsctrl**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-_fsrtl_advanced_fcb_header-fsrtloplockfsctrl).

For more information about opportunistic locking and about the FSCTL_OPBATCH_ACK_CLOSE_PENDING control code, see the Microsoft Windows SDK documentation.

## Parameters

- **Oplock**: Opaque oplock object pointer for the file.

- **CallbackData**: [**FltOplockFsctrl**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltoplockfsctrl) only. Callback data ([**FLT_CALLBACK_DATA**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/ns-fltkernel-_flt_callback_data)) structure for an IRP_MJ_FILE_SYSTEM_CONTROL FSCTL request. The **FsControlCode** parameter for the operation must be FSCTL_OPBATCH_ACK_CLOSE_PENDING.

- **Irp**: [**FsRtlOplockFsctrl**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-_fsrtl_advanced_fcb_header-fsrtloplockfsctrl) only. IRP for an IRP_MJ_FILE_SYSTEM_CONTROL FSCTL request. The **FsControlCode** parameter for the operation must be FSCTL_OPBATCH_ACK_CLOSE_PENDING.

- **OpenCount**: Not used with this operation; set to zero.

## Status block

[**FltOplockFsctrl**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltoplockfsctrl) always returns FLT_PREOP_COMPLETE for this operation.

[**FsRtlOplockFsctrl**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-_fsrtl_advanced_fcb_header-fsrtloplockfsctrl) returns one of the following NTSTATUS values for this operation:

| Code | Meaning |
| ---- | ------- |
| STATUS_SUCCESS | The oplock held by this handle was in the process of being broken. |
| STATUS_INVALID_OPLOCK_PROTOCOL | No oplock was held by this handle, or the oplock break is not currently in progress. This is an error code. |

## Requirements

| Requirement type | Requirement |
| ---------------- | ----------- |
| Header | *Ntifs.h* (include *Ntifs.h* or *Fltkernel.h*) |

## See also

[**FLT_CALLBACK_DATA**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/ns-fltkernel-_flt_callback_data)

[**FLT_PARAMETERS for IRP_MJ_FILE_SYSTEM_CONTROL**](https://learn.microsoft.com/windows-hardware/drivers/ifs/flt-parameters-for-irp-mj-file-system-control)

[**FltOplockFsctrl**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltoplockfsctrl)

[**FSCTL_OPLOCK_BREAK_ACK_NO_2**](https://learn.microsoft.com/windows-hardware/drivers/ifs/fsctl-oplock-break-ack-no-2)

[**FSCTL_OPLOCK_BREAK_ACKNOWLEDGE**](https://learn.microsoft.com/windows-hardware/drivers/ifs/fsctl-oplock-break-acknowledge)

[**FSCTL_OPLOCK_BREAK_NOTIFY**](https://learn.microsoft.com/windows-hardware/drivers/ifs/fsctl-oplock-break-notify)

[**FSCTL_REQUEST_BATCH_OPLOCK**](https://learn.microsoft.com/windows-hardware/drivers/ifs/fsctl-request-batch-oplock)

[**FSCTL_REQUEST_FILTER_OPLOCK**](https://learn.microsoft.com/windows-hardware/drivers/ifs/fsctl-request-filter-oplock)

[**FSCTL_REQUEST_OPLOCK_LEVEL_1**](https://learn.microsoft.com/windows-hardware/drivers/ifs/fsctl-request-oplock-level-1)

[**FSCTL_REQUEST_OPLOCK_LEVEL_2**](https://learn.microsoft.com/windows-hardware/drivers/ifs/fsctl-request-oplock-level-2)

[**FsRtlOplockFsctrl**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-_fsrtl_advanced_fcb_header-fsrtloplockfsctrl)

[**IRP_MJ_FILE_SYSTEM_CONTROL**](https://learn.microsoft.com/windows-hardware/drivers/ifs/irp-mj-file-system-control)