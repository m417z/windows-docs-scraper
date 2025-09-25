# FltFsControlFile function

## Description

The **FltFsControlFile** routine sends a control code directly to a specified file system or file system filter driver, causing the corresponding driver to perform the specified action.

## Parameters

### `Instance` [in]

Opaque instance pointer for the caller. This parameter is required and cannot be **NULL**.

### `FileObject` [in]

File object pointer for the file or directory that is the target of this request. This parameter is required and cannot be **NULL**.

### `FsControlCode` [in]

FSCTL_*XXX* code that indicates which file system operation is to be carried out. The value of this parameter determines the formats and required lengths of the *InputBuffer* and *OutputBuffer*, and it determines which of the following parameter pairs (*InputBuffer* and *InputBufferLength*, *OutputBuffer* and *OutputBufferLength*) is required.

### `InputBuffer` [in, optional]

Pointer to a caller-allocated input buffer that contains device-specific information to be given to the target driver. If the *FsControlCode* parameter specifies an operation that does not require input data, this parameter is optional and can be **NULL**.

### `InputBufferLength` [in]

Size, in bytes, of the buffer at *InputBuffer*. This value is ignored if *InputBuffer* is **NULL**.

### `OutputBuffer` [out, optional]

Pointer to a caller-allocated output buffer in which information is returned from the target driver. If the *FsControlCode* parameter specifies an operation that does not require output data, this parameter is optional and can be **NULL**.

### `OutputBufferLength` [in]

Size, in bytes, of the buffer at *OutputBuffer*. This value is ignored if *OutputBuffer* is **NULL**.

### `LengthReturned` [out, optional]

Pointer to a caller-allocated variable that receives the size, in bytes, of the information returned in the buffer at *OutputBuffer*. This parameter is optional and can be **NULL**.

## Return value

**FltFsControlFile** returns STATUS_SUCCESS or an appropriate NTSTATUS value.

## Remarks

Minifilter drivers should call this routine instead of [ZwFsControlFile](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-zwfscontrolfile).

The following FSCTL codes are currently documented for kernel-mode drivers:

[FSCTL_DELETE_REPARSE_POINT](https://learn.microsoft.com/windows-hardware/drivers/ifs/fsctl-delete-reparse-point)

[FSCTL_GET_REPARSE_POINT](https://learn.microsoft.com/windows-hardware/drivers/ifs/fsctl-get-reparse-point)

[FSCTL_OPBATCH_ACK_CLOSE_PENDING](https://learn.microsoft.com/windows-hardware/drivers/ifs/fsctl-opbatch-ack-close-pending)

[FSCTL_OPLOCK_BREAK_ACK_NO_2](https://learn.microsoft.com/windows-hardware/drivers/ifs/fsctl-oplock-break-ack-no-2)

[FSCTL_OPLOCK_BREAK_ACKNOWLEDGE](https://learn.microsoft.com/windows-hardware/drivers/ifs/fsctl-oplock-break-acknowledge)

[FSCTL_OPLOCK_BREAK_NOTIFY](https://learn.microsoft.com/windows-hardware/drivers/ifs/fsctl-oplock-break-notify)

[FSCTL_REQUEST_BATCH_OPLOCK](https://learn.microsoft.com/windows-hardware/drivers/ifs/fsctl-request-batch-oplock)

[FSCTL_REQUEST_FILTER_OPLOCK](https://learn.microsoft.com/windows-hardware/drivers/ifs/fsctl-request-filter-oplock)

[FSCTL_REQUEST_OPLOCK_LEVEL_1](https://learn.microsoft.com/windows-hardware/drivers/ifs/fsctl-request-oplock-level-1)

[FSCTL_REQUEST_OPLOCK_LEVEL_2](https://learn.microsoft.com/windows-hardware/drivers/ifs/fsctl-request-oplock-level-2)

[FSCTL_SET_REPARSE_POINT](https://learn.microsoft.com/windows-hardware/drivers/ifs/fsctl-set-reparse-point)

For more information about the system-defined FSCTL_*XXX* codes, see the Remarks section of the reference entry for DeviceIoControl in the Microsoft Windows SDK documentation.

## See also

[FltDeviceIoControlFile](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltdeviceiocontrolfile)

[ZwFsControlFile](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-zwfscontrolfile)