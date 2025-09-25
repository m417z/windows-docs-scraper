# IOCTL_HID_GET_DEVICE_ATTRIBUTES IOCTL

## Description

The IOCTL_HID_GET_DEVICE_ATTRIBUTES request obtains a HIDClass device's attributes in a [HID_DEVICE_ATTRIBUTES](https://learn.microsoft.com/windows-hardware/drivers/ddi/hidport/ns-hidport-_hid_device_attributes) structure.

For general information about HIDClass devices, see [HID Collections](https://learn.microsoft.com/windows-hardware/drivers/hid/hid-collections).

## Parameters

### Major code

### Input buffer

**Parameters.DeviceIoControl.OutputBufferLength** contains the length, in bytes, of the HID class driver's buffer located at **Irp->UserBuffer**.

### Input buffer length

The size, in bytes, of the buffer must be greater than or equal to the size, in bytes, of a HID_DEVICE_ATTRIBUTES structure.

### Output buffer

The HID minidriver returns the device attributes in a HID_DEVICE_ATTRIBUTES structure at **Irp->UserBuffer**.

### Output buffer length

The size of a HID_DEVICE_ATTRIBUTES structure.

### Input/output buffer

### Input/output buffer length

### Status block

The HID minidriver sets the following fields of **Irp->IoStatus**:

* **Information** is set to the number of bytes transferred from the device.
* **Status** is set to STATUS_SUCCESS if the transfer completed without error. Otherwise, it is set to an appropriate NTSTATUS error code.

## See also

[HID_DEVICE_ATTRIBUTES](https://learn.microsoft.com/windows-hardware/drivers/ddi/hidport/ns-hidport-_hid_device_attributes)

[IOCTL_HID_GET_DEVICE_DESCRIPTOR](https://learn.microsoft.com/windows-hardware/drivers/ddi/hidport/ni-hidport-ioctl_hid_get_device_descriptor)