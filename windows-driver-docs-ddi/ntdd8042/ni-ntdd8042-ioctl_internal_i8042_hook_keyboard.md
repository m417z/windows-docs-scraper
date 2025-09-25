# IOCTL_INTERNAL_I8042_HOOK_KEYBOARD IOCTL

## Description

The IOCTL_INTERNAL_I8042_HOOK_KEYBOARD request does the following:

* Adds an initialization callback routine to the I8042prt keyboard initialization routine
* Adds an ISR callback routine to the I8042prt keyboard ISR

The initialization and ISR callbacks are optional and are provided by an upper-level filter driver for a PS/2-style keyboard device.

After I8042prt receives an [IOCTL_INTERNAL_KEYBOARD_CONNECT](https://learn.microsoft.com/windows-hardware/drivers/ddi/kbdmou/ni-kbdmou-ioctl_internal_keyboard_connect) request, it sends a synchronous IOCTL_INTERNAL_I8042_HOOK_KEYBOARD request to the top of the keyboard device stack.

After Kbfiltr receives the hook keyboard request, Kbfiltr filters the request in the following way:

* Saves the upper-level information passed to Kbfiltr, which includes the context of an upper-level device object, a pointer to an initialization callback, and a pointer to an ISR callback
* Replaces the upper-level information with its own
* Saves the context of I8042prt and pointers to callbacks that the Kbfiltr ISR callback can use

For more information about this request and the callbacks, see the following topics:

[I8042prt Callback Routines](https://learn.microsoft.com/windows-hardware/drivers/ddi/)

[Kbfiltr Callback Routines](https://learn.microsoft.com/previous-versions/ff542302(v=vs.85))

## Parameters

### Major code

[IRP_MJ_INTERNAL_DEVICE_CONTROL](https://learn.microsoft.com/windows-hardware/drivers/kernel/irp-mj-internal-device-control)

### Input buffer

The **Parameters.DeviceIoControl.Type3InputBuffer** points to an INTERNAL_I8042_HOOK_KEYBOARD structure. This structure includes the following members:

### Input buffer length

The **Parameters.DeviceIoControl.InputBufferLength** member is set to a value that is greater than or equal to the size, in bytes, of an [INTERNAL_I8042_HOOK_KEYBOARD](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntdd8042/ns-ntdd8042-_internal_i8042_hook_keyboard) structure.

### Output buffer

None

### Output buffer length

None

### Input/output buffer

### Input/output buffer length

### Status block

The **Status** member is set to one of the following values:

**STATUS_INVALID_PARAMETER**

**Parameters.DeviceIoControl.InputBufferLength** is less than the size, in bytes, of an INTERNAL_I8042_HOOK_KEYBOARD structure.

**STATUS_SUCCESS**

The request completed successfully.

## -InitializationRoutine

Pointer to an optional callback that the I8042prt keyboard initialization routine calls when it initializes a keyboard device.

## -IsrRoutine

Pointer to an optional callback that is called by the I8042prt keyboard ISR.

## See also

[INTERNAL_I8042_HOOK_KEYBOARD](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntdd8042/ns-ntdd8042-_internal_i8042_hook_keyboard)

[IOCTL_INTERNAL_KEYBOARD_CONNECT](https://learn.microsoft.com/windows-hardware/drivers/ddi/kbdmou/ni-kbdmou-ioctl_internal_keyboard_connect)