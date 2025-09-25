## Description

The **USBCAMD_SelectAlternateInterface** function selects an alternate setting within the USB video streaming interface.

## Parameters

### `DeviceContext` [in]

Pointer to a device-specific context.

### `RequestInterface` [in, out]

Pointer to a [USBD_INTERFACE_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/usb/ns-usb-_usbd_interface_information) structure initialized with the proper values for a SELECT_INTERFACE URB request. This interface structure corresponds to a single isochronous interface on the device.

## Return value

**USBCAMD_SelectAlternateInterface** returns the status of the SELECT_INTERFACE USB bus driver request. Other possible error codes include:

| Return code | Description |
|---|---|
| **STATUS_DEVICE_DATA_ERROR** | USBCAMD failed to cancel outstanding bulk/interrupt IRPs. |
| **STATUS_INSUFFICIENT_RESOURCES** | There are insufficient resources to allocate the USB request block |

## Remarks

On successful completion, the structure pointed to by the *RequestInterface* argument is filled in with the information from the SELECT_INTERFACE USB bus driver request.

This function is typically called by a camera minidriver in response to a request to allocate or free bandwidth. This function should not be called when any video streams in the minidriver are open and/or actively streaming data.

## See also

[USBD_INTERFACE_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/usb/ns-usb-_usbd_interface_information)