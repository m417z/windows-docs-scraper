# ITAddress::get_CurrentForwardInfo

## Description

The
**get_CurrentForwardInfo** method gets a pointer to the current forwarding information object.

## Parameters

### `ppForwardInfo` [out]

Pointer to
[ITForwardInformation](https://learn.microsoft.com/windows/desktop/api/tapi3if/nn-tapi3if-itforwardinformation) interface.

## Return value

This method can return one of these values.

| Value | Meaning |
| --- | --- |
| **S_OK** | Method succeeded. |
| **E_NOTIMPL** | Method not implemented. |
| **E_OUTOFMEMORY** | Insufficient memory exists to perform the operation. |
| **LINEERR_INVALPOINTER** | The *ppForwardInfo* parameter is not a valid pointer. |

## Remarks

TAPI calls the **AddRef** method on the
[ITForwardInformation](https://learn.microsoft.com/windows/desktop/api/tapi3if/nn-tapi3if-itforwardinformation) interface returned by **ITAddress::get_ForwardInfo**. The application must call **Release** on the
**ITForwardInformation** interface to free resources associated with it.

## See also

[Address Object](https://learn.microsoft.com/windows/desktop/Tapi/address-object)

[ITAddress](https://learn.microsoft.com/windows/desktop/api/tapi3if/nn-tapi3if-itaddress)

[ITAddress::CreateForwardInfoObject](https://learn.microsoft.com/windows/desktop/api/tapi3if/nf-tapi3if-itaddress-createforwardinfoobject)

[ITAddress::Forward](https://learn.microsoft.com/windows/desktop/api/tapi3if/nf-tapi3if-itaddress-forward)

[ITForwardInformation](https://learn.microsoft.com/windows/desktop/api/tapi3if/nn-tapi3if-itforwardinformation)