# ITForwardInformation2::SetForwardType2

## Description

The
**SetForwardType2** method sets the current forwarding mode, specified by caller address.

## Parameters

### `ForwardType` [in]

[Line forward type](https://learn.microsoft.com/windows/desktop/Tapi/lineforwardmode--constants) to be set.

### `pDestAddress` [in]

Pointer to the **BSTR** representation of the destination address.

### `DestAddressType` [in]

[Address type](https://learn.microsoft.com/windows/desktop/Tapi/lineaddresstype--constants) of destination.

### `pCallerAddress` [in]

Pointer to the **BSTR** representation of the caller address.

### `CallerAddressType` [in]

[Address type](https://learn.microsoft.com/windows/desktop/Tapi/lineaddresstype--constants) of caller.

## Return value

This method can return one of these values.

| Return code | Description |
| --- | --- |
| **S_OK** | Method succeeded. |
| **E_INVALIDARG** | The *ForwardType*, *DestAddressType*, or *CallerAddressType* is invalid. |
| **E_OUTOFMEMORY** | Insufficient memory exists to perform the operation. |
| **E_POINTER** | The *pDestAddress* or *pCallerAddress* parameter is not a valid pointer. |

## See also

[ITForwardInformation](https://learn.microsoft.com/windows/desktop/api/tapi3if/nn-tapi3if-itforwardinformation)

[ITForwardInformation2](https://learn.microsoft.com/windows/desktop/api/tapi3if/nn-tapi3if-itforwardinformation2)

[ITForwardInformation::SetForwardType](https://learn.microsoft.com/windows/desktop/api/tapi3if/nf-tapi3if-itforwardinformation-setforwardtype)