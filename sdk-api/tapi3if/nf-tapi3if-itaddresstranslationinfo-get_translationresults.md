# ITAddressTranslationInfo::get_TranslationResults

## Description

The
**get_TranslationResults** method gets the results of a translation operation.

## Parameters

### `plResults` [out]

Indicates the information derived from the translation process, which may assist the application in presenting user-interface elements. This value uses one of the
[LINETRANSLATERESULT_ Constants](https://learn.microsoft.com/windows/desktop/Tapi/linetranslateresult--constants).

## Return value

This method can return one of these values.

| Return code | Description |
| --- | --- |
| **S_OK** | Method succeeded. |
| **E_POINTER** | The *plResults* parameter is not a valid pointer. |
| **E_OUTOFMEMORY** | Insufficient memory exists to perform the operation. |

## Remarks

Corresponds to the **dwTranslateResults** member of TAPI 2's
[LINETRANSLATEOUTPUT](https://learn.microsoft.com/windows/desktop/api/tapi/ns-tapi-linetranslateoutput) structure.

## See also

[Address Object](https://learn.microsoft.com/windows/desktop/Tapi/address-object)

[ITAddressTranslationInfo](https://learn.microsoft.com/windows/desktop/api/tapi3if/nn-tapi3if-itaddresstranslationinfo)