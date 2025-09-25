# USB_CONTROLLER_INFO_0 structure

## Description

The **USB_CONTROLLER_INFO_0** structure is used with the [IOCTL_USB_USER_REQUEST](https://learn.microsoft.com/windows/desktop/api/usbuser/ni-usbuser-ioctl_usb_user_request) I/O control request to retrieve information about the USB host controller.

## Members

### `PciVendorId`

The vendor identifier that is associated with the host controller device.

### `PciDeviceId`

The device identifier that is associated with the host controller.

### `PciRevision`

The revision number of the host controller device.

### `NumberOfRootPorts`

The number of root hub ports that the host controller has.

**Note** In Windows 8, the USB 3.0 driver stack does not include the number of SuperSpeed hubs in the reported **NumberOfRootPorts** value.

### `ControllerFlavor`

A [USB_CONTROLLER_FLAVOR](https://learn.microsoft.com/windows-hardware/drivers/ddi/content/usb/ne-usb-_usb_controller_flavor)-typed enumerator that specifies the type of controller.

### `HcFeatureFlags`

A bitwise OR of some combination of the following host controller feature flags.

| Host controller feature | Meaning |
| --- | --- |
| USB_HC_FEATURE_FLAG_PORT_POWER_SWITCHING | Power switching is enabled on the host controller. This flag allows powering of hot-plug devices. |
| USB_HC_FEATURE_FLAG_SEL_SUSPEND | Selective suspend is enabled on the host controller. |
| USB_HC_FEATURE_LEGACY_BIOS | The host controller has a legacy BIOS. |

**Note** In Windows 8, the underlying USB 3.0 driver stack does not set any host controller feature flags in **HcFeatureFlags.**

## Remarks

The **USB_CONTROLLER_INFO_0** structure is used with the USBUSER_GET_CONTROLLER_INFO_0 user-mode request. For a description of this request, see [IOCTL_USB_USER_REQUEST](https://learn.microsoft.com/windows/desktop/api/usbuser/ni-usbuser-ioctl_usb_user_request).

## See also

[IOCTL_USB_USER_REQUEST](https://learn.microsoft.com/windows/desktop/api/usbuser/ni-usbuser-ioctl_usb_user_request)

[USB_CONTROLLER_FLAVOR](https://learn.microsoft.com/windows-hardware/drivers/ddi/content/usb/ne-usb-_usb_controller_flavor)