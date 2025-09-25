# IOCTL_INTERNAL_MOUSE_CONNECT IOCTL

## Description

The IOCTL_INTERNAL_MOUSE_CONNECT request connects Mouclass service to a mouse device. Mouclass sends this request down the device stack before it opens a mouse device.

After Moufiltr receives the mouse connect request, it filters the request in the following way:

1. Saves a copy of the [CONNECT_DATA (Mouclass)](https://learn.microsoft.com/previous-versions/ff538375(v=vs.85)) structure that was passed to Moufiltr
2. Substitutes its own connect information for the class driver connect information
3. Sends the IOCTL_INTERNAL_MOUSE_CONNECT request down the device stack

If the request is not successful, Moufiltr completes the request with an appropriate error status.

Moufiltr provides a template for a filter service callback routine that can supplement the operation of [MouseClassServiceCallback](https://learn.microsoft.com/previous-versions/ff542394(v=vs.85)), the Mouclass service callback routine. The filter service callback can filter the input data that is transferred from the device input buffer to the class driver data queue.

For more information about the connection of the Mouclass service, see the following topics:

[I8042prt Callback Routines](https://learn.microsoft.com/windows-hardware/drivers/ddi/)

[Moufiltr Callback Routines](https://learn.microsoft.com/previous-versions/ff542384(v=vs.85))

## Parameters

### Major code

[IRP_MJ_INTERNAL_DEVICE_CONTROL](https://learn.microsoft.com/windows-hardware/drivers/kernel/irp-mj-internal-device-control)

### Input buffer

The **Parameters.DeviceIoControl.Type3InputBuffer** member points to a CONNECT_DATA structure that is allocated and set by Mouclass.

### Input buffer length

The **Parameters.DeviceIoControl.InputBufferLength** member is set to a value greater than or equal to the size, in bytes, of a CONNECT_DATA structure.

### Output buffer

The **Parameters.DeviceIoControl.Type3InputBuffer** member points to a CONNECT_DATA structure that is set by Moufiltr.

### Output buffer length

The size of a CONNECT_DATA structure.

### Input/output buffer

### Input/output buffer length

### Status block

The **Information** member is set to zero.

The **Status** member is set to one of the following values:

**STATUS_INVALID_PARAMETER**

**Parameters.DeviceIoControl.InputBufferLength** is less than the size, in bytes, of a CONNECT_DATA structure.

**STATUS_SHARING_VIOLATION**

Moufiltr is already connected (a filter driver supports only one connect request).

## See also

[CONNECT_DATA (Mouclass)](https://learn.microsoft.com/previous-versions/ff538375(v=vs.85))

[MouseClassServiceCallback](https://learn.microsoft.com/previous-versions/ff542394(v=vs.85))