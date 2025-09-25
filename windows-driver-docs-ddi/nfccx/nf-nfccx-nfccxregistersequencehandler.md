# NfcCxRegisterSequenceHandler function

## Description

Called by the client driver during initialization to register for handling specific sequences.

## Parameters

### `Device`

A handle to a framework device object.

### `Sequence`

An [NFC_CX_SEQUENCE](https://learn.microsoft.com/windows-hardware/drivers/ddi/nfccx/ne-nfccx-_nfc_cx_sequence)-typed enumerator.

### `EvtNfcCxSequenceHandler`

A pointer to an [EvtNfcCxSequenceHandler](https://learn.microsoft.com/windows-hardware/drivers/ddi/nfccx/nc-nfccx-evt_nfc_cx_sequence_handler) callback function.

## Return value

If the operation succeeds, the function returns STATUS_SUCCESS.

## See also

[NFC class extension design guide](https://learn.microsoft.com/windows-hardware/drivers/nfc/nfc-class-extension-)

[Near field communication (NFC) design guide](https://learn.microsoft.com/windows-hardware/drivers/nfc/)