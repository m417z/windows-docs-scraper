# _WDF_USB_DEVICE_TRAITS enumeration

## Description

[Applies to KMDF and UMDF]

The **WDF_USB_DEVICE_TRAITS** enumeration identifies USB device traits.

## Constants

### `WDF_USB_DEVICE_TRAIT_SELF_POWERED:0x00000001`

The device is self-powered.

### `WDF_USB_DEVICE_TRAIT_REMOTE_WAKE_CAPABLE:0x00000002`

The device has a remote wakeup capability.

### `WDF_USB_DEVICE_TRAIT_AT_HIGH_SPEED:0x00000004`

The device is operating at high speed or SuperSpeed.

## Remarks

The **WDF_USB_DEVICE_TRAITS** enumeration is used in the [WDF_USB_DEVICE_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfusb/ns-wdfusb-_wdf_usb_device_information) structure.

## See also

[WDF_USB_DEVICE_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfusb/ns-wdfusb-_wdf_usb_device_information)