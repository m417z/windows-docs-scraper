# EVT_NFC_CX_WRITE_NCI_PACKET callback function

## Description

Called by the NFC CX to send a write packet to the client driver. The request code must match IOCTL_NFCCX_WRITE_PACKET.

## Parameters

### `Device` [in]

A handle to a framework device object.

### `Request` [in]

A handle to a framework request object.

## Remarks

The client driver should not make any blocking calls when handling this function call. Any I/O processing must be handled on a separate thread or work-item (that is, the client driver should immediately return STATUS_PENDING and on completion invoke the completion handler).

## See also

[NFC class extension design guide](https://learn.microsoft.com/windows-hardware/drivers/nfc/nfc-class-extension-)

[Near field communication (NFC) design guide](https://learn.microsoft.com/windows-hardware/drivers/nfc/)