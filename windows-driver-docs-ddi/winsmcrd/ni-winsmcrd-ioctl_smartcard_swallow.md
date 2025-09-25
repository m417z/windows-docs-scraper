# IOCTL_SMARTCARD_SWALLOW IOCTL

## Description

The IOCTL_SMARTCARD_SWALLOW request causes the smart card reader to swallow the card.

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

**Irp->IoStatus.Status** is set to **STATUS_SUCCESS** if the request is successful. Possible error codes are:

| Value | Meaning |
| --- | --- |
| STATUS_SUCCESS | The smart card was swallowed. |
| STATUS_NO_MEDIA | No smart card is in the reader. |
| STATUS_IO_TIMEOUT | The operation timed out. |
| STATUS_NOT_SUPPORTED | The reader does not support swallowing. |

## Remarks

The **Information** member must be set to zero.

The **Status** member is set to one of the values in the status block table.