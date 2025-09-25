# IAppxManifestApplication::GetStringValue

## Description

Gets the string value of an element or attribute in the application metadata section of the manifest.

## Parameters

### `name` [in]

Type: **[LPCWSTR](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

The name of the element or attribute value to get from the application metadata. Supported names include:

* AppListEntry
* BackgroundColor
* DefaultSize
* Description
* DisplayName
* EntryPoint
* Executable
* ForegroundText
* ID
* LockScreenLogo
* LockScreenNotification
* Logo
* MinWidth
* ShortName
* SmallLogo
* Square150x150Logo
* Square30x30Logo
* Square310x310Logo
* Square44x44Logo
* Square70x70Logo
* Square71x71Logo
* StartPage
* Tall150x310Logo
* VisualGroup
* WideLogo
* Wide310x150Logo

Refer to the [schema](https://learn.microsoft.com/uwp/schemas/appxpackage/uapmanifestschema/schema-root) to determine where these values are being read from in the manifest.

### `value` [out, retval]

Type: **[LPWSTR](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)***

The value of the requested element or attribute.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

If the *name* parameter is not a supported name of an element or attribute in the manifest, this method returns **E_INVALIDARG**. If the *name* parameter is supported but the element or attribute is not found in the manifest, this method returns **S_OK** and the return value of the *value* parameter is **NULL**.

The caller must free the memory allocated for *value* using the [CoTaskMemFree](https://learn.microsoft.com/windows/desktop/api/combaseapi/nf-combaseapi-cotaskmemfree) function.

## Examples

For an example, see [Quickstart: Read app package manifest info](https://learn.microsoft.com/windows/desktop/appxpkg/how-to-query-package-identity-information).

## See also

[IAppxManifestApplication](https://learn.microsoft.com/windows/desktop/api/appxpackaging/nn-appxpackaging-iappxmanifestapplication)