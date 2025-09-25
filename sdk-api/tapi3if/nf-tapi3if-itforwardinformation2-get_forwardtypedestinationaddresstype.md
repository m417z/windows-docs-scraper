# ITForwardInformation2::get_ForwardTypeDestinationAddressType

## Description

The
**get_ForwardTypeDestinationAddressType** method gets the destination address type for a given forwarding type.

## Parameters

### `ForwardType` [in]

[Line forward type](https://learn.microsoft.com/windows/desktop/Tapi/lineforwardmode--constants) to be retrieved.

### `pDestAddressType` [out]

[Address type](https://learn.microsoft.com/windows/desktop/Tapi/lineaddresstype--constants) of the destination.

## Return value

This method can return one of these values.

| Value | Meaning |
| --- | --- |
| **S_OK** | Method succeeded. |
| **E_INVALIDARG** | The *ForwardType* parameter is invalid. |
| **E_OUTOFMEMORY** | Insufficient memory exists to perform the operation. |
| **E_POINTER** | The *pDestAddressType* parameter is not a valid pointer. |

## See also

[ITForwardInformation](https://learn.microsoft.com/windows/desktop/api/tapi3if/nn-tapi3if-itforwardinformation)

[ITForwardInformation2](https://learn.microsoft.com/windows/desktop/api/tapi3if/nn-tapi3if-itforwardinformation2)

[ITForwardInformation::GetForwardType](https://learn.microsoft.com/windows/desktop/api/tapi3if/nf-tapi3if-itforwardinformation-getforwardtype)