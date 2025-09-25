# IOCTL_SMARTCARD_IS_ABSENT IOCTL

## Description

The **IOCTL_SMARTCARD_IS_ABSENT**
control code returns immediately with STATUS_SUCCESS if no smart card is currently detected. If smart cards are detected, the IOCTL needs to be pended by the driver and it needs to complete the request on card departure. Closing the file handle automatically unsubscribes the event.

## Parameters

### Major code

### Input buffer

None.

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
| STATUS_PENDING | This code is returned when the attribute ID is SCARD_ATTR_DEVICE_IN_USE. |
| STATUS_DEVICE_BUSY | This code is returned if the operation is already waiting for the absent event. |
| STATUS_INVALID_DEVICE_STATE | This code is returned if the device cannot accept the request. |
| STATUS_INVALID_PARAMETER | This code is returned when the input or output buffers are invalid. |
| STATUS_DEVICE_POWERED_OFF | This code is returned when the proximity radio control is off. |

## Remarks

The following actions are required when using this IOCTL:

* The driver must support CancelIo on this pended IOCTL.
* It is a power-managed request. The pended IOCTL will keep the driver in D0 power state.

## See also

[Near field communication (NFC) design guide](https://learn.microsoft.com/windows-hardware/drivers/nfc/)

[Smart card design guide](https://learn.microsoft.com/windows-hardware/drivers/nfc/design-guide-smart-card)