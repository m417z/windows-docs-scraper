# ITAddress::get_Calls

## Description

The
**get_Calls** method creates a collection of calls currently active on the address. This method is provided for Automation client applications, such as those written in Visual Basic. C and C++ applications must use the
[EnumerateCalls](https://learn.microsoft.com/windows/desktop/api/tapi3if/nf-tapi3if-itaddress-enumeratecalls) method.

## Parameters

### `pVariant` [out]

Pointer to a **VARIANT** containing an
[ITCollection](https://learn.microsoft.com/windows/desktop/api/tapi3if/nn-tapi3if-itcollection) of
[ITCallInfo](https://learn.microsoft.com/windows/desktop/api/tapi3if/nn-tapi3if-itcallinfo) interface pointers (call objects).

## Return value

This method can return one of these values.

| Value | Meaning |
| --- | --- |
| **S_OK** | Method succeeded. |
| **E_POINTER** | The *pVariant* parameter is not a valid pointer. |
| **E_OUTOFMEMORY** | Insufficient memory exists to perform the operation. |

## Remarks

TAPI calls the **AddRef** method on the
[ITCallInfo](https://learn.microsoft.com/windows/desktop/api/tapi3if/nn-tapi3if-itcallinfo) interface returned by ITAddress::get_Calls. The application must call **Release** on the
**ITCallInfo** interface to free resources associated with it.

## See also

[Address Object](https://learn.microsoft.com/windows/desktop/Tapi/address-object)

[EnumerateCalls](https://learn.microsoft.com/windows/desktop/api/tapi3if/nf-tapi3if-itaddress-enumeratecalls)

[ITAddress](https://learn.microsoft.com/windows/desktop/api/tapi3if/nn-tapi3if-itaddress)

[ITCallInfo](https://learn.microsoft.com/windows/desktop/api/tapi3if/nn-tapi3if-itcallinfo)

[ITCollection](https://learn.microsoft.com/windows/desktop/api/tapi3if/nn-tapi3if-itcollection)