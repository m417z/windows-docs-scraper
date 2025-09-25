# IAppxManifestPackageId::GetPackageFullName

## Description

Gets the package full name.

## Parameters

### `packageFullName` [out, retval]

Type: **[LPWSTR](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)***

The package full name.

## Return value

Type: **HRESULT**

If the method succeeds, it returns **S_OK**.

## Remarks

The package full name string is a case-insensitive string, which can be used to uniquely identify the package.

This string is a serialized form of the package ID, and it is suitable for naming objects such as files and directories.

The caller must free the memory allocated for *packageFullName* using the [CoTaskMemFree](https://learn.microsoft.com/windows/desktop/api/combaseapi/nf-combaseapi-cotaskmemfree) function.

#### Examples

For an example, see [Quickstart: Read app package manifest info](https://learn.microsoft.com/windows/desktop/appxpkg/how-to-query-package-identity-information).

## See also

[IAppxManifestPackageId](https://learn.microsoft.com/windows/desktop/api/appxpackaging/nn-appxpackaging-iappxmanifestpackageid)