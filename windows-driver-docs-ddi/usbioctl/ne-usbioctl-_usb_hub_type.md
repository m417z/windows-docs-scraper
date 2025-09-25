# _USB_HUB_TYPE enumeration

## Description

The **USB_HUB_TYPE** enumeration defines constants that indicate the type of USB hub.

The hub type is retrieved by the [IOCTL_USB_GET_HUB_INFORMATION_EX](https://learn.microsoft.com/windows-hardware/drivers/ddi/usbioctl/ni-usbioctl-ioctl_usb_get_hub_information_ex) I/O control request.

The request retrieves the hub descriptor associated with the specified hub in the [USB_HUB_INFORMATION_EX](https://learn.microsoft.com/windows-hardware/drivers/ddi/usbioctl/ns-usbioctl-_usb_hub_information_ex) structure. The **HubType** member contains a **USB_HUB_TYPE** enumerator that the application can use to evaluate the type of hub descriptor retrieved by the request.

## Syntax

```cpp
typedef enum _USB_HUB_TYPE {
  UsbRootHub = 1,
  Usb20Hub = 2,
  Usb30Hub = 3
} USB_HUB_TYPE;
```

## Constants

### `UsbRootHub`

Indicates a root hub.

### `Usb20Hub`

Indicates that the retrieved hub descriptor is defined in USB 2.0 and 1.1 specifications.

### `Usb30Hub`

Indicates that the retrieved hub descriptor is defined in USB 3.0 specification.

## See also

[IOCTL_USB_GET_HUB_INFORMATION_EX](https://learn.microsoft.com/windows-hardware/drivers/ddi/usbioctl/ni-usbioctl-ioctl_usb_get_hub_information_ex)

[USB Constants and Enumerations](https://learn.microsoft.com/windows-hardware/drivers/ddi/_usbref/#enumerations)

[USB_HUB_INFORMATION_EX](https://learn.microsoft.com/windows-hardware/drivers/ddi/usbioctl/ns-usbioctl-_usb_hub_information_ex)