# FsRtlIssueDeviceIoControl function

## Description

The **FsRtlIssueDeviceIoControl** routine sends a synchronous device I/O control request to a target device object.

## Parameters

### `DeviceObject` [in]

The target device object.

### `IoCtl` [in]

The IOCTL control code to issue.

### `Flags`

The desired IRP flags to set for IOCTL request.

### `InputBuffer` [in, optional]

An optional buffer containing the input data for the request.

### `InputBufferLength` [in]

The length, in bytes, of the input data in **InputBuffer**.

### `OutputBuffer` [out, optional]

An optional caller-supplied output buffer for returned data.

### `OutputBufferLength` [in]

The length, in bytes, of the output data buffer at **OutputBuffer**.

### `IosbInformation` [in]

A pointer to a ULONG status value to receive the information field value set in the I/O status block at completion of the request.

## Return value

**FsRtlIssueDeviceIoControl** returns STATUS_SUCCESS or another NTSTATUS value returned in the status block from the I/O operation.

## See also

[**FltDeviceIoControlFile**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltdeviceiocontrolfile)