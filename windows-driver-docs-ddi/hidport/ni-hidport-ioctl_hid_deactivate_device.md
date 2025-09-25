# IOCTL_HID_DEACTIVATE_DEVICE IOCTL

## Description

The IOCTL_HID_DEACTIVATE_DEVICE request deactivates a HIDClass device, which causes it to stop operations and terminate all outstanding I/O requests.

For general information about HIDClass devices, see [HID Collections](https://learn.microsoft.com/windows-hardware/drivers/hid/hid-collections).

## Parameters

### Major code

### Input buffer

**Parameters.DeviceIoControl.Type3InputBuffer** contains the collection identifier, as a ULONG value, of the collection that is ceasing operations.

### Input buffer length

The length of a ULONG value.

### Output buffer

None.

### Output buffer length

None

### Input/output buffer

### Input/output buffer length

### Status block

 HID minidrivers that carry out the I/O to the device set the following fields of **Irp->IoStatus**:

* **Information** is set to zero.
* **Status** is set to STATUS_SUCCESS if the transfer completed without error. Otherwise, it is set to an appropriate NTSTATUS error code.

HID minidrivers that call other drivers with this IRP to carry out the I/O to their device should ensure that the **Information** field of the status block is zero and must not change the contents of the **Status** field.

## See also

[IOCTL_HID_ACTIVATE_DEVICE](https://learn.microsoft.com/windows-hardware/drivers/ddi/hidport/ni-hidport-ioctl_hid_activate_device)