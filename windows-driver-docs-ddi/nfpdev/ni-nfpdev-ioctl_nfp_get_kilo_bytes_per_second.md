# IOCTL_NFP_GET_KILO_BYTES_PER_SECOND IOCTL

## Description

A client sends the **IOCTL_NFP_GET_KILO_BYTES_PER_SECOND** request to any generic handle, one that is non-published and non-subscribed, to the provider device. The request is sent in order to determine the approximate best-case transmission speed supported by the provider or its underlying RF technology. This is used to distinguish the difference in one order of magnitude in transmission rate to another.

**Note** A typical NFC implementation should provide a value of approximately 50.

## Parameters

### Major code

### Input buffer

None

### Input buffer length

### Output buffer

One **INT32** value that defines the approximate transmission speed supported by the provider or its underlying technology.

### Output buffer length

### Input/output buffer

### Input/output buffer length

### Status block

Irp->IoStatus.Status is set to STATUS_SUCCESS if the request is successful.

Otherwise, Status to the appropriate error condition as a NTSTATUS code.

For more information, see [NTSTATUS Values](https://learn.microsoft.com/windows-hardware/drivers/kernel/ntstatus-values).

## Remarks

Each provider implementation can specify an approximate transmission rate. A typical NFC implementation should provide a value of around 50 KB per second.

The following are required actions when using this IOCTL:

* The driver MUST support an approximate transmission rate no smaller than 16 KB per second.
* When this IOCTL is received, the driver MUST copy the approximate transmission speed into the output buffer and complete it with STATUS_SUCCESS.

## See also

[Near field communication (NFC) overall design guide](https://learn.microsoft.com/windows-hardware/drivers/nfc/)

[Near field proximity design guide (Tap and Do, NFP provider model, driver requirements)](https://learn.microsoft.com/windows-hardware/drivers/nfc/nfp-design-guide)