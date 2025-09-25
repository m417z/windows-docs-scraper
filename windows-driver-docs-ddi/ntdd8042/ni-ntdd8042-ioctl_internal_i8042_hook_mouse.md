# IOCTL_INTERNAL_I8042_HOOK_MOUSE IOCTL

## Description

The IOCTL_INTERNAL_I8042_HOOK_MOUSE request adds an ISR callback routine to the I8042prt mouse ISR. The ISR callback is optional and is provided by an upper-level mouse filter driver.

I8042prt sends this request after it receives an [IOCTL_INTERNAL_MOUSE_CONNECT](https://learn.microsoft.com/windows-hardware/drivers/ddi/kbdmou/ni-kbdmou-ioctl_internal_mouse_connect) request. I8042prt sends a synchronous IOCTL_INTERNAL_I8042_HOOK_MOUSE request to the top of the mouse device stack.

After Moufiltr receives the hook mouse request, it filters the request in the following way:

* Saves the upper-level information passed to Moufiltr, which includes the context of an upper-level device object and a pointer to an ISR callback
* Replaces the upper-level information with its own
* Saves the context of I8042prt and pointers to callbacks that the Moufiltr ISR callbacks can use

For more information about this request and the callbacks, see the following topics:

[I8042prt Callback Routines](https://learn.microsoft.com/windows-hardware/drivers/ddi/)

[Moufiltr Callback Routines](https://learn.microsoft.com/previous-versions/ff542384(v=vs.85))

## Parameters

### Major code

[IRP_MJ_INTERNAL_DEVICE_CONTROL](https://learn.microsoft.com/windows-hardware/drivers/kernel/irp-mj-internal-device-control)

### Input buffer

The **Parameters.DeviceIoControl.InputBufferLength** member is set to a value greater than or equal to the size, in bytes, of an [INTERNAL_I8042_HOOK_MOUSE](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntdd8042/ns-ntdd8042-_internal_i8042_hook_mouse) structure.

The **Parameters.DeviceIoControl.Type3InputBuffer** points to an INTERNAL_I8042_HOOK_MOUSE structure that is allocated and set initially by I8042prt.

### Input buffer length

The **Parameters.DeviceIoControl.Type3InputBuffer** points to an INTERNAL_I8042_HOOK_MOUSE structure that is allocated and set initially by I8042prt.

### Output buffer

None

### Output buffer length

None

### Input/output buffer

### Input/output buffer length

### Status block

The **Status** member is set to one of the following values:

**STATUS_INVALID_PARAMETER**

**Parameters.DeviceIoControl.InputBufferLength** is less than the size, in bytes, of an INTERNAL_I8042_HOOK_MOUSE structure.

**STATUS_SUCCESS**

The request completed successfully.

## See also

[INTERNAL_I8042_HOOK_MOUSE](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntdd8042/ns-ntdd8042-_internal_i8042_hook_mouse)

[IOCTL_INTERNAL_MOUSE_CONNECT](https://learn.microsoft.com/windows-hardware/drivers/ddi/kbdmou/ni-kbdmou-ioctl_internal_mouse_connect)