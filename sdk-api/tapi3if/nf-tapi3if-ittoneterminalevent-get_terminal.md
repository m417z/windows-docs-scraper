# ITToneTerminalEvent::get_Terminal

## Description

The
**get_Terminal** method returns an
[ITTerminal](https://learn.microsoft.com/windows/desktop/api/tapi3if/nn-tapi3if-itterminal) pointer for the tone terminal on which the event occurred.

## Parameters

### `ppTerminal` [out]

Pointer to the
[ITTerminal](https://learn.microsoft.com/windows/desktop/api/tapi3if/nn-tapi3if-itterminal) interface.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

TAPI calls the **AddRef** method on the
[ITTerminal](https://learn.microsoft.com/windows/desktop/api/tapi3if/nn-tapi3if-itterminal) interface returned by **ITToneTerminalEvent::get_Terminal**. The application must call **Release** on the
[ITTerminal](https://learn.microsoft.com/windows/desktop/api/tapi3if/nn-tapi3if-itterminal) interface to free resources associated with it.

## See also

[ITTerminal](https://learn.microsoft.com/windows/desktop/api/tapi3if/nn-tapi3if-itterminal)

[ITToneTerminalEvent](https://learn.microsoft.com/windows/desktop/api/tapi3if/nn-tapi3if-ittoneterminalevent)