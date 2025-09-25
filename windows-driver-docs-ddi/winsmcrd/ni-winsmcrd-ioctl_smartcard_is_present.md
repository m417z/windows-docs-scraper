# IOCTL_SMARTCARD_IS_PRESENT IOCTL

## Description

The **IOCTL_SMARTCARD_IS_PRESENT**
control code detects whether a smart card is currently detected. If a card is present, it returns immediately with STATUS_SUCCESS. If no smart card is detected, it subscribes to the smart card arrival event and is kept pending. Closing the file handle unsubscribes the event.

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
| STATUS_PENDING | This code is returned if the operation is waiting for the smart card to approach into the radio field. |
| STATUS_DEVICE_BUSY | This code is returned if the operation is already waiting for the present event. |
| STATUS_INVALID_DEVICE_STATE | This code is returned if the device cannot accept the request. |
| STATUS_INVALID_PARAMETER | This code is returned when the input or output buffers are invalid. |
| STATUS_DEVICE_POWERED_OFF | This code is returned when the proximity radio control is off. |

## Remarks

The following actions are required when using this IOCTL:

* The driver must support CancelIo on this pended IOCTL.
* It is a power-managed request. The pended IOCTL will keep the driver in a D0 power state.
* The driver must return STATUS_SUCCESS only for the supported type.

## See also

[Near field communication (NFC) design guide](https://learn.microsoft.com/windows-hardware/drivers/nfc/)

[Smart card design guide](https://learn.microsoft.com/windows-hardware/drivers/nfc/design-guide-smart-card)