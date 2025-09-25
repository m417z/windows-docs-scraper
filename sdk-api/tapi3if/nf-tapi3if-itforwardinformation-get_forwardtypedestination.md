# ITForwardInformation::get_ForwardTypeDestination

## Description

The
**get_ForwardTypeDestination** method gets the destination for a forwarding mode.

## Parameters

### `ForwardType` [in]

[Line forward mode](https://learn.microsoft.com/windows/desktop/Tapi/lineforwardmode--constants).

### `ppDestAddress` [out]

Pointer to **BSTR** representation of destination address.

## Return value

This method can return one of these values.

| Return code | Description |
| --- | --- |
| **S_OK** | Method succeeded. |
| **E_INVALIDARG** | The *ppDestAddress* parameter is not a valid pointer. |
| **E_OUTOFMEMORY** | Insufficient memory exists to perform the operation. |
| **E_POINTER** | The *ppDestAddress* parameter is not a valid pointer. |

## Remarks

The application must use
[SysFreeString](https://learn.microsoft.com/previous-versions/windows/desktop/api/oleauto/nf-oleauto-sysfreestring) to free the memory allocated for the *ppDestAddress* parameter.

## See also

[ITAddress::CreateForwardInfoObject](https://learn.microsoft.com/windows/desktop/api/tapi3if/nf-tapi3if-itaddress-createforwardinfoobject)

[ITAddress::Forward](https://learn.microsoft.com/windows/desktop/api/tapi3if/nf-tapi3if-itaddress-forward)

[ITAddress::get_CurrentForwardInfo](https://learn.microsoft.com/windows/desktop/api/tapi3if/nf-tapi3if-itaddress-get_currentforwardinfo)

[ITForwardInformation](https://learn.microsoft.com/windows/desktop/api/tapi3if/nn-tapi3if-itforwardinformation)

[Terminal Object](https://learn.microsoft.com/windows/desktop/Tapi/terminal-object)