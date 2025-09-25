# UsbBuildGetStatusRequest macro

## Description

 The **UsbBuildGetStatusRequest** macro formats an [URB](https://learn.microsoft.com/windows-hardware/drivers/ddi/usb/ns-usb-_urb) to obtain status from a device, interface, endpoint, or other device-defined target on a USB device.

## Parameters

### `urb` [in, out]

Pointer to an [URB](https://learn.microsoft.com/windows-hardware/drivers/ddi/usb/ns-usb-_urb) to be formatted as a status request.

### `op` [in]

Specifies one of the following values:

#### URB_FUNCTION_GET_STATUS_FROM_DEVICE

Retrieves status from a USB device.

#### URB_FUNCTION_GET_STATUS_FROM_INTERFACE

Retrieves status from an interface on a USB device.

#### URB_FUNCTION_GET_STATUS_FROM_ENDPOINT

Retrieves status from an endpoint for an interface on a USB device.

#### URB_FUNCTION_GET_STATUS_FROM_OTHER

Retrieves status from a device-defined target on a USB device.

### `index` [in]

Specifies the device-defined index, returned by a successful configuration request, if the request is for an endpoint or interface. Otherwise, *Index* must be zero.

### `transferBuffer` [in, optional]

Pointer to a resident buffer to receive the status data or is **NULL** if an MDL is supplied in *TransferBufferMDL*.

### `transferBufferMDL` [in, optional]

Pointer to an MDL that describes a resident buffer to receive the status data or is **NULL** if a buffer is supplied in *TransferBuffer*.

### `link` [in]

Reserved. Must be set to **NULL**.

## See also

[URB](https://learn.microsoft.com/windows-hardware/drivers/ddi/usb/ns-usb-_urb)

[USB device driver programming reference](https://learn.microsoft.com/windows-hardware/drivers/ddi/_usbref/)

[_URB_CONTROL_GET_STATUS_REQUEST](https://learn.microsoft.com/windows-hardware/drivers/ddi/usb/ns-usb-_urb_control_get_status_request)