# IOCTL_INTERNAL_USBFN_BUS_EVENT_NOTIFICATION IOCTL

## Description

The USB class driver sends this request to prepare for notifications received from the USB function class extension (UFX) in response to an event on the bus, such as a change in the port type
or a receipt of a non-standard setup packet.

## Parameters

### Major code

[IRP_MJ_INTERNAL_DEVICE_CONTROL](https://learn.microsoft.com/windows-hardware/drivers/kernel/irp-mj-internal-device-control)

### Input buffer

NULL.

### Input buffer length

None.

### Output buffer

A pointer to a caller-allocated [USBFN_NOTIFICATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/usbfnbase/ns-usbfnbase-_usbfn_notification)
structure that UFX populates with the type of bus event and data associated with that event.

### Output buffer length

The size of a [USBFN_NOTIFICATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/usbfnbase/ns-usbfnbase-_usbfn_notification)
structure.

### Input/output buffer

### Input/output buffer length

### Status block

If the request is successful, the USB function class extension (UFX) returns STATUS_SUCCESS, or another status value for which NT_SUCCESS(status) equals TRUE. Otherwise it returns a status value for which NT_SUCCESS(status) equals FALSE.

## Remarks

UFX completes this request in response to an event on the bus. It is recommended that class drivers send multiple requests at a time to make sure that critical notifications are not missed.

## See also

[USBFN_EVENT](https://learn.microsoft.com/windows-hardware/drivers/ddi/usbfnbase/ne-usbfnbase-_usbfn_event)

[USBFN_NOTIFICATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/usbfnbase/ns-usbfnbase-_usbfn_notification)