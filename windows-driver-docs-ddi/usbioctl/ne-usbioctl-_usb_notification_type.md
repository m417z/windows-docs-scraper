# _USB_NOTIFICATION_TYPE enumeration

## Description

Defines values for the type of notification that can be requested by a client driver.

## Constants

### `EnumerationFailure`

Reserved.

### `InsufficentBandwidth`

Reserved.

### `InsufficentPower`

Reserved.

### `OverCurrent`

Reserved.

### `ResetOvercurrent`

Reserved.

### `AcquireBusInfo`

Indicates the information about the bus. This is retrieved by the [IOCTL_INTERNAL_USB_GET_BUS_INFO](https://learn.microsoft.com/windows-hardware/drivers/ddi/usbioctl/ni-usbioctl-ioctl_internal_usb_get_bus_info) request. Also see, [**USB_BUS_NOTIFICATION**](https://learn.microsoft.com/windows-hardware/drivers/ddi/usbioctl/ns-usbioctl-_usb_bus_notification).

### `AcquireHubName`

Reserved.

### `AcquireControllerName`

Reserved.

### `HubOvercurrent`

Reserved.

### `HubPowerChange`

Reserved.

### `HubNestedTooDeeply`

Reserved.

### `ModernDeviceInLegacyHub`

Reserved.

## Remarks

## See also