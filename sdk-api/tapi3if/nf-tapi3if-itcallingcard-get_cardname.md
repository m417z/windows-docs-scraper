# ITCallingCard::get_CardName

## Description

The
**get_CardName** method gets the friendly name for the calling card.

## Parameters

### `ppCardName` [out]

Pointer to **BSTR** containing a displayable name for the calling card.

## Return value

This method can return one of these values.

| Return code | Description |
| --- | --- |
| **S_OK** | Method succeeded. |
| **E_POINTER** | The *ppCardName* parameter is not a valid pointer. |
| **E_OUTOFMEMORY** | Insufficient memory exists to perform the operation. |

## Remarks

The application must use
[SysFreeString](https://learn.microsoft.com/previous-versions/windows/desktop/api/oleauto/nf-oleauto-sysfreestring) to free the memory allocated for the *ppCardName* parameter.

## See also

[ITCallingCard](https://learn.microsoft.com/windows/desktop/api/tapi3if/nn-tapi3if-itcallingcard)