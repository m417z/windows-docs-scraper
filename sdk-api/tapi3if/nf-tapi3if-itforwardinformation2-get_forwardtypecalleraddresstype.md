# ITForwardInformation2::get_ForwardTypeCallerAddressType

## Description

The
**get_ForwardTypeCallerAddressType** method gets the caller address type for a given forwarding type.

## Parameters

### `Forwardtype` [in]

[Line forward type](https://learn.microsoft.com/windows/desktop/Tapi/lineforwardmode--constants) to be retrieved.

### `pCallerAddressType` [out]

[Address type](https://learn.microsoft.com/windows/desktop/Tapi/lineaddresstype--constants) of the caller.

## Return value

This method can return one of these values.

| Value | Meaning |
| --- | --- |
| **S_OK** | Method succeeded. |
| **E_INVALIDARG** | The *Forwardtype* parameter is invalid. |
| **E_OUTOFMEMORY** | Insufficient memory exists to perform the operation. |
| **E_POINTER** | The *pCallerAddressType* parameter is not a valid pointer. |

## See also

[ITForwardInformation](https://learn.microsoft.com/windows/desktop/api/tapi3if/nn-tapi3if-itforwardinformation)

[ITForwardInformation2](https://learn.microsoft.com/windows/desktop/api/tapi3if/nn-tapi3if-itforwardinformation2)

[ITForwardInformation::GetForwardType](https://learn.microsoft.com/windows/desktop/api/tapi3if/nf-tapi3if-itforwardinformation-getforwardtype)