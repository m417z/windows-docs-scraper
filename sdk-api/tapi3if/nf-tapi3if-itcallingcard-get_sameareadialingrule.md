# ITCallingCard::get_SameAreaDialingRule

## Description

The
**get_SameAreaDialingRule** method gets the dialing rules for calls within the same area code.

## Parameters

### `ppRule` [out]

Pointer to **BSTR** representation of local area dialing rules.

## Return value

This method can return one of these values.

| Return code | Description |
| --- | --- |
| **S_OK** | Method succeeded. |
| **E_POINTER** | The *ppRule* parameter is not a valid pointer. |
| **E_OUTOFMEMORY** | Insufficient memory exists to perform the operation. |

## Remarks

The application must use
[SysFreeString](https://learn.microsoft.com/previous-versions/windows/desktop/api/oleauto/nf-oleauto-sysfreestring) to free the memory allocated for the *ppRule* parameter.

## See also

[ITCallingCard](https://learn.microsoft.com/windows/desktop/api/tapi3if/nn-tapi3if-itcallingcard)