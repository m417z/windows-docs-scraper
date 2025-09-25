# IOCTL_DVD_SEND_KEY IOCTL

## Description

Sends the specified key to a DVD device to complete the related step in an authentication sequence.

This IOCTL has only read access to the device and cannot send keys that make alterations to the hardware configuration. Therefore, this request is limited to sending key types **DvdChallengeKey**, **DvdBusKey2**, and **DvdInvalidateAGID**.

The [IOCTL_DVD_SEND_KEY2](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddcdvd/ni-ntddcdvd-ioctl_dvd_send_key2) request has write access to the device and is not limited to these three key types.

For more information, see [DVD_KEY_TYPE](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddcdvd/ne-ntddcdvd-dvd_key_type).

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