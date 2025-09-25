# EVT_NFC_CX_SEQUENCE_HANDLER callback function

## Description

Called by the NFC CX to notify the client driver to handle the specific registered sequence.

## Parameters

### `Device` [in]

A handle to a framework device object.

### `Sequence` [in]

An [NFC_CX_SEQUENCE](https://learn.microsoft.com/windows-hardware/drivers/ddi/nfccx/ne-nfccx-_nfc_cx_sequence) enumeration.

### `CompletionRoutine` [in]

A pointer to a [CompletionRoutine](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfrequest/nc-wdfrequest-evt_wdf_request_completion_routine) callback function.

### `CompletionContext` [in, optional]

Driver-defined context information that the driver specified when it registered the *EvtNfcCxSequenceHandler* callback function.

## Remarks

On completion of handling the sequence, the client driver notifies the NFC CX through the sequence completion callback. Similar to [EvtNfcCxWriteNciPacket](https://learn.microsoft.com/windows-hardware/drivers/ddi/nfccx/nc-nfccx-evt_nfc_cx_write_nci_packet), the client must not make any blocking calls when handling this function call. Any I/O processing must be handled on a separate thread or work item. However, the client driver can invoke the completion routine with a status flag when handling this call.

## See also

[NFC class extension design guide](https://learn.microsoft.com/windows-hardware/drivers/nfc/nfc-class-extension-)

[Near field communication (NFC) design guide](https://learn.microsoft.com/windows-hardware/drivers/nfc/)