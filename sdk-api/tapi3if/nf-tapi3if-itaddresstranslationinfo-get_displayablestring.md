# ITAddressTranslationInfo::get_DisplayableString

## Description

The
**get_DisplayableString** method gets a string that contains a displayable version of the dialable number.

## Parameters

### `ppDisplayableString` [out]

Pointer to **BSTR** containing representation of displayable string.

## Return value

This method can return one of these values.

| Return code | Description |
| --- | --- |
| **S_OK** | Method succeeded. |
| **E_POINTER** | The *ppDisplayableString* parameter is not a valid pointer. |
| **E_OUTOFMEMORY** | Insufficient memory exists to perform the operation. |

## Remarks

The application must use
[SysFreeString](https://learn.microsoft.com/previous-versions/windows/desktop/api/oleauto/nf-oleauto-sysfreestring) to free the memory allocated for the *ppDisplayableString* parameter.

Corresponds to the **dwDisplayableStringSize** and **dwDisplayableStringOffset** members of TAPI 2's
[LINETRANSLATEOUTPUT](https://learn.microsoft.com/windows/desktop/api/tapi/ns-tapi-linetranslateoutput) structure.

## See also

[Address Object](https://learn.microsoft.com/windows/desktop/Tapi/address-object)

[ITAddressTranslationInfo](https://learn.microsoft.com/windows/desktop/api/tapi3if/nn-tapi3if-itaddresstranslationinfo)