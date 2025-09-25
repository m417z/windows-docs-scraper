# ITCallingCard::get_PermanentCardID

## Description

The
**get_PermanentCardID** method gets the permanent identifier that identifies the card.

## Parameters

### `plCardID` [out]

Pointer to calling card identifier.

## Return value

This method can return one of these values.

| Return code | Description |
| --- | --- |
| **S_OK** | Method succeeded. |
| **E_INVALIDARG** | The *plCardID* parameter is not valid. |
| **E_POINTER** | The *plCardID* parameter is not a valid pointer. |
| **E_OUTOFMEMORY** | Insufficient memory exists to perform the operation. |

## See also

[ITCallingCard](https://learn.microsoft.com/windows/desktop/api/tapi3if/nn-tapi3if-itcallingcard)