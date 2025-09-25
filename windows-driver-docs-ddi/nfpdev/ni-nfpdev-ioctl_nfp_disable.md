# IOCTL_NFP_DISABLE IOCTL

## Description

A client sends the **IOCTL_NFP_DISABLE** request to temporarily disable subscriptions, publications, and presence events. This is useful when a client wants to disable the proximity functionality but keep the resources allocated to quickly re-enable them when needed again.

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

* When this IOCTL is received the driver MUST mark the file handle as “Disabled”.
* If a subscription handle is changed to “Disabled, the provider MUST remove all messages from that file handle’s “Received” queue.
* If a subscription handle is “Disabled”:

  + The driver MUST keep that handle’s “Received” queue at zero length by purging (dropping) existing messages in the queue and by dropping new messages from the queue as soon as they are received.
  + The driver MUST complete all pended [IOCTL_NFP_GET_NEXT_SUBSCRIBED_MESSAGE](https://learn.microsoft.com/windows-hardware/drivers/ddi/nfpdev/ni-nfpdev-ioctl_nfp_get_next_subscribed_message) requests on that handle with STATUS_CANCELLED.
* If a publication handle is “Disabled”, the provider MUST NOT transmit the publication’s message and it MUST complete all pended [IOCTL_NFP_GET_NEXT_TRANSMITTED_MESSAGE](https://learn.microsoft.com/windows-hardware/drivers/ddi/nfpdev/ni-nfpdev-ioctl_nfp_get_next_transmitted_message) requests on that handle with STATUS_CANCELLED

## See also

[IOCTL_NFP_ENABLE](https://learn.microsoft.com/windows-hardware/drivers/ddi/nfpdev/ni-nfpdev-ioctl_nfp_enable)

[Near field communication (NFC) overall design guide](https://learn.microsoft.com/windows-hardware/drivers/nfc/)

[Near field proximity design guide (Tap and Do, NFP provider model, driver requirements)](https://learn.microsoft.com/windows-hardware/drivers/nfc/nfp-design-guide)