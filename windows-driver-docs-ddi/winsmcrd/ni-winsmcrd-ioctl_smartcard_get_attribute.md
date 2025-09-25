# IOCTL_SMARTCARD_GET_ATTRIBUTE IOCTL

## Description

The **IOCTL_SMARTCARD_GET_ATTRIBUTE**
control code queries for smart card attributes.

## Parameters

### Major code

### Input buffer

(DWORD) contains the attribute tag.

### Input buffer length

### Output buffer

(DWORD) contains the attribute tag.

### Output buffer length

### Input/output buffer

### Input/output buffer length

### Status block

**Irp->IoStatus.Status** is set to **STATUS_SUCCESS** if the request is successful. Possible error codes are:

| Return Code | Description |
| --- | --- |
| STATUS_NOT_SUPPORTED | This code is returned if the attribute is not supported. |
| STATUS_INVALID_PARAMETER | This code is returned if the input or output buffers are invalid. |
| STATUS_BUFFER_TOO_SMALL | This code is returned if the output buffer is too small for the return data. |
| STATUS_INVALID_DEVICE_STATE | This code is returned if the device cannot accept the request. |
| STATUS_DEVICE_POWERED_OFF | This code is returned if the proximity radio control is off when the call is made. |

## Remarks

The following actions are required when using this IOCTL:

* The driver must support CancelIo on this pended IOCTL.
* If this IOCTL is issued when the NFCC is in RF discovery state, the driver needs to put the NFCC into RF idle state, configure the routing table, and restart RF discovery.

## See also

[Near field communication (NFC) design guide](https://learn.microsoft.com/windows-hardware/drivers/nfc/)

[Smart card design guide](https://learn.microsoft.com/windows-hardware/drivers/nfc/design-guide-smart-card)