# IOCTL_STORAGE_MEDIA_REMOVAL IOCTL

## Description

Locks the device to prevent removal of the media. If the driver can prevent the media from being removed while the drive is in use, it disables or enables the mechanism that ejects media on a device - the caller has opened for read or write access.

Unlike [IOCTL_STORAGE_EJECTION_CONTROL](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddstor/ni-ntddstor-ioctl_storage_ejection_control), for which the driver tracks requests by caller, the driver ignores IOCTL_STORAGE_MEDIA_REMOVAL unlock requests only if its lock count is already zero, thereby allowing any caller to unlock the drive.

A driver for such a removable-media device that can support this IOCTL must do the following:

1. Keep a lock count in the device object extension.
2. Keep the lock count per physical device.
3. When called with this IOCTL, if the flag to prevent removing the media is set, increment the count; if the flag is clear, decrement the count.
4. Prevent removal of the media unless all lock counts are zero.

## Parameters

### Major code

### Input buffer

The buffer at **Irp->AssociatedIrp.SystemBuffer** contains a Boolean value, with **TRUE** indicating that the driver should lock the media in the drive.

### Input buffer length

The length of a Boolean.

### Output buffer

None.

### Output buffer length

None.

### Input/output buffer

### Input/output buffer length

### Status block

The **Information** field is set to zero. The **Status** field is set to STATUS_SUCCESS, or possibly to STATUS_INVALID_DEVICE_REQUEST, STATUS_NO_MEDIA_IN_DEVICE, or STATUS_DEVICE_NOT_CONNECTED.

## See also

[IOCTL_STORAGE_EJECTION_CONTROL](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddstor/ni-ntddstor-ioctl_storage_ejection_control)