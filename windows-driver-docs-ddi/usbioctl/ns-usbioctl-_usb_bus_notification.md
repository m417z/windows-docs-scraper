# _USB_BUS_NOTIFICATION structure

## Description

Stores certain bus information. This structure is used in the [IOCTL_INTERNAL_USB_GET_BUS_INFO](https://learn.microsoft.com/windows-hardware/drivers/ddi/usbioctl/ni-usbioctl-ioctl_internal_usb_get_bus_info) request.

## Members

### `NotificationType`

A [**USB_NOTIFICATION_TYPE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/usbioctl/ne-usbioctl-_usb_notification_type)-value that indicates the type of notification.

### `TotalBandwidth`

The total bandwidth, in bits per second, available on the bus.

### `ConsumedBandwidth`

The mean bandwidth already in use, in bits per second.

### `ControllerNameLength`

The length of the Unicode symbolic name (in bytes) for the host controller to which this device is attached. The length does not include NULL.

## Remarks

## See also