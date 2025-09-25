# IOCTL_HID_GET_POLL_FREQUENCY_MSEC IOCTL

## Description

The IOCTL_HID_GET_POLL_FREQUENCY_MSEC request obtains the current polling frequency, in milliseconds, of a [top-level collection](https://learn.microsoft.com/windows-hardware/drivers/hid/top-level-collections).

For general information about HIDClass devices, see [HID Collections](https://learn.microsoft.com/windows-hardware/drivers/hid/hid-collections).

## Parameters

### Major code

### Input buffer

**Parameters.DeviceIoControl.OutputBufferLength** in the I/O stack location of the IRP indicates the size, in bytes, of the output buffer, which must be >= **sizeof**(ULONG).

### Input buffer length

Greater than or equal to **sizeof**(ULONG).

### Output buffer

**Irp->AssociatedIrp.SystemBuffer** points to a buffer that will receive the polling frequency.

### Output buffer length

### Input/output buffer

### Input/output buffer length

### Status block

The HID class driver sets the following fields of **Irp->IoStatus**:

* **Information** is set to **sizeof**(ULONG) if the polling frequency is successfully retrieved.
* **Status** is set to STATUS_SUCCESS if the transfer completed without error. Otherwise, it is set to an appropriate NTSTATUS error code.

## See also

[IOCTL_HID_SET_POLL_FREQUENCY_MSEC](https://learn.microsoft.com/windows-hardware/drivers/ddi/hidclass/ni-hidclass-ioctl_hid_set_poll_frequency_msec)