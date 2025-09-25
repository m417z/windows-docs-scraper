# IOCTL_HID_ENABLE_WAKE_ON_SX IOCTL

## Description

The **IOCTL_HID_ENABLE_WAKE_ON_SX**
request is used to indicate the requirement for a device to be able to wake from system sleep.

User mode clients, including user mode driver framework (UMDF) drivers, use this IOCTL to let a device know about the "*wake from sleep*" requirement. The user mode clients use this IOCTL because they are not able to send an I/O request packet (IRP) to a device.

## Parameters

### Major code

### Input buffer

The **Parameters.DeviceIoControl.OutputBufferLength** member specifies the size, in bytes, of a requester-allocated output buffer.

### Input buffer length

This is a buffer of size Boolean.

### Output buffer

The **Irp->AssociatedIrp.SystemBuffer** member is a pointer to the requestor-allocated buffer that the HID class driver uses to return the Boolean value. This Boolean value indicates whether or not the device is configured and ready to wake from system sleep. The pointer is cast as a pointer to Boolean: (PBOOLEAN)(Irp->AssociatedIrp.SystemBuffer).

### Output buffer length

This is a buffer of size Boolean.

### Input/output buffer

### Input/output buffer length

### Status block

**Irp->IoStatus.Status** is set to STATUS_SUCCESS if the request is successful. Otherwise, Status to the appropriate error condition as a [NTSTATUS](https://learn.microsoft.com/windows-hardware/drivers/kernel/using-ntstatus-values) code.