# _HID_DEVICE_ATTRIBUTES structure

## Description

The HID_DEVICE_ATTRIBUTES structure contains information about a HIDClass device.

## Members

### `Size`

Specifies the size of the structure. This member should be treated as read-only when a HID minidriver uses this structure to complete an [IOCTL_HID_GET_DEVICE_ATTRIBUTES](https://learn.microsoft.com/windows-hardware/drivers/ddi/hidport/ni-hidport-ioctl_hid_get_device_attributes) request.

### `VendorID`

Specifies a HID device's vendor ID.

### `ProductID`

Specifies a HID device's product ID.

### `VersionNumber`

Specifies the manufacturer's revision number for a HID device.

### `Reserved`

Reserved for internal system use.

## Remarks

The HID class driver uses this structure to obtain device attributes when it sends an [IOCTL_HID_GET_DEVICE_ATTRIBUTES](https://learn.microsoft.com/windows-hardware/drivers/ddi/hidport/ni-hidport-ioctl_hid_get_device_attributes) request to a HID minidriver.

## See also

[IOCTL_HID_GET_DEVICE_ATTRIBUTES](https://learn.microsoft.com/windows-hardware/drivers/ddi/hidport/ni-hidport-ioctl_hid_get_device_attributes)