# IOCTL_SMARTCARD_TRANSMIT IOCTL

## Description

The **IOCTL_SMARTCARD_TRANSMIT** request transmits data to, and receives data from, the inserted smart card.

## Parameters

### Major code

### Input buffer

* **Irp->AssociatedIrp.SystemBuffer**
A pointer to an [**SCARD_IO_REQUEST**](https://learn.microsoft.com/windows-hardware/drivers/ddi/winsmcrd/ns-winsmcrd-_scard_io_request) structure followed by the data to transmit to the inserted smart card.

### Input buffer length

* **Parameters.DeviceIoControl.InputBufferLength**
Contains the size of the structure plus the length of trailing data bytes (if any). The **dwProtocol** member must be set to the protocol that was previously selected, and the **cbPciLength** member must be set to the size of the **SCARD_IO_REQUEST** structure itself (usually eight bytes). The structure is used for future protocols. Data that will be transmitted to the card must immediately follow this structure.

### Output buffer

Bytes buffer contains the result of the transmission. The buffer points to the SCARD_IO_REQUEST structure immediately followed by the data received.

* **Irp->AssociatedIrp.SystemBuffer**
Receives the result of the transmission. This buffer must also begin with an [**SCARD_IO_REQUEST**](https://learn.microsoft.com/windows-hardware/drivers/ddi/winsmcrd/ns-winsmcrd-_scard_io_request) structure. Any data that was received from the card must be stored immediately after the structure.

### Output buffer length

* **Parameters.DeviceIoControl.OutputBufferLength**
Contains the length of the output buffer.

### Input/output buffer

### Input/output buffer length

### Status block

**Irp->IoStatus.Status** is set to one of the following values.

| Value | Meaning |
| ----- | ------- |
| STATUS_SUCCESS | The transmission was successful. |
| STATUS_NO_MEDIA | No smart card is detected in the reader. |
| STATUS_IO_TIMEOUT | The operation timed out. |
| STATUS_INVALID_DEVICE_STATE | The protocol in the header file does not match the smart card protocol that was previously selected. |
| STATUS_BUFFER_TOO_SMALL | The output buffer is too small for the return data. |
| STATUS_DEVICE_POWERED_OFF | The proximity radio control is off. |

## Remarks

**IOCTL_SMARTCARD_TRANSMIT** transmits data from the client to the detected smart card in ISO7816-4 compliant APDU. These APDUs are interpreted with respect to the PC/SC specification (Section 4.3.7 has more detailed requirements on support for different NFC contactless tag formats). Because the NFP feature shares the same driver with the smart card, the card should be connected right after the discovery, no explicit connect for the ‘Transmit’ is needed.

Because the input buffer and the output buffer are pointing to the same memory area, the driver must avoid overwriting the input data. Use the smart card driver library to make sure that the input data is not overwritten.

## See also

[Near field communication (NFC) design guide](https://learn.microsoft.com/windows-hardware/drivers/nfc/)

[Smart card design guide](https://learn.microsoft.com/windows-hardware/drivers/nfc/design-guide-smart-card)