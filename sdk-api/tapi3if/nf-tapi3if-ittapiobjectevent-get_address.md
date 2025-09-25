# ITTAPIObjectEvent::get_Address

## Description

The
**get_Address** method gets a pointer to the Address object on which the event occurred.

## Parameters

### `ppAddress` [out]

Pointer to an
[ITAddress](https://learn.microsoft.com/windows/desktop/api/tapi3if/nn-tapi3if-itaddress) interface pointer.

## Return value

This method can return one of these values.

| Value | Meaning |
| --- | --- |
| **S_OK** | Method succeeded. |
| **E_POINTER** | The *ppAddress* parameter is not a valid pointer. |
| **E_OUTOFMEMORY** | Insufficient memory exists to perform the operation. |

## Remarks

TAPI calls the **AddRef** method on the
[ITAddress](https://learn.microsoft.com/windows/desktop/api/tapi3if/nn-tapi3if-itaddress) interface returned by **ITTAPIObjectEvent::get_Address**. The application must call **Release** on the
**ITAddress** interface to free resources associated with it.

## See also

[ITAddress](https://learn.microsoft.com/windows/desktop/api/tapi3if/nn-tapi3if-itaddress)

[ITTAPIObjectEvent](https://learn.microsoft.com/windows/desktop/api/tapi3if/nn-tapi3if-ittapiobjectevent)

[TAPI Object](https://learn.microsoft.com/windows/desktop/Tapi/tapi-object)