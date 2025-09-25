# IOCTL_DVD_READ_KEY IOCTL

## Description

Returns a copy-protection key of the specified type: challenge key, bus key, title key, read RPC key, set RPC key, or disk key. A challenge key or bus key is sent back to the device to complete the related step in a DVD authentication sequence. After the authentication sequence is completed, a title key is used to encrypt and decrypt user data transferred from a DVD disc and a disk key is used to encrypt and decrypt title key data. If the drive region has not been set previously (if it is still at factory default) and if the inserted media has a region, the device region will be set to the current media region.

## Parameters

### Major code

### Input buffer

The buffer at **Irp->AssociatedIrp.SystemBuffer** contains a [DVD_COPY_PROTECT_KEY](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddcdvd/ns-ntddcdvd-_dvd_copy_protect_key) structure that indicates the session ID of the DVD session and the type of key to return.

### Input buffer length

**Parameters.DeviceIoControl.OutputBufferLength** indicates the size, in bytes, of the buffer, which must be >= the size of one of the following: DVD_CHALLENGE_KEY_LENGTH, DVD_BUS_KEY_LENGTH, DVD_TITLE_KEY_LENGTH, DVD_RPC_KEY_LENGTH, DVD_SET_RPC_KEY_LENGTH, or DVD_DISK_KEY_LENGTH.

### Output buffer

The driver returns the DVD_COPY_PROTECT_KEY data in the buffer at **Irp->AssociatedIrp.SystemBuffer**.

### Output buffer length

Length of a [DVD_COPY_PROTECT_KEY](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddcdvd/ns-ntddcdvd-_dvd_copy_protect_key).

### Input/output buffer

### Input/output buffer length

### Status block

The **Information** field is set to the number of bytes transferred. The **Status** field is set to STATUS_SUCCESS, or possibly to STATUS_INSUFFICIENT_RESOURCES.

## See also

[DVD_COPY_PROTECT_KEY](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddcdvd/ns-ntddcdvd-_dvd_copy_protect_key)