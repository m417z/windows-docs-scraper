# IAppxManifestProperties::GetStringValue

## Description

Gets the value of the specified string element in the properties section.

## Parameters

### `name` [in]

Type: **[LPCWSTR](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

The name of the string element. Valid values include:

"Description"

"DisplayName"

"Logo"

"PublisherDisplayName"

### `value` [out, retval]

Type: **[LPWSTR](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)***

The value of the specified element.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

If a valid string property with this name is not defined in the manifest, this method returns **E_INVALIDARG** and *value* receives a null string.

The caller must free the memory allocated for *value* using the [CoTaskMemFree](https://learn.microsoft.com/windows/desktop/api/combaseapi/nf-combaseapi-cotaskmemfree) function.

#### Examples

For an example, see [Quickstart: Read app package manifest info](https://learn.microsoft.com/windows/desktop/appxpkg/how-to-query-package-identity-information).

## See also

[IAppxManifestProperties](https://learn.microsoft.com/windows/desktop/api/appxpackaging/nn-appxpackaging-iappxmanifestproperties)