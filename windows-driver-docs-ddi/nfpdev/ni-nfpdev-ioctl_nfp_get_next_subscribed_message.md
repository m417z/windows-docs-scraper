# IOCTL_NFP_GET_NEXT_SUBSCRIBED_MESSAGE IOCTL

## Description

The client sends the **IOCTL_NFP_GET_NEXT_SUBSCRIBED_MESSAGE** request to the subscription handle repeatedly in order to receive subscribed messages as they arrive. Typically, this IOCTL will be pended in the subscription handle until a message matching the subscribed type actually arrives.

## Parameters

### Major code

### Input buffer

None

### Input buffer length

### Output buffer

A valid buffer is required for returning the message data when it arrives. The first **DWORD** of this buffer is reserved for a hint to the client for the next size of the buffer to be returned. This buffer will typically initially be 255 bytes, but the driver can request that the client send a bigger buffer by providing just the hint and completing the IOCTL with STATUS_BUFFER_OVERFLOW.

### Output buffer length

### Input/output buffer

### Input/output buffer length

### Status block

Irp->IoStatus.Status is set to STATUS_SUCCESS if the request is successful.

Otherwise, Status to the appropriate error condition as a NTSTATUS code.

For more information, see [NTSTATUS Values](https://learn.microsoft.com/windows-hardware/drivers/kernel/ntstatus-values).

## Remarks

* The client should send another IOCTL each time the pended one is completed. The driver MUST use appropriate locks to guarantee that the number of successful completions of this IOCTL equates to the number of successful message receptions for the subscription type.
* The following are required actions when using this IOCTL:
  + If this IOCTL is received on a handle that wasn’t previously opened in the “Subs\” device namespace, the driver MUST complete it with STATUS_INVALID_DEVICE_STATE.
  + The driver must maintain a “Received” queue of received messages that match the subscription type within the subscription file handle.
  + When this IOCTL is received in the driver:

    - If the “Received” queue is empty, then the driver MUST pend the IOCTL for later completion.
    - If the “Received” queue is non-empty, then the driver MUST dequeue one message buffer, copy the message buffer to the IOCTL’s output buffer, and complete the IOCTL with STATUS_SUCCESS immediately.
  + If a message matching the type is received and no IOCTL is currently pended, the driver MUST add the message buffer to the “Received” queue.
  + If a message matching the type is received and there is a pended IOCTL available (the “Received” queue is empty), the driver MUST copy the message buffer to the IOCTL’s output buffer and complete the pended IRP with STATUS_SUCCESS. The “Received” queue MUST continue to be empty following completion of the pended IRP.
  + If the driver completes this IOCTL with STATUS_SUCCESS, the first DWORD [4 bytes] of the output buffer MUST contain a hint for the size of the next client buffer and the IOCTL’s Information field MUST contain the size of this message plus **sizeof**(DWORD) (4 bytes).
  + If the IOCTL contains an input buffer the driver MUST complete the IOCTL with STATUS_INVALID_PARAMETER.
  + If a received message has a zero-length payload the driver SHOULD ignore the message. This is a performance optimization because Windows WILL drop messages with zero-length payloads.
  + If a received message is too large to be copied into this IOCTL’s buffer, the driver MUST copy the required buffer size into the first 4 bytes of the output buffer, set the IOCTL’s “Information” field to sizeof(DWORD) (“4”), and complete the IOCTL with STATUS_BUFFER_OVERFLOW. The message buffer must be left in the “Received” queue.
  + If this IOCTL is received while another is currently pended in the subscription handle, the second (or later) one MUST be completed with STATUS_INVALID_DEVICE_STATE.
  + The driver MUST support CancelIo of the pended IOCTL.

## See also

[Near field communication (NFC) overall design guide](https://learn.microsoft.com/windows-hardware/drivers/nfc/)

[Near field proximity design guide (Tap and Do, NFP provider model, driver requirements)](https://learn.microsoft.com/windows-hardware/drivers/nfc/nfp-design-guide)