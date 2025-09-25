# ITForwardInformation2::GetForwardType2

## Description

The
**GetForwardType2** method gets the current forwarding mode, specified by caller address.

## Parameters

### `ForwardType` [in]

[Line forward type](https://learn.microsoft.com/windows/desktop/Tapi/lineforwardmode--constants) to be retrieved.

### `ppDestinationAddress` [out]

Pointer to the **BSTR** representation of the destination address.

### `pDestAddressType` [out]

[Address type](https://learn.microsoft.com/windows/desktop/Tapi/lineaddresstype--constants) of the destination.

### `ppCallerAddress` [out]

Pointer to the **BSTR** representation of the caller address.

### `pCallerAddressType` [out]

[Address type](https://learn.microsoft.com/windows/desktop/Tapi/lineaddresstype--constants) of the caller.

## Return value

This method can return one of these values.

| Return code | Description |
| --- | --- |
| **S_OK** | Method succeeded. |
| **E_INVALIDARG** | The *ForwardType*, *pDestAddressType*, or *pCallerAddressType* parameter is invalid. |
| **E_OUTOFMEMORY** | Insufficient memory exists to perform the operation. |
| **E_POINTER** | The *ppDestinationAddress*, *pDestAddressType*, *pCallerAddressType*, or *ppCallerAddress* parameter is not a valid pointer. |

## See also

[ITForwardInformation](https://learn.microsoft.com/windows/desktop/api/tapi3if/nn-tapi3if-itforwardinformation)

[ITForwardInformation2](https://learn.microsoft.com/windows/desktop/api/tapi3if/nn-tapi3if-itforwardinformation2)

[ITForwardInformation::GetForwardType](https://learn.microsoft.com/windows/desktop/api/tapi3if/nf-tapi3if-itforwardinformation-getforwardtype)