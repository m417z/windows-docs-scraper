# IOCTL_NFCSE_GET_NEXT_EVENT IOCTL

## Description

The **IOCTL_NFCSE_GET_NEXT_EVENT**
control code returns the next event available in the buffer, or if there are no more buffered events remains pending until a secure element event is available. The event details must then be returned to the caller.

## Parameters

### Major code

### Input buffer

None

### Input buffer length

None

### Output buffer

 A **DWORD** indicating the size of the [SECURE_ELEMENT_EVENT_INFO](https://learn.microsoft.com/windows-hardware/drivers/ddi/nfcsedev/ns-nfcsedev-_secure_element_event_info) structure plus its payload, immediately followed by the **SECURE_ELEMENT_EVENT_INFO** structure itself.

### Output buffer length

### Input/output buffer

### Input/output buffer length

### Status block

**Irp->IoStatus.Status** is set to **STATUS_SUCCESS** if the request is successful. Possible error codes are:

| Return Code | Description |
| --- | --- |
| **STATUS_INVALID_DEVICE_STATE** | This code is returned when this IOCTL is called on a device handle that has a filename other than SEEvents, or when there is already another pending request that is not completed yet. |
| **STATUS_INVALID_PARAMETER** | This code is returned when the output buffer is non-zero, or when the GUID of the secure element does not match any of the enumerated IDs. |

## Remarks

The following are requirements that the driver must adhere to.

* This IOCTL must be called on a handle that has an **SEEvents** relative file name; otherwise, the driver returns STATUS_INVALID_DEVICE_STATE
* This driver must support CancelIO for this pending IOCTL.
* This driver must maintain a received queue of the received secure element events that match the subscription type.
* The following conditions must be met when this IOCTL is received in the driver:

  + If the received queue is empty, then the driver must pend the IOCTL for later completion.
  + If the received queue is non-empty, then the driver must de-queue one event, copy the message buffer to the IOCTL’s output buffer, and complete the IOCTL with **STATUS_SUCCESS** immediately.
* If the driver completes this IOCTL with STATUS_SUCCESS, the first DWORD [4 bytes] of the output buffer must contain the size of the SECURE_ELEMENT_EVENT_INFO structure plus its payload.
* If a received secure element event info is too large to be copied into this IOCTL’s buffer, the driver must copy the required buffer size into the first 4 bytes of the output buffer, set the IOCTL’s information field to sizeof(DWORD), and complete the IOCTL with **STATUS_BUFFER_OVERFLOW**. The event must then be left in the received queue.