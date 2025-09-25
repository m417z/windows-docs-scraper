# ITAddress::CreateForwardInfoObject

## Description

The
**CreateForwardInfoObject** method creates the forwarding information object and returns an
[ITForwardInformation](https://learn.microsoft.com/windows/desktop/api/tapi3if/nn-tapi3if-itforwardinformation) interface pointer. This interface exposes methods that allow an application to control aspects of how a call is forwarded, such as whether internal calls will be handled differently than external calls.

## Parameters

### `ppForwardInfo` [out]

Pointer to
[ITForwardInformation](https://learn.microsoft.com/windows/desktop/api/tapi3if/nn-tapi3if-itforwardinformation) interface.

## Return value

This method can return one of these values.

| Value | Meaning |
| --- | --- |
| **S_OK** | Method succeeded. |
| **E_OUTOFMEMORY** | Insufficient memory exists to perform the operation. |
| **E_POINTER** | The *ppForwardInfo* parameter is not a valid pointer. |

## Remarks

The application must set information on a newly created
[ITForwardInformation](https://learn.microsoft.com/windows/desktop/api/tapi3if/nn-tapi3if-itforwardinformation) object before the object can be used.

TAPI calls the **AddRef** method on the
[ITForwardInformation](https://learn.microsoft.com/windows/desktop/api/tapi3if/nn-tapi3if-itforwardinformation) interface returned by **ITAddress::CreateForwardInfoObject**. The application must call **Release** on the
**ITForwardInformation** interface to free resources associated with it.

## See also

[Address Object](https://learn.microsoft.com/windows/desktop/Tapi/address-object)

[Forward](https://learn.microsoft.com/windows/desktop/api/tapi3if/nf-tapi3if-itaddress-forward)

[ITAddress](https://learn.microsoft.com/windows/desktop/api/tapi3if/nn-tapi3if-itaddress)

[ITForwardInformation](https://learn.microsoft.com/windows/desktop/api/tapi3if/nn-tapi3if-itforwardinformation)

[get_CurrentForwardInfo](https://learn.microsoft.com/windows/desktop/api/tapi3if/nf-tapi3if-itaddress-get_currentforwardinfo)