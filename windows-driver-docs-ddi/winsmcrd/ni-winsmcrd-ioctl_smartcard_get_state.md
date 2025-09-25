# IOCTL_SMARTCARD_GET_STATE IOCTL

## Description

The **IOCTL_SMARTCARD_GET_STATE**
control code gets the current status of the smart card.

## Parameters

### Major code

### Input buffer

None.

### Input buffer length

### Output buffer

(DWORD) one of the following states:

| State | Description |
| --- | --- |
| SCARD_UNKNOWN | Unknown state |
| SCARD_ABSENT | Card is not detected |
| SCARD_SWALLOWED | Card is present but not powered. When SCARD_POWER_DOWN is set. |
| SCARD_SPECIFIC | Card is present and communication protocols are established. |

### Output buffer length

### Input/output buffer

### Input/output buffer length

### Status block

**Irp->IoStatus.Status** is set to **STATUS_SUCCESS** if the request is successful. Possible error codes are:

| Return Code | Description |
| --- | --- |
| STATUS_INVALID_PARAMETER | This code is returned when the input or output buffers are invalid. |
| STATUS_BUFFER_TOO_SMALL | This code is returned if the output buffer is too small for the return data. |
| STATUS_DEVICE_POWERED_OFF | This code is returned if the proximity radio control is off. |

## See also

[Near field communication (NFC) design guide](https://learn.microsoft.com/windows-hardware/drivers/nfc/)

[Smart card design guide](https://learn.microsoft.com/windows-hardware/drivers/nfc/design-guide-smart-card)