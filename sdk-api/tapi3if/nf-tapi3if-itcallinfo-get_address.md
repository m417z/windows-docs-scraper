# ITCallInfo::get_Address

## Description

The
**get_Address** method gets a pointer to the
[ITAddress](https://learn.microsoft.com/windows/desktop/api/tapi3if/nn-tapi3if-itaddress) interface of the
[Address object](https://learn.microsoft.com/windows/desktop/Tapi/address-object).

## Parameters

### `ppAddress` [out]

Pointer to
[ITAddress](https://learn.microsoft.com/windows/desktop/api/tapi3if/nn-tapi3if-itaddress) interface.

## Return value

This method can return one of these values.

| Value | Meaning |
| --- | --- |
| **S_OK** | Method succeeded. |
| **E_POINTER** | The *ppAddress* parameter is not a valid pointer. |
| **E_OUTOFMEMORY** | Insufficient memory exists to perform the operation. |

## Remarks

TAPI calls the **AddRef** method on the
[ITAddress](https://learn.microsoft.com/windows/desktop/api/tapi3if/nn-tapi3if-itaddress) interface returned by **ITCallInfo::get_Address**. The application must call **Release** on the
**ITAddress** interface to free resources associated with it.

## See also

[Address object](https://learn.microsoft.com/windows/desktop/Tapi/address-object)

[Call Object](https://learn.microsoft.com/windows/desktop/Tapi/call-object)

[ITAddress](https://learn.microsoft.com/windows/desktop/api/tapi3if/nn-tapi3if-itaddress)

[ITCallInfo](https://learn.microsoft.com/windows/desktop/api/tapi3if/nn-tapi3if-itcallinfo)