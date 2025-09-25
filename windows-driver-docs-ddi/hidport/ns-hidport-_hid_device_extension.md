# _HID_DEVICE_EXTENSION structure

## Description

The HID_DEVICE_EXTENSION structure is used by a HID minidriver as its layout for the device extension of a HIDClass device's functional device object.

## Members

### `PhysicalDeviceObject`

Pointer to HID device's physical device object.

### `NextDeviceObject`

Pointer to the device object immediately below the functional device object in the HID device's device stack.

### `MiniDeviceExtension`

Pointer to the minidriver-specific portion of the device extension.

## See also

[HidRegisterMinidriver](https://learn.microsoft.com/windows-hardware/drivers/ddi/hidport/nf-hidport-hidregisterminidriver)