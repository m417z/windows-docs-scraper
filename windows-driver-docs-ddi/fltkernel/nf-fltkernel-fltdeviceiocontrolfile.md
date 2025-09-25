# FltDeviceIoControlFile function

## Description

**FltDeviceIoControlFile** sends a control code directly to a specified device driver, causing the corresponding driver to perform the specified action.

## Parameters

### `Instance` [in]

Opaque instance pointer for the caller. This parameter is required and cannot be **NULL**.

### `FileObject` [in]

File object pointer for the file or device that is the target of this request. This parameter is required and cannot be **NULL**.

### `IoControlCode` [in]

IOCTL_*XXX* code that indicates which device I/O operation is to be carried out. The value of this parameter determines the formats and required lengths of the *InputBuffer* and *OutputBuffer*, and it determines which of the following parameter pairs (*InputBuffer* and *InputBufferLength*, or *OutputBuffer* and *OutputBufferLength*) is required.

### `InputBuffer` [in, optional]

Pointer to a caller-allocated input buffer that contains device-specific information to be given to the target driver. If the *IoControlCode* parameter specifies an operation that does not require input data, this parameter is optional and can be **NULL**.

### `InputBufferLength` [in]

Size, in bytes, of the buffer at *InputBuffer*. This value is ignored if *InputBuffer* is **NULL**.

### `OutputBuffer` [out]

Pointer to a caller-allocated output buffer in which information is returned from the target driver. If the *IoControlCode* parameter specifies an operation that does not require output data, this parameter is optional and can be **NULL**.

### `OutputBufferLength` [in]

Size, in bytes, of the buffer at *OutputBuffer*. This value is ignored if *OutputBuffer* is **NULL**.

### `LengthReturned` [out, optional]

Pointer to a caller-allocated variable that receives the size, in bytes, of the information returned in the buffer at *OutputBuffer*. This parameter is optional and can be **NULL**.

## Return value

**FltDeviceIoControlFile** returns STATUS_SUCCESS or an appropriate NTSTATUS value.

## Remarks

For more information about the system-defined IOCTL_*XXX* codes, see the Remarks section of the reference entry for **DeviceIoControl** in the Microsoft Windows SDK documentation.

## See also

[FltFsControlFile](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltfscontrolfile)