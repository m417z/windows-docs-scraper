# _URB_CONTROL_FEATURE_REQUEST structure

## Description

The **_URB_CONTROL_FEATURE_REQUEST** structure is used by USB client drivers to set or clear features on a device, interface, or endpoint.

## Members

### `Hdr`

Pointer to a [_URB_HEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/usb/ns-usb-_urb_header) structure that specifies the URB header information. **Hdr.Function** indicates either a set or a clear feature operation, to perform on a device, interface, endpoint or other non-standard component. **Hdr.Function** must have one of the following values:

**Hdr.Length** must equal `sizeof(_URB_CONTROL_FEATURE_REQUEST)`.

### `Reserved`

Reserved. Do not use.

### `Reserved2`

Reserved. Do not use.

### `Reserved3`

Reserved. Do not use.

### `Reserved4`

Reserved. Do not use.

### `Reserved5`

Reserved. Do not use.

### `UrbLink`

Reserved. Do not use.

### `hca`

Reserved. Do not use.

### `Reserved0`

Reserved. Do not use.

### `FeatureSelector`

Specifies the USB-defined feature code to be cleared or set. Using a feature code that is invalid, cannot be set, or cannot be cleared will cause the target to stall. The bus driver will copy the value in the **FeatureSelector** member to the **wValue** field of the setup packet.

### `Index`

Specifies the device-defined index, returned by a successful configuration request, if the request is for an endpoint or interface. Otherwise, **Index** must be zero. The bus driver will copy the value in the **Index** member to the **wIndex** field of the setup packet.

### `Reserved1`

Reserved. Do not use.

## Remarks

Drivers can use the **UsbBuildFeatureRequest** service routine to format this URB.

The reserved members of this structure must be treated as opaque and are reserved for system use.

When a driver arms a USB device for remote wakeup with an IRP_MN_WAIT_WAKE request, the USB bus driver automatically sets remote wakeup feature on the device. A control feature URB is not necessary.

Likewise, when a driver issues a URB with a function type of URB_FUNCTION_SYNC_RESET_PIPE_AND_CLEAR_STALL to a pipe, the bus driver will automatically clear the pipe's endpoint stall feature. The driver does not have to send a control feature URB to the pipe to clear the endpoint stall.

## See also

[URB](https://learn.microsoft.com/windows-hardware/drivers/ddi/usb/ns-usb-_urb)

[USB Structures](https://learn.microsoft.com/windows-hardware/drivers/ddi/_usbref/#structures)

[_URB_HEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/usb/ns-usb-_urb_header)