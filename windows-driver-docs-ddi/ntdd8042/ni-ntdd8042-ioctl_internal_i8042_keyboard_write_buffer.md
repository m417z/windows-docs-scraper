# IOCTL_INTERNAL_I8042_KEYBOARD_WRITE_BUFFER IOCTL

## Description

The IOCTL_INTERNAL_I8042_KEYBOARD_WRITE_BUFFER request writes data to the i8042 port controller to control operation of a keyboard device. A filter driver can use this request to control the operation of a keyboard.

I8042prt synchronizes write buffer requests and other keyboard requests that write to the i8042 port controller, including [IOCTL_KEYBOARD_SET_INDICATORS](https://learn.microsoft.com/windows/win32/api/ntddkbd/ni-ntddkbd-ioctl_keyboard_set_indicators) and [IOCTL_KEYBOARD_SET_TYPEMATIC](https://learn.microsoft.com/windows/win32/api/ntddkbd/ni-ntddkbd-ioctl_keyboard_set_typematic). I8042prt synchronizes the actual write of data with the keyboard ISR.

## Parameters

### Major code

[IRP_MJ_INTERNAL_DEVICE_CONTROL](https://learn.microsoft.com/windows-hardware/drivers/kernel/irp-mj-internal-device-control)

### Input buffer

**Parameters.DeviceIoControl.Type3InputBuffer** points to a client-allocated buffer which inputs the data to write to an i8042 port controller.

### Input buffer length

**Parameters.DeviceIoControl.InputBufferLength** is set to the number of bytes in the input buffer, which must be greater than one.

### Output buffer

None

### Output buffer length

None

### Input/output buffer

### Input/output buffer length

### Status block

The **Status** member is set to one of the following values:

**STATUS_DEVICE_NOT_READY**

The keyboard interrupt is not initialized.

**STATUS_INVALID_PARAMETER**

The input parameters are not valid.

**STATUS_IO_TIMEOUT**

The request timed out.

**STATUS_SUCCESS**

The request completed successfully.

## See also

[IOCTL_KEYBOARD_SET_INDICATORS](https://learn.microsoft.com/windows/win32/api/ntddkbd/ni-ntddkbd-ioctl_keyboard_set_indicators)

[IOCTL_KEYBOARD_SET_TYPEMATIC](https://learn.microsoft.com/windows/win32/api/ntddkbd/ni-ntddkbd-ioctl_keyboard_set_typematic)