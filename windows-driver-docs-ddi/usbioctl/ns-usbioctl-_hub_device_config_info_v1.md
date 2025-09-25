# _HUB_DEVICE_CONFIG_INFO_V1 structure

## Description

The **HUB_DEVICE_CONFIG_INFO** structure is used in conjunction with the kernel-mode IOCTL, [IOCTL_INTERNAL_USB_GET_DEVICE_CONFIG_INFO](https://learn.microsoft.com/windows-hardware/drivers/ddi/usbioctl/ni-usbioctl-ioctl_internal_usb_get_device_config_info) to request to report information about a USB device and the hub to which the device is attached.

## Members

### `Version`

Specifies the version number. Must be set to 1.

### `Length`

Specifies the size of the **HUB_DEVICE_CONFIG_INFO** structure. Must be set by the caller.

### `HubFlags`

Specifies the hub capabilities in a [USB_HUB_CAP_FLAGS](https://learn.microsoft.com/windows-hardware/drivers/ddi/usbioctl/ns-usbioctl-_usb_hub_cap_flags) structure.

### `HardwareIds`

The PnP hardware ID multi-string for the USB device in a [USB_ID_STRING](https://learn.microsoft.com/windows-hardware/drivers/ddi/usbioctl/ns-usbioctl-_usb_id_string) structure.

### `CompatibleIds`

 PnP compatible ID multi-string for the USB device in a [USB_ID_STRING](https://learn.microsoft.com/windows-hardware/drivers/ddi/usbioctl/ns-usbioctl-_usb_id_string) structure.

### `DeviceDescription`

Description of the device in a [USB_ID_STRING](https://learn.microsoft.com/windows-hardware/drivers/ddi/usbioctl/ns-usbioctl-_usb_id_string) structure. This may be set to **NULL**.

### `Reserved`

Reserved.

### `UxdSettings`

## Remarks

 The **Buffer** member of the [USB_ID_STRING](https://learn.microsoft.com/windows-hardware/drivers/ddi/usbioctl/ns-usbioctl-_usb_id_string) structure points to a string that contains **HardwareIds**, **CompatibleIds**, and **DeviceDescription** values.
The caller is responsible for releasing this string buffer, which is allocated by the hub driver.

## See also

[IOCTL_INTERNAL_USB_GET_DEVICE_CONFIG_INFO](https://learn.microsoft.com/windows-hardware/drivers/ddi/usbioctl/ni-usbioctl-ioctl_internal_usb_get_device_config_info)

[USB Structures](https://learn.microsoft.com/windows-hardware/drivers/ddi/_usbref/#structures)

[USB_HUB_CAP_FLAGS](https://learn.microsoft.com/windows-hardware/drivers/ddi/usbioctl/ns-usbioctl-_usb_hub_cap_flags)

[USB_ID_STRING](https://learn.microsoft.com/windows-hardware/drivers/ddi/usbioctl/ns-usbioctl-_usb_id_string)