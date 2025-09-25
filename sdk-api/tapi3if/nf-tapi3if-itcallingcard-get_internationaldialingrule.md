# ITCallingCard::get_InternationalDialingRule

## Description

The
**get_InternationalDialingRule** method gets the international dialing rules for this calling card.

## Parameters

### `ppRule` [out]

Pointer to **BSTR** representation of international dialing rules.

## Return value

This method can return one of these values.

| Return code | Description |
| --- | --- |
| **S_OK** | Method succeeded. |
| **E_INVALIDARG** | The *ppRule* parameter is not a valid pointer. |
| **E_POINTER** | The *ppRule* parameter is not a valid pointer. |
| **E_OUTOFMEMORY** | Insufficient memory exists to perform the operation. |

## Remarks

The application must use
[SysFreeString](https://learn.microsoft.com/previous-versions/windows/desktop/api/oleauto/nf-oleauto-sysfreestring) to free the memory allocated for the *ppRule* parameter.

## See also

[ITCallingCard](https://learn.microsoft.com/windows/desktop/api/tapi3if/nn-tapi3if-itcallingcard)