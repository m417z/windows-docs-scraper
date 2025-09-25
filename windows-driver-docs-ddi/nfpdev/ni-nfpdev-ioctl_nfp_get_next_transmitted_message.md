# IOCTL_NFP_GET_NEXT_TRANSMITTED_MESSAGE IOCTL

## Description

A client interested in receiving notifications that a message has been transmitted will send the **IOCTL_NFP_GET_NEXT_TRANSMITTED_MESSAGE** request to the proximity driver.

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

* A client application will send this IOCTL in a control loop to the publication handle. Two separate transmissions of the same message would result in triggering two events.
* The client should send another IOCTL each time the pended one is completed. The driver MUST use appropriate locks to guarantee that the number of successful completions of this IOCTL equates to the number of times the publication has been transmitted.
* The following actions are required when using this IOCTL:
  + If this IOCTL is received on a handle that hasn’t previously succeeded an [IOCTL_NFP_SET_PAYLOAD](https://learn.microsoft.com/windows-hardware/drivers/ddi/nfpdev/ni-nfpdev-ioctl_nfp_set_payload), the driver MUST complete it with STATUS_INVALID_DEVICE_STATE.
  + The driver must maintain the equivalent of a “CompleteEventImmediately” counter (**ULONG** or larger) in the publication file handle.
  + When this IOCTL is received in the driver:

    - If the counter is zero, then the driver MUST pend the IOCTL for later completion.
    - If the counter is greater than zero, then the driver MUST decrement the counter by one and complete the IOCTL with STATUS_SUCCESS immediately.
  + If the publication is transmitted and no IOCTL is currently pended, the driver MUST increment the “CompleteEventImmediately” counter by one.
  + If the publication is transmitted while there is a pended IOCTL available, the driver MUST complete the pended IRP with STATUS_SUCCESS and NOT increment the “CompleteEventImmediately” counter.
  + If the IOCTL contains an input or output buffer the driver MUST complete the IOCTL with STATUS_INVALID_PARAMETER.
  + If this IOCTL is received while another is currently pended in the publication handle, the second one (or later) MUST be completed with STATUS_INVALID_DEVICE_STATE.
  + The driver MUST support CancelIo of the pended IOCTL.

## See also

[Near field communication (NFC) overall design guide](https://learn.microsoft.com/windows-hardware/drivers/nfc/)

[Near field proximity design guide (Tap and Do, NFP provider model, driver requirements)](https://learn.microsoft.com/windows-hardware/drivers/nfc/nfp-design-guide)