# IOCTL_MOUSE_QUERY_ATTRIBUTES IOCTL

## Description

The IOCTL_MOUSE_QUERY_ATTRIBUTES request returns information about the mouse attributes.

Mouclass copies the current stack location, sets the **MajorFunction** member of the new stack location to [IRP_MJ_INTERNAL_DEVICE_CONTROL](https://learn.microsoft.com/windows-hardware/drivers/kernel/irp-mj-internal-device-control), and sends this request down the device stack.

For more information about this request, see [I8042prt Mouse Internal Device Control Requests](https://learn.microsoft.com/windows-hardware/drivers/ddi/content/).

## Parameters

### Input buffer

The **Parameters.DeviceIoControl.InputBufferLength** member is set to zero or a value greater than or equal to the size, in bytes, of a [MOUSE_UNIT_ID_PARAMETER](https://learn.microsoft.com/windows/desktop/api/ntddmou/ns-ntddmou-mouse_unit_id_parameter). A value of zero specifies a default unit ID of zero.

The **AssociatedIrp.SystemBuffer**  member points to a client-allocated buffer that is used to input and output information. On input, **AssociatedIrp.SystemBuffer** points to a MOUSE_UNIT_ID_PARAMETER structure. The client sets the **UnitId** member of the input structure.

The **Parameters.DeviceIoControl.OutputBufferLength** member specifies the size, in bytes, of an output buffer, which must be greater than or equal to the size in bytes of a [MOUSE_ATTRIBUTES](https://learn.microsoft.com/windows/desktop/api/ntddmou/ns-ntddmou-mouse_attributes) structure.

### Input buffer length

The size of a [MOUSE_UNIT_ID_PARAMETER](https://learn.microsoft.com/windows/desktop/api/ntddmou/ns-ntddmou-mouse_unit_id_parameter) structure.

### Output buffer

**AssociatedIrp.SystemBuffer** points to the client-allocated buffer that the lower-level drivers use to output a [MOUSE_ATTRIBUTES](https://learn.microsoft.com/windows/desktop/api/ntddmou/ns-ntddmou-mouse_attributes) structure.

### Output buffer length

The size of a [MOUSE_ATTRIBUTES](https://learn.microsoft.com/windows/desktop/api/ntddmou/ns-ntddmou-mouse_attributes) structure.

### Input/output buffer

### Input/output buffer length

### Status block

The **Information** member is set to the number of bytes of attribute data that are returned if the request is successful.

The **Status** member is set to one of the following values:

## -STATUS_BUFFER_TOO_SMALL

The **Parameters.DeviceIoControl.InputBufferLength**  value is greater than zero but less than the size, in bytes, of a MOUSE_UNIT_ID_PARAMETER structure.

## -STATUS_INVALID_PARAMETER

The **UnitId**  value is invalid.

## -STATUS_NOT_SUPPORTED

The target device is associated with a subordinate class device.

## -STATUS_SUCCESS

The request completed successfully.

## See also

[MOUSE_ATTRIBUTES](https://learn.microsoft.com/windows/desktop/api/ntddmou/ns-ntddmou-mouse_attributes)

[MOUSE_UNIT_ID_PARAMETER](https://learn.microsoft.com/windows/desktop/api/ntddmou/ns-ntddmou-mouse_unit_id_parameter)