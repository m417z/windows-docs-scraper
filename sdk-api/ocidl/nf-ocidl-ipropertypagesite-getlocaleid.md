# IPropertyPageSite::GetLocaleID

## Description

Retrieves the locale identifier (an LCID) that a property page can use to adjust its locale-specific settings.

## Parameters

### `pLocaleID` [out]

A pointer to a variable that receives the locale identifier. See [Language Identifier Constants and Strings](https://learn.microsoft.com/windows/desktop/Intl/language-identifier-constants-and-strings).

## Return value

This method can return the following values.

| Return code | Description |
| --- | --- |
| **S_OK** | The method completed successfully. |
| **E_POINTER** | The address in *pLocaleID* is not valid. For example, it may be **NULL**. |

## See also

[IPropertyPageSite](https://learn.microsoft.com/windows/desktop/api/ocidl/nn-ocidl-ipropertypagesite)

[OCPFIPARAMS](https://learn.microsoft.com/windows/desktop/api/olectl/ns-olectl-ocpfiparams)

[PROPPAGEINFO](https://learn.microsoft.com/windows/desktop/api/ocidl/ns-ocidl-proppageinfo)