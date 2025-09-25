# IOCTL_HID_SET_POLL_FREQUENCY_MSEC IOCTL

## Description

The IOCTL_HID_SET_POLL_FREQUENCY_MSEC request sets the polling frequency, in milliseconds, for a [top-level collection](https://learn.microsoft.com/windows-hardware/drivers/hid/top-level-collections).

User-mode applications or kernel-mode drivers that perform irregular, opportunistic reads on a polled device must furnish a polling interval of zero. In such cases, IOCTL_HID_SET_POLL_FREQUENCY_MSEC does not actually change the polling frequency of the device; but if the report data is not stale when it is read, the read is completed immediately with the latest report data for the indicated collection. If the report data is stale, it is refreshed immediately, without waiting for the expiration of the polling interval, and the read is completed with the new data.

If the value for the polling interval that is provided in the IRP is not zero, it must be >= MIN_POLL_INTERVAL_MSEC and <= MAX_POLL_INTERVAL_MSEC.

Polling may be limited if there are multiple top-level collections.

For general information about HIDClass devices, see [HID Collections](https://learn.microsoft.com/windows-hardware/drivers/hid/hid-collections).

## Parameters

### Major code

### Input buffer

**Parameters.DeviceIoControl.InputBufferLength** in the I/O stack location of the IRP indicates the size, in bytes, of the input buffer, which must be >= **sizeof**(ULONG).

**Irp->AssociatedIrp.SystemBuffer** contains the new polling interval.

### Input buffer length

A value greater than or equal to **sizeof**(ULONG).

### Output buffer

None.

### Output buffer length

None.

### Input/output buffer

### Input/output buffer length

### Status block

The HID class driver sets the **Status** member of **Irp->IoStatus** to STATUS_SUCCESS if the transfer completed without error. Otherwise, it is set to an appropriate NTSTATUS error code.

## See also

[IOCTL_HID_GET_POLL_FREQUENCY_MSEC](https://learn.microsoft.com/windows-hardware/drivers/ddi/hidclass/ni-hidclass-ioctl_hid_get_poll_frequency_msec)