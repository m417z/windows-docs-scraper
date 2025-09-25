# IAppxManifestProperties::GetBoolValue

## Description

Gets the value of the specified Boolean element in the properties section.

## Parameters

### `name` [in]

Type: **[LPCWSTR](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

The name of the Boolean element. Valid values include:

"Framework"

"ResourcePackage" for Windows 8.1 and later

### `value` [out, retval]

Type: **[BOOL](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)***

The value of the specified Boolean element.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

If a valid Boolean property with this name is not defined in the manifest, this method returns **E_INVALIDARG** and *value* is **FALSE**.

## See also

[IAppxManifestProperties](https://learn.microsoft.com/windows/desktop/api/appxpackaging/nn-appxpackaging-iappxmanifestproperties)