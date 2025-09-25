# IOCTL_SMARTCARD_POWER IOCTL

## Description

Windows may require a driver to have this IOCTL to be NOP and return success.

The **IOCTL_SMARTCARD_POWER**
control code puts the smart card into one of the following power modes:

| Power Mode Setting | Description |
| --- | --- |
| SCARD_COLD_RESET | Sets virtual power that only affects the IOCTL_SMARTCARD_GET_STATE. No impact on the actual reader power states. Returns SCARD_SPECIFIC in IOCTL_SMARTCARD_GET_STATE if the card is present. |
| SCARD_WARM_RESET | Sets virtual power that only affects the IOCTL_SMARTCARD_GET_STATE. No impact on the actual reader power states. Returns SCARD_SPECIFIC in IOCTL_SMARTCARD_GET_STATE if the card is present. |

## Parameters

### Major code

### Input buffer

(DWORD) that contains the power state to set.

### Input buffer length

### Output buffer

None.

### Output buffer length

### Input/output buffer

### Input/output buffer length

### Status block

**Irp->IoStatus.Status** is set to **STATUS_SUCCESS** if the request is successful. Possible error codes are:

| Return Code | Description |
| --- | --- |
| STATUS_NO_MEDIA | This code is returned if no smart card is detected. |
| STATUS_INVALID_PARAMETER | This code is returned if the input or output buffer is invalid. |
| STATUS_DEVICE_POWERED_OFF | This code is returned if the proximity radio control is off. |

## Remarks

Virtual power is set to TRUE for COLD_RESET and WARM_RESET; otherwise, virtual power is set to FALSE.

## See also

[Near field communication (NFC) design guide](https://learn.microsoft.com/windows-hardware/drivers/nfc/)

[Smart card design guide](https://learn.microsoft.com/windows-hardware/drivers/nfc/design-guide-smart-card)