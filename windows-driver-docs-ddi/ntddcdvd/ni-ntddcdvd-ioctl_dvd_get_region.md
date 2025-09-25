# IOCTL_DVD_GET_REGION IOCTL

## Description

Returns Region Playback Control (RPC) information for a DVD device, such as whether the player supports the RPC2 standard, the current region code of the player, and the remaining number of times the player's region code can be changed by the user. This IOCTL also indicates the region code of the currently mounted disc. This only works if a DVD is in the drive. The [IOCTL_DVD_READ_KEY](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddcdvd/ni-ntddcdvd-ioctl_dvd_read_key) operation should be used to obtain only the device region code. If the drive region has not been set previously (if it is still at factory default) and if the inserted media has a region, the device region will be set to the current media region.

## Parameters

### Major code

### Input buffer

None.

### Input buffer length

None.

### Output buffer

The driver returns the [DVD_REGION](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddcdvd/ns-ntddcdvd-_dvd_region) data in the buffer at **Irp->AssociatedIrp.SystemBuffer**.

### Output buffer length

None. **Parameters.DeviceIoControl.OutputBufferLength** indicates the size, in bytes, of the buffer at **Irp->AssociatedIrp.SystemBuffer**, which must be >= **sizeof(**DVD_REGION**)**.

### Input/output buffer

### Input/output buffer length

### Status block

The **Information** field is set to the number of bytes transferred. The **Status** field is set to STATUS_SUCCESS or possibly STATUS_INSUFFICIENT_RESOURCES.

## See also

[DVD_REGION](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddcdvd/ns-ntddcdvd-_dvd_region)