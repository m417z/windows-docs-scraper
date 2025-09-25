# ITForwardInformation::get_ForwardTypeCaller

## Description

The
**get_ForwardTypeCaller** method gets the type of caller for a given forwarding mode.

## Parameters

### `Forwardtype` [in]

[Line forward mode](https://learn.microsoft.com/windows/desktop/Tapi/lineforwardmode--constants).

### `ppCallerAddress` [out]

Pointer to **BSTR** representation of caller address.

## Return value

This method can return one of these values.

| Return code | Description |
| --- | --- |
| **S_OK** | Method succeeded. |
| **E_POINTER** | The *ppCallerAddress* parameter is not a valid pointer. |
| **E_INVALIDARG** | The *Forwardtype* parameter is not valid. |
| **E_OUTOFMEMORY** | Insufficient memory exists to perform the operation. |

## Remarks

The application must use
[SysFreeString](https://learn.microsoft.com/previous-versions/windows/desktop/api/oleauto/nf-oleauto-sysfreestring) to free the memory allocated for the *ppCallerAddress* parameter.

## See also

[ITAddress::CreateForwardInfoObject](https://learn.microsoft.com/windows/desktop/api/tapi3if/nf-tapi3if-itaddress-createforwardinfoobject)

[ITAddress::Forward](https://learn.microsoft.com/windows/desktop/api/tapi3if/nf-tapi3if-itaddress-forward)

[ITAddress::get_CurrentForwardInfo](https://learn.microsoft.com/windows/desktop/api/tapi3if/nf-tapi3if-itaddress-get_currentforwardinfo)

[ITForwardInformation](https://learn.microsoft.com/windows/desktop/api/tapi3if/nn-tapi3if-itforwardinformation)

[Terminal Object](https://learn.microsoft.com/windows/desktop/Tapi/terminal-object)