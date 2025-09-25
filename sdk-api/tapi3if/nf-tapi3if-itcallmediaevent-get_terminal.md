# ITCallMediaEvent::get_Terminal

## Description

The
**get_Terminal** method gets the terminal associated with the event.

## Parameters

### `ppTerminal` [out]

Pointer to
[ITTerminal](https://learn.microsoft.com/windows/desktop/api/tapi3if/nn-tapi3if-itterminal) interface.

## Return value

This method can return one of these values.

| Value | Meaning |
| --- | --- |
| **S_OK** | Method succeeded. |
| **E_OUTOFMEMORY** | Insufficient memory exists to perform the operation. |
| **E_POINTER** | The *ppTerminal* parameter is not a valid pointer. |

## Remarks

TAPI calls the **AddRef** method on the
[ITTerminal](https://learn.microsoft.com/windows/desktop/api/tapi3if/nn-tapi3if-itterminal) interface returned by **ITCallMediaEvent::get_Terminal**. The application must call **Release** on
**ITTerminal** to free resources associated with it.

## See also

[Call Object](https://learn.microsoft.com/windows/desktop/Tapi/call-object)

[ITCallMediaEvent](https://learn.microsoft.com/windows/desktop/api/tapi3if/nn-tapi3if-itcallmediaevent)

[ITTerminal](https://learn.microsoft.com/windows/desktop/api/tapi3if/nn-tapi3if-itterminal)