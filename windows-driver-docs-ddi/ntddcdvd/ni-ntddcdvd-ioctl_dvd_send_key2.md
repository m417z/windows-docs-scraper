# IOCTL_DVD_SEND_KEY2 IOCTL

## Description

Sends the specified key to a DVD device -to complete the related step in an authentication sequence. The IOCTL_DVD_SEND_KEY2 request has write access to the device and can send a broader range of key types than [IOCTL_DVD_SEND_KEY](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddcdvd/ni-ntddcdvd-ioctl_dvd_send_key).

## Parameters

### Major code

### Input buffer

The buffer at **Irp->AssociatedIrp.SystemBuffer** contains a [DVD_COPY_PROTECT_KEY](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddcdvd/ns-ntddcdvd-_dvd_copy_protect_key) structure that indicates the session ID, key type, and key to be sent to the device.

### Input buffer length

Length of a [DVD_COPY_PROTECT_KEY](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddcdvd/ns-ntddcdvd-_dvd_copy_protect_key).

### Output buffer

None.

### Output buffer length

None.

### Input/output buffer

### Input/output buffer length

### Status block

The **Information** field is set to zero. The **Status** field is set to STATUS_SUCCESS, or possibly to STATUS_INSUFFICIENT_RESOURCES.

## See also

[DVD_COPY_PROTECT_KEY](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddcdvd/ns-ntddcdvd-_dvd_copy_protect_key)