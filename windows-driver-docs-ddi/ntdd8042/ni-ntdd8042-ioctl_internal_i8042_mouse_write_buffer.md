# IOCTL_INTERNAL_I8042_MOUSE_WRITE_BUFFER IOCTL

## Description

The IOCTL_INTERNAL_I8042_MOUSE_WRITE_BUFFER request writes data to the i8042 port controller to control operation of a mouse device. An upper-level filter driver can use this request to control the operation of a mouse.

I8042prt synchronizes write buffer requests with one another. I8042prt synchronizes the actual write of data with the mouse ISR.

## Parameters

### Major code

[IRP_MJ_INTERNAL_DEVICE_CONTROL](https://learn.microsoft.com/windows-hardware/drivers/kernel/irp-mj-internal-device-control)

### Input buffer

**Parameters.DeviceIoControl.Type3InputBuffer** points to a client-allocated buffer that supplies the data to write to an i8042 port controller.

### Input buffer length

**Parameters.DeviceIoControl.InputBufferLength** is set to the number of bytes in the input buffer, which must be greater than 1.

### Output buffer

None

### Output buffer length

None

### Input/output buffer

### Input/output buffer length

### Status block

The **Status** member is set to one of the following values:

**STATUS_DEVICE_NOT_READY**

The mouse interrupt is not initialized.

**STATUS_INVALID_PARAMETER**

The input parameters are not valid.

**STATUS_IO_TIMEOUT**

The request timed out.

**STATUS_SUCCESS**

The request completed successfully.