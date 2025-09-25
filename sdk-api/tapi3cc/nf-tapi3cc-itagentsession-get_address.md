# ITAgentSession::get_Address

## Description

The
**get_Address** method gets a pointer to the
[ITAddress](https://learn.microsoft.com/windows/desktop/api/tapi3if/nn-tapi3if-itaddress) interface associated with this session.

## Parameters

### `ppAddress` [out]

Pointer for
[ITAddress](https://learn.microsoft.com/windows/desktop/api/tapi3if/nn-tapi3if-itaddress).

## Return value

This method can return one of these values.

| Value | Meaning |
| --- | --- |
| **S_OK** | Method succeeded. |
| **E_OUTOFMEMORY** | Insufficient memory exists to perform the operation. |
| **E_POINTER** | The *ppAddress* parameter is not a valid pointer. |

## Remarks

TAPI calls the **AddRef** method on the
[ITAddress](https://learn.microsoft.com/windows/desktop/api/tapi3if/nn-tapi3if-itaddress) interface returned by **ITAgentSession::get_Address**. The application must call **Release** on the
**ITAddress** interface to free resources associated with it.

## See also

[ITAddress](https://learn.microsoft.com/windows/desktop/api/tapi3if/nn-tapi3if-itaddress)

[ITAgentSession](https://learn.microsoft.com/windows/desktop/api/tapi3/nn-tapi3-itagentsession)