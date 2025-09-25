# IOCTL_HID_SET_S0_IDLE_TIMEOUT IOCTL

## Description

The **IOCTL_HID_SET_S0_IDLE_TIMEOUT**
request is used by a client to inform the HID class driver about the client's preferred idle timeout value.

When the client sets this value to zero (0), it informs the HID class driver that the preferred idle timeout value is no longer valid. In this case, the HID class driver will start to use the default idle timeout value.

## Parameters

### Major code

### Input buffer

 The **Parameters.DeviceIoControl.OutputBufferLength** member specifies the size, in bytes, of a requester-allocated output buffer.

### Input buffer length

This is a buffer of size ULONG.

### Output buffer

The **Irp->AssociatedIrp.SystemBuffer** member is a pointer to the requestor-allocated buffer that the client uses to return the idle timeout value.

### Output buffer length

### Input/output buffer

### Input/output buffer length

### Status block

**Irp->IoStatus.Status** is set to STATUS_SUCCESS if the request is successful. Otherwise, Status to the appropriate error condition as a [NTSTATUS](https://learn.microsoft.com/windows-hardware/drivers/kernel/using-ntstatus-values) code.