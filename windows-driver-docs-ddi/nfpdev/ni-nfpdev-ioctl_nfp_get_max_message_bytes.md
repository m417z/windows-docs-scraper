# IOCTL_NFP_GET_MAX_MESSAGE_BYTES IOCTL

## Description

A client sends the **IOCTL_NFP_GET_MAX_MESSAGE_BYTES** request to any generic handle, one that is non-published and non-subscribed, to the provider device to determine the maximum message size supported.

## Parameters

### Major code

### Input buffer

None

### Input buffer length

### Output buffer

One **INT32** value that defines the maximum message size supported by the provide.

### Output buffer length

### Input/output buffer

### Input/output buffer length

### Status block

Irp->IoStatus.Status is set to STATUS_SUCCESS if the request is successful.

Otherwise, Status to the appropriate error condition as a NTSTATUS code.

For more information, see [NTSTATUS Values](https://learn.microsoft.com/windows-hardware/drivers/kernel/ntstatus-values).

## Remarks

* Each provider implementation can specify a maximum message size for publications and subscriptions. Windows requires that this maximum provider-supported message size be no less than 10 KB.
* The following are required actions when using this ioctl:
  + The driver MUST support a maximum message size no smaller than 10 KB.
  + When this IOCTL is received, the driver MUST copy the maximum message size into the output buffer and complete it with STATUS_SUCCESS.

## See also

[Near field communication (NFC) overall design guide](https://learn.microsoft.com/windows-hardware/drivers/nfc/)

[Near field proximity design guide (Tap and Do, NFP provider model, driver requirements)](https://learn.microsoft.com/windows-hardware/drivers/nfc/nfp-design-guide)