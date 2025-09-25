# IOCTL_HID_GET_REPORT_DESCRIPTOR IOCTL

## Description

The IOCTL_HID_GET_REPORT_DESCRIPTOR request obtains the report descriptor for a HIDClass device.

For general information about HIDClass devices, see [HID Collections](https://learn.microsoft.com/windows-hardware/drivers/hid/hid-collections).

## Parameters

### Major code

### Input buffer

**Parameters.DeviceIoControl.OutputBufferLength** specifies the length, in bytes, of the locked-down buffer at **Irp->UserBuffer**.

### Input buffer length

The size of **OutputBufferLength**.

### Output buffer

The HID minidriver fills the buffer at **Irp->UserBuffer** with the report descriptor.

### Output buffer length

The size of the report descriptor.

### Input/output buffer

### Input/output buffer length

### Status block

HID minidrivers that carry out the I/O to the device set the following fields of **Irp->IoStatus**:

* **Information** is set to the number of bytes transferred from the device.
* **Status** is set to STATUS_SUCCESS if the transfer completed without error. Otherwise, it is set to an appropriate NTSTATUS error code.

HID minidrivers that call other drivers with this IOCTL to carry out the I/O to their device, should ensure that the **Information** field of the status block is correct and not change the contents of the **Status** field.

## See also

[IOCTL_GET_PHYSICAL_DESCRIPTOR](https://learn.microsoft.com/windows-hardware/drivers/ddi/hidclass/ni-hidclass-ioctl_get_physical_descriptor)

[IOCTL_HID_GET_DEVICE_DESCRIPTOR](https://learn.microsoft.com/windows-hardware/drivers/ddi/hidport/ni-hidport-ioctl_hid_get_device_descriptor)