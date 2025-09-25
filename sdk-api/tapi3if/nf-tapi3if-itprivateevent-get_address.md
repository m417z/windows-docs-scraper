# ITPrivateEvent::get_Address

## Description

The
**get_Address** method gets the
[ITAddress](https://learn.microsoft.com/windows/desktop/api/tapi3if/nn-tapi3if-itaddress) interface pointer to the private object involved in the event.

## Parameters

### `ppAddress` [out]

Pointer to an
[ITAddress](https://learn.microsoft.com/windows/desktop/api/tapi3if/nn-tapi3if-itaddress) interface.

## Return value

This method can return one of these values.

| Value | Meaning |
| --- | --- |
| **S_OK** | Method succeeded. |
| **E_OUTOFMEMORY** | Insufficient memory exists to perform the operation. |
| **E_POINTER** | The *ppAddress* parameter is not a valid pointer. |

## See also

[Address Object](https://learn.microsoft.com/windows/desktop/Tapi/address-object)

[ITAddress](https://learn.microsoft.com/windows/desktop/api/tapi3if/nn-tapi3if-itaddress)

[ITPrivateEvent](https://learn.microsoft.com/windows/desktop/api/tapi3if/nn-tapi3if-itprivateevent)