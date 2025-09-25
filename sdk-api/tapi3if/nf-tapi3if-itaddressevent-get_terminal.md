# ITAddressEvent::get_Terminal

## Description

The
**get_Terminal** method gets a pointer to the
[ITTerminal](https://learn.microsoft.com/windows/desktop/api/tapi3if/nn-tapi3if-itterminal) interface associated with the event.

## Parameters

### `ppTerminal` [out]

Pointer to
[ITTerminal](https://learn.microsoft.com/windows/desktop/api/tapi3if/nn-tapi3if-itterminal) interface, or **NULL** if the event does not refer to a terminal.

## Return value

This method can return one of these values.

| Value | Meaning |
| --- | --- |
| **S_OK** | Method succeeded. |
| **E_INVALIDARG** | The *ppTerminal* parameter is not a valid pointer. |
| **E_OUTOFMEMORY** | Insufficient memory exists to perform the operation. |
| **E_POINTER** | The *ppTerminal* parameter is not a valid pointer. |

## Remarks

TAPI calls the **AddRef** method on the
[ITTerminal](https://learn.microsoft.com/windows/desktop/api/tapi3if/nn-tapi3if-itterminal) interface returned by **ITAddressEvent::get_Terminal**. The application must call **Release** on the
**ITTerminal** interface to free resources associated with it.

## See also

[Address Object](https://learn.microsoft.com/windows/desktop/Tapi/address-object)

[ITAddressEvent](https://learn.microsoft.com/windows/desktop/api/tapi3if/nn-tapi3if-itaddressevent)

[ITTerminal](https://learn.microsoft.com/windows/desktop/api/tapi3if/nn-tapi3if-itterminal)