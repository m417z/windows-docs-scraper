# IOCTL_SMARTCARD_SET_PROTOCOL IOCTL

## Description

The **IOCTL_SMARTCARD_SET_PROTOCOL** request sets the protocol that the driver will use to communicate with the smart card after the card is detected (inserted).

## Parameters

### Major code

### Input buffer

* **Irp->AssociatedIrp.SystemBuffer**
Contains a mask of protocols that are acceptable for the following transmissions. The mask can be a bitwise OR of the following values:

  * SCARD_PROTOCOL_RAW
  * SCARD_PROTOCOL_T0
  * SCARD_PROTOCOL_T1
  * SCARD_PROTOCOL_DEFAULT
  * SCARD_PROTOCOL_OPTIMAL

 The last two values are additional bit definitions that indicate that the driver must either explicitly perform protocol type selection (PTS) with the best possible communication parameters (SCARD_PROTOCOL_OPTIMAL) or use the implicit protocol of the card with standard parameters (SCARD_PROTOCOL_DEFAULT). If the card supports only one protocol with one set of communication parameters, the bits are ignored.

* **Parameters.DeviceIoControl.InputBufferLength**
Must be set to sizeof(ULONG). The driver decides which protocol out of the mask to use with the inserted card.

### Input buffer length

### Output buffer

* **Irp->AssociatedIrp.SystemBuffer**
The driver stores the selected protocol here (for example, SCARD_PROTOCOL_T1). Only one bit out of the mask can be set.

### Output buffer length

* **Parameters.DeviceIoControl.OutputBufferLength**
Must be sizeof(ULONG).

### Input/output buffer

### Input/output buffer length

### Status block

**Irp->IoStatus.Information** must be set to sizeof(ULONG).

**Irp->IoStatus.Status** is set to one of the following values.

| Value | Meaning |
| ----- | ------- |
| STATUS_SUCCESS | A protocol was successfully selected. |
| STATUS_NO_MEDIA | No smart card is detected in the reader. |
| STATUS_IO_TIMEOUT | The operation timed out. |
| STATUS_NOT_SUPPORTED | The smart card does not support any of the requested protocols. |
| STATUS_INVALID_DEVICE_REQUEST | The mask contains no known protocol. |

For more information, see [NTSTATUS Values](https://learn.microsoft.com/windows-hardware/drivers/kernel/ntstatus-values).

## See also

[Near field communication (NFC) design guide](https://learn.microsoft.com/windows-hardware/drivers/nfc/)

[Smart card design guide](https://learn.microsoft.com/windows-hardware/drivers/nfc/design-guide-smart-card)