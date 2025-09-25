# IOCTL_NFP_SET_PAYLOAD IOCTL

## Description

A client application sends message data and confirms publication with the **IOCTL_NFP_SET_PAYLOAD** request.

## Parameters

### Major code

### Input buffer

The input buffer contains the message data to transmit.

### Input buffer length

### Output buffer

None.

### Output buffer length

### Input/output buffer

### Input/output buffer length

### Status block

Irp->IoStatus.Status is set to STATUS_SUCCESS if the request is successful.

Otherwise, Status to the appropriate error condition as a NTSTATUS code.

For more information, see [NTSTATUS Values](https://learn.microsoft.com/windows-hardware/drivers/kernel/ntstatus-values).

## Remarks

The following actions are required when using this IOCTL:

* If this IOCTL is sent on a handle that hasn’t previously been opened on a “Pubs\...” filename, the driver MUST complete it with STATUS_INVALID_DEVICE_STATE.
* The message data is write-once. If this IOCTL succeeds once, any subsequent IOCTL_NFP_SET_PAYLOAD received on the same handle MUST be completed with STATUS_INVALID_DEVICE_STATE.
* If the IOCTL contains an output buffer, the driver MUST complete the IOCTL with STATUS_INVALID_PARAMETER.
* If the input buffer is larger than the driver’s maximum message size, the driver MUST complete the IOCTL with STATUS_INVALID_BUFFER_SIZE.
* If any device becomes proximate after this IOCTL succeeds, and before the handle is closed, then the message data (along with its type) MUST be transmitted only once to the proximate device.
* If the same (or different) device becomes proximate again before the handle is closed, the message MUST be transmitted once again.
* If a device is currently proximate when this IOCTL is successfully completed, then the message data (along with its type) MUST be transmitted (only once) to the proximate device. This applies even if the handle is immediately closed.

## See also

[Near field communication (NFC) overall design guide](https://learn.microsoft.com/windows-hardware/drivers/nfc/)

[Near field proximity design guide (Tap and Do, NFP provider model, driver requirements)](https://learn.microsoft.com/windows-hardware/drivers/nfc/nfp-design-guide)