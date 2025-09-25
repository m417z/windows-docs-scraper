# IOCTL_HID_GET_MS_GENRE_DESCRIPTOR IOCTL

## Description

The **IOCTL_HID_GET_MS_GENRE_DESCRIPTOR** request is used for retrieving the _Genre_ [Microsoft OS 1.0 feature descriptor](https://learn.microsoft.com/windows-hardware/drivers/usbcon/microsoft-defined-usb-descriptors) for the device. This descriptor is being considered for future versions of Windows, and no specification is currently available.

## Parameters

### Major code

### Input buffer

The **Parameters.DeviceIoControl.OutputBufferLength** member specifies the size, in bytes, of a requester-allocated output buffer.

### Input buffer length

### Output buffer

**Irp->IoStatus.Status** is set to STATUS_SUCCESS if the request is successful. Otherwise, Status to the appropriate error condition as a [NTSTATUS](https://learn.microsoft.com/windows-hardware/drivers/kernel/using-ntstatus-values) code.

### Output buffer length

The size of a status code.

### Input/output buffer

### Input/output buffer length

### Status block

**Irp->IoStatus.Status** is set to STATUS_SUCCESS if the request is successful. Otherwise, Status to the appropriate error condition as a [NTSTATUS](https://learn.microsoft.com/windows-hardware/drivers/kernel/using-ntstatus-values) code.