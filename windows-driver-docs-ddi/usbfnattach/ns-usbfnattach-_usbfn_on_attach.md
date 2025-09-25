# _USBFN_ON_ATTACH structure

## Description

Describes the detected port type and attach action.

## Members

### `PortType`

Detected port type defined by one of the [USBFN_PORT_TYPE](https://learn.microsoft.com/windows-hardware/drivers/ddi/usbfnbase/ne-usbfnbase-_usbfn_port_type)-typed values.

### `AttachAction`

The operation that must be performed depending on the port type. This value is defined in the [USBFN_ATTACH_ACTION](https://learn.microsoft.com/windows-hardware/drivers/ddi/usbfnattach/ne-usbfnattach-_usbfn_attach_action) enumeration.

## See also

[USBFN_GET_ATTACH_ACTION](https://learn.microsoft.com/windows-hardware/drivers/ddi/usbfnattach/nc-usbfnattach-usbfn_get_attach_action)