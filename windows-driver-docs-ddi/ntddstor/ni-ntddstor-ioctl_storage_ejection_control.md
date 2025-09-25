# IOCTL_STORAGE_EJECTION_CONTROL IOCTL

## Description

Locks the device to prevent removal of the media. If the driver can prevent the media from being removed while the drive is in use, the driver disables or enables the mechanism that ejects media, thereby locking the drive. A caller must open the device with FILE_READ_ATTRIBUTES to send this request.

Unlike [IOCTL_STORAGE_MEDIA_REMOVAL](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddstor/ni-ntddstor-ioctl_storage_media_removal), the driver tracks **IOCTL_STORAGE_EJECTION_CONTROL** requests by caller and ignores unlock requests for which it has not received a lock request from the same caller, thereby preventing other callers from unlocking the drive.

A driver for a removable-media device - can support this IOCTL must do the following:

1. Keep a lock count, tagged by caller, in the device object extension.
2. Keep the lock count per physical device.
3. When called with this IOCTL, if the flag to prevent removing the media is set, increment the count; if the flag is clear and the driver has previously received a lock request from the same caller, decrement the count.
4. Prevent removal of the media unless all lock counts are zero.

Under normal circumstances, the caller who locked the device using IOCTL_STORAGE_EJECTION_CONTROL, unlocks the device by sending IOCTL_STORAGE_EJECTION_CONTROL again with **Irp->AssociatedIrp.SystemBuffer** set to a boolean value of **FALSE**. However, sometimes the caller fails to unlock the device properly.

To ensure that media removal locks are released properly, the class driver keeps track of callers who lock the media with IOCTL_STORAGE_EJECTION_CONTROL. If the caller terminates without unlocking the device, the class driver unlocks the device.

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

[IOCTL_STORAGE_EJECT_MEDIA](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddstor/ni-ntddstor-ioctl_storage_eject_media)