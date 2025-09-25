# ITBasicCallControl::Unpark

## Description

The
**Unpark** method gets the call from park.

## Return value

This method can return one of these values.

| Value | Meaning |
| --- | --- |
| **S_OK** | Method succeeded. |
| **E_FAIL** | The park operation is not supported. |
| **TAPI_E_INVALCALLSTATE** | Call state must be CS_IDLE. |
| **TAPI_E_TIMEOUT** | The operation failed because the TAPI 3 DLL timed it out. The timeout interval is two minutes. |
| **E_OUTOFMEMORY** | Insufficient memory exists to perform the operation. |

## Remarks

To unpark a call,
[CreateCall](https://learn.microsoft.com/windows/desktop/api/tapi3if/nf-tapi3if-itaddress-createcall) must be called using as the destination address the current parked location of the call. See the example below.

#### Examples

``` syntax
// Note: the parameters used in this call are obtained from elsewhere in the code.

HRESULT hr = pAddress->CreateCall( bstrAddressToCall,
                           dwAddressType,
                           dwMediaTypes,
                           &pBasicCall
                           );
// If ( hr != S_OK ) process the error here.

// Select appropriate terminals for call, and then call:
pBasicCall->Unpark();
```

## See also

[Call Object](https://learn.microsoft.com/windows/desktop/Tapi/call-object)

[ITAddress::CreateCall](https://learn.microsoft.com/windows/desktop/api/tapi3if/nf-tapi3if-itaddress-createcall)

[ITBasicCallControl](https://learn.microsoft.com/windows/desktop/api/tapi3if/nn-tapi3if-itbasiccallcontrol)

[Park overview](https://learn.microsoft.com/windows/desktop/Tapi/park-ovr)

[ParkDirect](https://learn.microsoft.com/windows/desktop/api/tapi3if/nf-tapi3if-itbasiccallcontrol-parkdirect)

[ParkIndirect](https://learn.microsoft.com/windows/desktop/api/tapi3if/nf-tapi3if-itbasiccallcontrol-parkindirect)

[lineUnpark](https://learn.microsoft.com/windows/desktop/api/tapi/nf-tapi-lineunpark)