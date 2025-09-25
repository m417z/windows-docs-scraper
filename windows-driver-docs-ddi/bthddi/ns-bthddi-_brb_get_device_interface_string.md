# _BRB_GET_DEVICE_INTERFACE_STRING structure

## Description

The _BRB_GET_DEVICE_INTERFACE_STRING structure describes the device interface string for the current
device object.

## Members

### `Hdr`

A
[BRB_HEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/bthddi/ns-bthddi-_brb_header) structure that contains information
about the current BRB.

### `DeviceInterfaceString`

A pointer to the buffer to contain the device interface string.

### `DeviceInterfaceStringCbLength`

On input, this member specifies the length, in bytes, of the device interface string. On output,
this member specifies the number of bytes required for the string if the
[BRB_GET_DEVICE_INTERFACE_STRING](https://learn.microsoft.com/windows-hardware/drivers/ddi/bthddi/ns-bthddi-_brb_get_device_interface_string) BRB fails and returns STATUS_MORE_ENTRIES because of insufficient
buffer length. If the BRB call succeeds, this member contains the number of bytes copied.

## Remarks

To get the device interface string for the current device object, profile drivers should
[build and send](https://learn.microsoft.com/previous-versions/ff536657(v=vs.85)) a
[BRB_GET_DEVICE_INTERFACE_STRING](https://learn.microsoft.com/windows-hardware/drivers/ddi/bthddi/ns-bthddi-_brb_get_device_interface_string) request.

The Bluetooth driver stack performs an
[IoRegisterDeviceInterface](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-ioregisterdeviceinterface) call on
each device object it creates. The BRB returns the device interface string returned by that call. This
can be useful for registering for events.

If the buffer pointed to by the
**DeviceInterfaceString** member is not large enough to hold the string, the call fails and the
**DeviceInterfaceStringCbLength** member contains the required buffer length.

## See also

[BRB_GET_DEVICE_INTERFACE_STRING](https://learn.microsoft.com/windows-hardware/drivers/ddi/bthddi/ns-bthddi-_brb_get_device_interface_string)

[BRB_HEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/bthddi/ns-bthddi-_brb_header)

[IoRegisterDeviceInterface](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-ioregisterdeviceinterface)