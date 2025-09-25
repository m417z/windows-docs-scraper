# _WdfUsbTargetDeviceSelectSettingType enumeration

## Description

[Applies to KMDF and UMDF]

The **WdfUsbTargetDeviceSelectSettingType** enumeration defines techniques for specifying an alternate setting for a USB interface.

## Constants

### `WdfUsbInterfaceSelectSettingTypeDescriptor:0x10`

Specify an interface's alternate setting by providing a [USB_INTERFACE_DESCRIPTOR](https://learn.microsoft.com/windows-hardware/drivers/ddi/usbspec/ns-usbspec-_usb_interface_descriptor) structure.

### `WdfUsbInterfaceSelectSettingTypeSetting:0x11`

Specify an interface's alternate setting by providing a setting index value.

### `WdfUsbInterfaceSelectSettingTypeUrb:0x12`

Specify an interface's alternate setting by providing a [URB](https://learn.microsoft.com/windows-hardware/drivers/ddi/usb/ns-usb-_urb).

## Remarks

The **WdfUsbTargetDeviceSelectSettingType** enumeration is used in the [WDF_USB_INTERFACE_SELECT_SETTING_PARAMS](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfusb/ns-wdfusb-_wdf_usb_interface_select_setting_params) structure.

## See also

[URB](https://learn.microsoft.com/windows-hardware/drivers/ddi/usb/ns-usb-_urb)

[USB_INTERFACE_DESCRIPTOR](https://learn.microsoft.com/windows-hardware/drivers/ddi/usbspec/ns-usbspec-_usb_interface_descriptor)

[WDF_USB_INTERFACE_SELECT_SETTING_PARAMS](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfusb/ns-wdfusb-_wdf_usb_interface_select_setting_params)