# IWRdsProtocolConnection::GetInputHandles

## Description

Obtains the handles to input/output devices for the protocol.

## Parameters

### `pKeyboardHandle` [out]

A pointer to a handle that receives the handle of the keyboard device. This is a handle to an [I8042prt keyboard driver](https://learn.microsoft.com/windows-hardware/drivers/ddi/content/).

### `pMouseHandle` [out]

A pointer to a handle that receives the handle of the mouse device. This is a handle to a [Mouclass driver](https://learn.microsoft.com/previous-versions/ff542367(v=vs.85)).

### `pBeepHandle` [out]

A pointer to a handle that receives the handle of the beep or sound device. This handle is not used and must be set to **NULL**.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[IWRdsProtocolConnection](https://learn.microsoft.com/windows/desktop/api/wtsprotocol/nn-wtsprotocol-iwrdsprotocolconnection)