# ITForwardInformation::GetForwardType

## Description

The
**GetForwardType** method gets the forwarding mode.

## Parameters

### `ForwardType` [in]

[Line forward mode](https://learn.microsoft.com/windows/desktop/Tapi/lineforwardmode--constants).

### `ppDestinationAddress` [out]

Pointer to **BSTR** representation of destination address.

### `ppCallerAddress` [out]

Pointer to **BSTR** representation of the call originator's address.

## Return value

This method can return one of these values.

| Return code | Description |
| --- | --- |
| **S_OK** | Method succeeded. |
| **E_INVALIDARG** | The *ppDestAddress* or *ppCallerAddress* parameter is not a valid pointer. |
| **E_OUTOFMEMORY** | Insufficient memory exists to perform the operation. |

## Remarks

The application must use
[SysFreeString](https://learn.microsoft.com/previous-versions/windows/desktop/api/oleauto/nf-oleauto-sysfreestring) to free the memory allocated for the *ppDestinationAddress* and *ppCallerAddress* parameters.

## See also

[ITAddress::CreateForwardInfoObject](https://learn.microsoft.com/windows/desktop/api/tapi3if/nf-tapi3if-itaddress-createforwardinfoobject)

[ITAddress::Forward](https://learn.microsoft.com/windows/desktop/api/tapi3if/nf-tapi3if-itaddress-forward)

[ITAddress::get_CurrentForwardInfo](https://learn.microsoft.com/windows/desktop/api/tapi3if/nf-tapi3if-itaddress-get_currentforwardinfo)

[ITForwardInformation](https://learn.microsoft.com/windows/desktop/api/tapi3if/nn-tapi3if-itforwardinformation)

[ITForwardInformation2::GetForwardType](https://learn.microsoft.com/windows/desktop/api/tapi3if/nf-tapi3if-itforwardinformation2-getforwardtype2)

[Terminal Object](https://learn.microsoft.com/windows/desktop/Tapi/terminal-object)