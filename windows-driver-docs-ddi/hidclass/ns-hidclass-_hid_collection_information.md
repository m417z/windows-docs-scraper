# _HID_COLLECTION_INFORMATION structure

## Description

The HID_COLLECTION_INFORMATION structure contains general information about a [top-level collection](https://learn.microsoft.com/windows-hardware/drivers/hid/top-level-collections).

## Members

### `DescriptorSize`

Specifies the size, in bytes, of a collection's [preparsed data](https://learn.microsoft.com/windows-hardware/drivers/hid/preparsed-data).

### `Polled`

Indicates, if **TRUE**, that the HID class driver must poll the device to receive data. Otherwise, if **Polled** is **FALSE**, the device uses asynchronous interrupts to signal the host that the device has HID reports to send to the host.

### `Reserved1`

Reserved for internal system use.

### `VendorID`

Specifies a HID device's vendor ID.

### `ProductID`

Specifies a HID device's product ID.

### `VersionNumber`

Specifies the manufacturer's revision number for a HID device.

## Remarks

Kernel-mode drivers can use an [IOCTL_HID_GET_COLLECTION_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/hidclass/ni-hidclass-ioctl_hid_get_collection_information) to obtain a collection's **HID_COLLECTION_INFORMATION** structure.

## See also

[HID_COLLECTION_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/hidclass/ns-hidclass-_hid_collection_information)

[IOCTL_HID_GET_COLLECTION_DESCRIPTOR](https://learn.microsoft.com/windows-hardware/drivers/ddi/hidclass/ni-hidclass-ioctl_hid_get_collection_descriptor)

[IOCTL_HID_GET_COLLECTION_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/hidclass/ni-hidclass-ioctl_hid_get_collection_information)