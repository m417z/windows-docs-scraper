# NfcCxNciReadNotification function

## Description

Called by the client driver when a read packet is available. The WDFMEMORY can be deallocated by the client driver after completion of the call. While NFC CXs implementation will quickly process this call, it is expected that the client driver doesn't make this call from the context of an ISR. It is recommend that the client driver issues this call from the ISR work-item.

## Parameters

### `Device`

A handle to a framework device object.

### `Memory`

A handle to a framework memory object.

## Return value

If the operation succeeds, the function returns STATUS_SUCCESS.

## See also

[NFC class extension design guide](https://learn.microsoft.com/windows-hardware/drivers/nfc/nfc-class-extension-)

[Near field communication (NFC) design guide](https://learn.microsoft.com/windows-hardware/drivers/nfc/)