# IOCTL_NFP_ENABLE IOCTL

## Description

The client sends the **IOCTL_NFP_ENABLE** request to re-enable previously disabled subscriptions, publications, and presence events.

## Parameters

### Major code

### Input buffer

None

### Input buffer length

### Output buffer

None

### Output buffer length

### Input/output buffer

### Input/output buffer length

### Status block

Irp->IoStatus.Status is set to STATUS_SUCCESS if the request is successful.

Otherwise, Status to the appropriate error condition as a NTSTATUS code.

For more information, see [NTSTATUS Values](https://learn.microsoft.com/windows-hardware/drivers/kernel/ntstatus-values).

## Remarks

The following are required actions when using this IOCTL:

* When this IOCTL is received the driver MUST mark the file handle as “Enabled”.
* If the file handle is already marked “Enabled” the driver MUST complete the IOCTL with STATUS_INVALID_DEVICE_STATE.
* If a device is currently proximate when this IOCTL is successfully completed, then the message data (along with its type) MUST be transmitted (only once) to the proximate device.

## See also

[IOCTL_NFP_DISABLE](https://learn.microsoft.com/windows-hardware/drivers/ddi/nfpdev/ni-nfpdev-ioctl_nfp_disable)

[Near field communication (NFC) overall design guide](https://learn.microsoft.com/windows-hardware/drivers/nfc/)

[Near field proximity design guide (Tap and Do, NFP provider model, driver requirements)](https://learn.microsoft.com/windows-hardware/drivers/nfc/nfp-design-guide)