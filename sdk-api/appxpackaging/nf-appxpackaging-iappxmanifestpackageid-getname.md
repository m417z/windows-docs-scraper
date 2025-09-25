# IAppxManifestPackageId::GetName

## Description

Gets the name of the package as defined in the manifest.

## Parameters

### `name` [out, retval]

Type: **[LPWSTR](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)***

The name of the package.

## Return value

Type: **HRESULT**

If the method succeeds, it returns **S_OK**.

## Remarks

Package name information is specified using the **Name** attribute of the [Identity](https://learn.microsoft.com/uwp/schemas/appxpackage/appxmanifestschema/element-identity) element in the package manifest.

The package name is not intended to be displayed to end users. Rather, the system uses it to uniquely identify the package.

The caller must free the memory allocated for *name* using the [CoTaskMemFree](https://learn.microsoft.com/windows/desktop/api/combaseapi/nf-combaseapi-cotaskmemfree) function.

#### Examples

For an example, see [Quickstart: Read app package manifest info](https://learn.microsoft.com/windows/desktop/appxpkg/how-to-query-package-identity-information).

## See also

[IAppxManifestPackageId](https://learn.microsoft.com/windows/desktop/api/appxpackaging/nn-appxpackaging-iappxmanifestpackageid)