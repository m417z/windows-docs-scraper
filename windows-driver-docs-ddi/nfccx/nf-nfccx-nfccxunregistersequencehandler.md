# NfcCxUnregisterSequenceHandler function

## Description

Called by the client driver during device shutdown to unregister for the previously registered sequence handler callback.

## Parameters

### `Device`

A handle to a framework device object.

### `Sequence`

An [NFC_CX_SEQUENCE](https://learn.microsoft.com/windows-hardware/drivers/ddi/nfccx/ne-nfccx-_nfc_cx_sequence)-typed enumerator.

## Return value

If the operation succeeds, the function returns STATUS_SUCCESS.

## See also

[NFC class extension design guide](https://learn.microsoft.com/windows-hardware/drivers/nfc/nfc-class-extension-)

[Near field communication (NFC) design guide](https://learn.microsoft.com/windows-hardware/drivers/nfc/)