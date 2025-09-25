# ITForwardInformation::get_NumRingsNoAnswer

## Description

The
**get_NumRingsNoAnswer** method retrieves the number of rings after which a no answer condition is assumed.

## Parameters

### `plNumRings` [out]

Pointer to number of rings.

## Return value

This method can return one of these values.

| Return code | Description |
| --- | --- |
| **S_OK** | Method succeeded. |
| **E_OUTOFMEMORY** | Insufficient memory exists to perform the operation. |
| **E_POINTER** | The *plNumRings* parameter is not a valid pointer. |

## See also

[ITAddress::CreateForwardInfoObject](https://learn.microsoft.com/windows/desktop/api/tapi3if/nf-tapi3if-itaddress-createforwardinfoobject)

[ITAddress::Forward](https://learn.microsoft.com/windows/desktop/api/tapi3if/nf-tapi3if-itaddress-forward)

[ITAddress::get_CurrentForwardInfo](https://learn.microsoft.com/windows/desktop/api/tapi3if/nf-tapi3if-itaddress-get_currentforwardinfo)

[ITForwardInformation](https://learn.microsoft.com/windows/desktop/api/tapi3if/nn-tapi3if-itforwardinformation)

[Terminal Object](https://learn.microsoft.com/windows/desktop/Tapi/terminal-object)

[put_NumRingsNoAnswer](https://learn.microsoft.com/windows/desktop/api/tapi3if/nf-tapi3if-itforwardinformation-put_numringsnoanswer)