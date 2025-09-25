# IOCTL_INTERNAL_KEYBOARD_CONNECT IOCTL

## Description

The IOCTL_INTERNAL_KEYBOARD_CONNECT request connects the Kbdclass service to the keyboard device. Kbdclass sends this request down the keyboard device stack before it opens the keyboard device.

After Kbfiltr received the keyboard connect request, Kbfiltr filters the connect request in the following way:

* Saves a copy of Kbdclass's [CONNECT_DATA (Kbdclass)](https://learn.microsoft.com/windows-hardware/drivers/ddi/kbdmou/ns-kbdmou-_connect_data) structure that is passed to the filter driver by Kbdclass
* Substitutes its own connect information for the class driver connect information
* Sends the IOCTL_INTERNAL_KEYBOARD_CONNECT request down the device stack

If the request is not successful, Kbfiltr completes the request with an appropriate error status.

Kbfiltr provides a template for a filter service callback routine that can supplement the operation of [KeyboardClassServiceCallback](https://learn.microsoft.com/previous-versions/ff542324(v=vs.85)), the Kbdclass class service callback routine. The filter service callback can filter the input data that is transferred from the device input buffer to the class data queue.

For more information about the connection of the Kbdclass service, see the following topics:

[Kbdclass Class Service Callback Routine](https://learn.microsoft.com/windows-hardware/drivers/ddi/kbdmou/nc-kbdmou-pservice_callback_routine)

[Kbfiltr Callback Routines](https://learn.microsoft.com/previous-versions/ff542302(v=vs.85))

## Parameters

### Major code

[IRP_MJ_INTERNAL_DEVICE_CONTROL](https://learn.microsoft.com/windows-hardware/drivers/kernel/irp-mj-internal-device-control)

### Input buffer

The **Parameters.DeviceIoControl.Type3InputBuffer** member points to a **CONNECT_DATA** structure that is allocated and set by Kbdclass.

### Input buffer length

The **Parameters.DeviceIoControl.InputBufferLength** member is set to a value greater than or equal to the size, in bytes, of a CONNECT_DATA structure.

### Output buffer

The **Parameters.DeviceIoControl.Type3InputBuffer** member points to a **CONNECT_DATA** structure that is set by Kbfiltr.

### Output buffer length

The size of a **CONNECT_DATA** structure.

### Input/output buffer

### Input/output buffer length

### Status block

The **Information** member is set to zero.

The **Status** member is set to one of the following values:

**STATUS_INVALID_PARAMETER**

**Parameters.DeviceIoControl.InputBufferLength** is less than the size, in bytes, of a CONNECT_DATA structure.

**STATUS_SHARING_VIOLATION**

Kbfiltr is already connected (the filter driver supports only one connect request).

**STATUS_SUCCESS**

The request completed successfully.

## See also

[CONNECT_DATA (Kbdclass)](https://learn.microsoft.com/windows-hardware/drivers/ddi/kbdmou/ns-kbdmou-_connect_data)

[IOCTL_INTERNAL_I8042_HOOK_KEYBOARD](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntdd8042/ni-ntdd8042-ioctl_internal_i8042_hook_keyboard)

[KeyboardClassServiceCallback](https://learn.microsoft.com/previous-versions/ff542324(v=vs.85))