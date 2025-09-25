# ICatInformation::GetCategoryDesc

## Description

Retrieves the localized description string for a specific category ID.

## Parameters

### `rcatid` [in]

The category identifier.

### `lcid` [in]

The locale.

### `pszDesc` [out]

A pointer to the string pointer for the description. This string must be released by the caller using the [CoTaskMemFree](https://learn.microsoft.com/windows/desktop/api/combaseapi/nf-combaseapi-cotaskmemfree) function.

## Return value

This method can return the standard return values E_INVALIDARG, E_OUTOFMEMORY, and S_OK, as well as the following values.

| Return code | Description |
| --- | --- |
| **CAT_E_CATIDNOEXIST** | The category ID *rcatid* is not registered. |
| **CAT_E_NODESCRIPTION** | There is no description string for *rcatid* with the specified locale. |

## See also

[ICatInformation](https://learn.microsoft.com/windows/desktop/api/comcat/nn-comcat-icatinformation)