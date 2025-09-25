# _USB_DEVICE_CHARACTERISTICS structure

## Description

Contains information about the USB device’s characteristics, such as the maximum send and receive delays for any request. This structure is used in the [IOCTL_USB_GET_DEVICE_CHARACTERISTICS](https://learn.microsoft.com/windows-hardware/drivers/ddi/usbioctl/ni-usbioctl-ioctl_usb_get_device_characteristics) request.

## Members

### `Version`

The version should be set to USB_DEVICE_CHARACTERISTICS_VERSION_1.

### `Reserved`

Reserved.

### `UsbDeviceCharacteristicsFlags`

A bitmask of flags that indicates to the client driver the transport characteristics that are available and are returned by this structure.

If the USB_DEVICE_CHARACTERISTICS_MAXIMUM_PATH_DELAYS_AVAILABLE

flag is set, **MaximumSendPathDelayInMilliSeconds** and **MaximumCompletionPathDelayInMilliSeconds** contain valid information. Otherwise they are not available and must not be used by the client driver.

### `MaximumSendPathDelayInMilliSeconds`

Contains the maximum delay in milliseconds for any request that is submitted by the client driver and is received by the USB driver stack to the time it is programmed in the host controller, including the maximum delay associated with the network medium if it is a MA-USB host controller.

### `MaximumCompletionPathDelayInMilliSeconds`

Contains the maximum delay in milliseconds the host controller completes any request for the device to the time the request is completed and sent back to the client driver. For a MA-USB controller this includes any delay associated with the network medium.

## See also

[IOCTL_USB_GET_DEVICE_CHARACTERISTICS](https://learn.microsoft.com/windows-hardware/drivers/ddi/usbioctl/ni-usbioctl-ioctl_usb_get_device_characteristics)