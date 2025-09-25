# ITForwardInformation::SetForwardType

## Description

The
**SetForwardType** method sets the forwarding mode and destination by caller address.

## Parameters

### `ForwardType` [in]

[Line forward mode](https://learn.microsoft.com/windows/desktop/Tapi/lineforwardmode--constants).

### `pDestAddress` [in]

Pointer to **BSTR** representation of destination address for forwarding.

### `pCallerAddress` [in]

Pointer to **BSTR** representation of caller address.

## Return value

This method can return one of these values.

| Return code | Description |
| --- | --- |
| **S_OK** | Method succeeded. |
| **E_POINTER** | The *pDestAddress* or *pCallerAddress* parameter is not a valid pointer. |
| **E_INVALIDARG** | The *ForwardType* parameter is not valid. |
| **E_OUTOFMEMORY** | Insufficient memory exists to perform the operation. |

## Remarks

The application must use
[SysAllocString](https://learn.microsoft.com/previous-versions/windows/desktop/api/oleauto/nf-oleauto-sysallocstring) to allocate memory for the *pDestAddress* and *pCallerAddress* parameters. The application must use
[SysFreeString](https://learn.microsoft.com/previous-versions/windows/desktop/api/oleauto/nf-oleauto-sysfreestring) to free the memory when the variables are no longer needed.

## See also

[ITAddress::CreateForwardInfoObject](https://learn.microsoft.com/windows/desktop/api/tapi3if/nf-tapi3if-itaddress-createforwardinfoobject)

[ITAddress::Forward](https://learn.microsoft.com/windows/desktop/api/tapi3if/nf-tapi3if-itaddress-forward)

[ITAddress::get_CurrentForwardInfo](https://learn.microsoft.com/windows/desktop/api/tapi3if/nf-tapi3if-itaddress-get_currentforwardinfo)

[ITForwardInformation](https://learn.microsoft.com/windows/desktop/api/tapi3if/nn-tapi3if-itforwardinformation)

[Terminal Object](https://learn.microsoft.com/windows/desktop/Tapi/terminal-object)